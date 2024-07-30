#ifndef MAINARGUMENTPARSER
#define MAINARGUMENTPARSER

#include <string>


struct MainArgument
{
    std::string topologyFilename;
    std::string parameterFilename;
    std::string initialFilename;
    std::string timeFilename;
    std::string outputFilename;
};

class MainArgumentParser
{
public:
    static MainArgument parse(int argc, char* argv[]);
};

#endif
