#ifndef TOPOLOGYPARSER
#define TOPOLOGYPARSER

#include <string>
#include <vector>


using NetworkTopology = std::vector<std::vector<int>>;

class NetworkTopologyParser
{
public:
    static NetworkTopology parseFile(const std::string& filename);
};

#endif
