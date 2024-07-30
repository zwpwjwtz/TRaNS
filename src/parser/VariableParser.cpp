#include "VariableParser.h"
#include <fstream>


std::vector<double> VariableParser::parseFile(const std::string& filename)
{
    std::ifstream file;
    std::string buffer;
    std::vector<double> values;
    file.open(filename);
    if (!file.is_open())
        return values;
    while (std::getline(file, buffer))
    {
        if (buffer.size() == 0)
            continue;
        values.push_back(std::stod(buffer));
    }
    return values;
}

