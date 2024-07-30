#ifndef VARIABLEPARSER_H
#define VARIABLEPARSER_H

#include <string>
#include <vector>


class VariableParser {
public:
    static std::vector<double> parseFile(const std::string& filename); 
};

#endif
