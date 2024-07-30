#include "TopologyParser.h"
#include <fstream>
#include <sstream>


NetworkTopology NetworkTopologyParser::parseFile(const std::string& filename)
{
    int nodeCount;
    std::ifstream file;
    std::string buffer, buffer2;
    std::stringstream bufferStream;
    std::vector<int> tempTopology; 
    NetworkTopology topology;
    
    file.open(filename);
    if (!file.is_open())
        return topology;
    std::getline(file, buffer);
    nodeCount = std::stoi(buffer);
    if (nodeCount > 0)
    {
        while (std::getline(file, buffer))
        {
            if (buffer.size() == 0)
                continue;
            
            bufferStream.clear();
            bufferStream.str(buffer);
            tempTopology.clear();
            while (std::getline(bufferStream, buffer2, ','))
                tempTopology.push_back(std::stoi(buffer2));
            
            if (tempTopology.size() > 0)
                topology.push_back(tempTopology);
        }
    }
    file.close();
    
    return topology;
}

