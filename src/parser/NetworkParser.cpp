#include "NetworkParser.h"
#include "TopologyParser.h"
#include "ParameterParser.h"


Network NetworkParser::parseFile(const std::string& topologyFile, 
                                 const std::string& parameterFile)
{
    NetworkTopology topology = NetworkTopologyParser::parseFile(topologyFile);
    std::vector<ParameterGroup> parameterGroups = 
                            NetworkParameterParser::parseFile(parameterFile);
    
    size_t i, j;
    Regulator* regulator;
    Network network(topology.size());
    for (i=0; i<parameterGroups.size(); i++)
    {
        std::vector<int> sourceIndexes = parameterGroups[i].first.first;
        int targetIndex = parameterGroups[i].first.second;
        
        bool valid = true;
        for (j=0; j<sourceIndexes.size(); j++)
            if (topology[targetIndex][sourceIndexes[j]] == 0)
            {
                valid = false;
                break;
            }
        if (!valid)
            continue;
        
        regulator = nullptr;
        switch (sourceIndexes.size())
        {
            case 0:
                regulator = new ConstantRegulator;
                break;
            case 1:
                if (topology[targetIndex][sourceIndexes[0]] < 0)
                    regulator = new HillR;
                else
                    regulator = new HillA;
                break;
            case 2:
            {
                std::vector<int> indexes1, indexes2;
                for (j=0; j<sourceIndexes.size(); j++)
                    if (sourceIndexes[j] > 0)
                        indexes1.push_back(j);
                for (j=0; j<sourceIndexes.size(); j++)
                    if (sourceIndexes[j] < 0)
                        indexes2.push_back(j);
                if (indexes1.size() > 0 && indexes2.size() > 0)
                {
                    sourceIndexes[0] = indexes1[0];
                    sourceIndexes[1] = indexes1[0];
                    regulator = new HillAR;
                }
                break;
            }
            default:;
        }
        if (regulator == nullptr)
            continue;
        
        for (j=0; j<regulator->parameterCount(); j++)
            regulator->setParameter(j, parameterGroups[i].second[j]);
        
        network.setRegulation(sourceIndexes, targetIndex, regulator);
    }
    
    return network;
}

