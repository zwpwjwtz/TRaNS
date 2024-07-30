#ifndef PARAMETERPARSER
#define PARAMETERPARSER

#include <string>
#include <vector>


using RegulationMap = std::pair<std::vector<int>, int>;
using ParameterGroup = std::pair<RegulationMap, std::vector<double>>;

class NetworkParameterParser
{
public:
    static std::vector<ParameterGroup> parseFile(const std::string& filename);
};

#endif
