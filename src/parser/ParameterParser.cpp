#include "ParameterParser.h"
#include <fstream>
#include <sstream>


std::vector<ParameterGroup> 
NetworkParameterParser::parseFile(const std::string& filename)
{
    int targetIndex;
    std::ifstream file;
    std::string buffer, buffer2, buffer3;
    std::istringstream bufferStream, bufferStream2;
    std::vector<int> sourceIndexes;
    std::vector<double> tempParameters; 
    std::vector<ParameterGroup> parameterGroups;
    
    file.open(filename);
    if (!file.is_open())
        return parameterGroups;
    while (std::getline(file, buffer))
    {
        if (buffer.size() == 0)
            continue;
        
        // Parse the index of target node
        bufferStream.clear();
        bufferStream.str(buffer);
        std::getline(bufferStream, buffer2, ';');
        if (buffer2.size() == 0)
            continue;
        targetIndex = std::stoi(buffer2);
        
        // Parse the indexes of source nodes
        sourceIndexes.clear();
        std::getline(bufferStream, buffer2, ';');
        if (buffer2.size() > 0)
        {
            bufferStream2.clear();
            bufferStream2.str(buffer2);
            while (std::getline(bufferStream2, buffer3, ','))
                sourceIndexes.push_back(std::stoi(buffer3));
        }
        
        // Parse the parameters
        std::getline(bufferStream, buffer2);
        if (buffer2.size() == 0)
            continue;
        bufferStream2.clear();
        bufferStream2.str(buffer2);
        tempParameters.clear();
        while (std::getline(bufferStream2, buffer3, ','))
            tempParameters.push_back(std::stod(buffer3));
        
        parameterGroups.push_back(
            {RegulationMap(sourceIndexes, targetIndex), tempParameters});
    }
    file.close();
    
    return parameterGroups;
}

