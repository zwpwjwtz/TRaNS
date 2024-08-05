#include "NetworkParser.h"
#include "TopologyParser.h"
#include "ParameterParser.h"
#include "../module/constant.h"


Network NetworkParser::parseFile(const std::string& topologyFile, 
                                 const std::string& parameterFile)
{
    NetworkTopology topology = NetworkTopologyParser::parseFile(topologyFile);
    std::vector<ParameterGroup> parameterGroups = 
                            NetworkParameterParser::parseFile(parameterFile);
    
    size_t i, j;
    bool valid;
    int targetIndex;
    std::vector<int> sourceIndexes;
    Regulator* regulator;
    Network network(topology.size());
    for (i=0; i<parameterGroups.size(); i++)
    {
        sourceIndexes = parameterGroups[i].first.first;
        targetIndex = parameterGroups[i].first.second;
        
        valid = true;
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
                if (topology[targetIndex][sourceIndexes[0]] == 
                    TRANS_NETWORK_REGULATION_LINEAR)
                    regulator = new LinearRegulator;
                else if (topology[targetIndex][sourceIndexes[0]] < 0)
                    regulator = new HillR;
                else
                    regulator = new HillA;
                break;
            case 2:
            {
                std::vector<int> indexes1, indexes2;
                for (j=0; j<sourceIndexes.size(); j++)
                    if (topology[targetIndex][sourceIndexes[j]] > 0)
                        indexes1.push_back(sourceIndexes[j]);
                for (j=0; j<sourceIndexes.size(); j++)
                    if (topology[targetIndex][sourceIndexes[j]] < 0)
                        indexes2.push_back(sourceIndexes[j]);
                if (indexes1.size() > 0 && indexes2.size() > 0)
                {
                    sourceIndexes[0] = indexes1[0];
                    sourceIndexes[1] = indexes2[0];
                    regulator = new HillAR;
                }
                else if (indexes2.size() == 2)
                {
                    sourceIndexes[0] = indexes1[0];
                    sourceIndexes[1] = indexes1[1];
                    regulator = new HillRR;
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

