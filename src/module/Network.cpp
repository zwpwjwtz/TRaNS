#include "Network.h"
#include "constant.h"


Network::Network(unsigned int nodeCount) : 
    nodeCount(nodeCount)
{
    for (unsigned int i=0; i<nodeCount; i++)
        regulations.push_back(std::vector<NetworkRegulation>());
}

Network::~Network()
{
    for (size_t i=0; i<regulations.size(); i++)
    {
        for (size_t j=0; j<regulations[i].size(); j++)
            delete regulations[i][j].second;
    }
}

void Network::setRegulation(const std::vector<int>& sourceIndexes, 
                            int targetIndex, const Regulator* regulator)
{
    regulations[targetIndex].push_back({sourceIndexes, regulator});
}

void Network::removeRegulation(const std::vector<int>& sourceIndexes, 
                               int targetIndex)
{
    if (size_t(targetIndex) < regulations.size())
    {
        for (auto i=regulations[targetIndex].begin(); 
             i!=regulations[targetIndex].end(); i++)
        {
            if (i->first == sourceIndexes)
            {
                delete i->second;
                regulations[targetIndex].erase(i);
                break;
            }
        }
    }
}

std::vector<double> Network::evolve(const std::vector<double>& values, 
                                    double time) const
{
    size_t count = values.size();
    std::vector<double> rates(count);
    std::vector<double> results(values);
    
    size_t i;
    double currentTime = 0;
    double maxRate;
    while (currentTime < time)
    {
        dynamics(results, rates);
        maxRate = 10.0;
        for (i=0; i<count; i++)
        {
            if (rates[i] > maxRate)
                maxRate = rates[i];
        }
        for (i=0; i<count; i++)
            results[i] = std::max(results[i] + rates[i] / maxRate, 0.0);
        currentTime += 1 / maxRate;
    }
    return results;
}

std::vector<std::vector<double>> 
Network::evolveMultiple(const std::vector<double>& values, double time, 
                        int trajectoryCount) const
{
    int nodeCount = values.size();
    std::vector<double> rates(nodeCount);
    std::vector<std::vector<double>> results(trajectoryCount, values);
    
    int i, j, k = 0;
    double maxRate;
    std::vector<double> currentTimes(trajectoryCount, 0.0);
    while (k < trajectoryCount)
    {
        for (i=0; i<trajectoryCount; i++)
        {
            if (currentTimes[i] >= time)
                continue;
            
            dynamics(results[i], rates);
            maxRate = 10.0;
            for (j=0; j<nodeCount; j++)
            {
                if (rates[j] > maxRate)
                    maxRate = rates[j];
            }
            for (j=0; j<nodeCount; j++)
                results[i][j] = std::max(results[i][j] + rates[j] / maxRate, 
                                         0.0);
            currentTimes[i] += 1 / maxRate;
            if (currentTimes[i] >= time)
                k++;
        }
    }
    return results;
}

void Network::dynamics(const std::vector<double>& values, 
                       std::vector<double>& results) const
{
    std::vector<double> inputs(TRANS_REGULATOR_MAX_INPUT);
    for (size_t i=0; i<results.size(); i++)
    {
        results[i] = -values[i];
        for (auto j=regulations[i].cbegin(); j!=regulations[i].cend(); j++)
        {
            for (size_t k=0; k<j->first.size(); k++)
                inputs[k] = values[j->first[k]];
            results[i] += (*j->second)(inputs);
        }
    }
}

