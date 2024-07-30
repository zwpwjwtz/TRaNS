#ifndef NETWORKPARSER
#define NETWORKPARSER

#include "../module/Network.h"
#include <string>


class NetworkParser
{
public:
    static Network parseFile(const std::string& topologyFile, 
                             const std::string& parameterFile);
};

#endif
