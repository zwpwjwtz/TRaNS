#include "parser/MainArgumentParser.h"
#include "parser/NetworkParser.h"
#include "parser/VariableParser.h"
#include <iostream>
#include <fstream>


int main(int argc, char* argv[])
{
    MainArgument arguments = MainArgumentParser::parse(argc, argv);
    
    Network network = NetworkParser::parseFile(arguments.topologyFilename, 
                                               arguments.parameterFilename);
    if (network.nodeCount == 0)
    {
        std::cout << "No node in the network." << std::endl;
        return 0;
    }
    
    size_t i;
    std::vector<double> initialValues = 
                        VariableParser::parseFile(arguments.initialFilename);
    for (i=initialValues.size(); i<network.nodeCount; i++)
    {
        std::cout << "Missing initial value for node " << i 
                  << "; assuming 0." << std::endl;
        initialValues.push_back(0);
    }
    
    std::vector<double> times = 
                        VariableParser::parseFile(arguments.timeFilename);
    if (times.size() == 0)
    {
        std::cout << "No time step specified." << std::endl;
        return 0;
    }
    
    std::cout << "Simulate the network with " << times.size() 
              << " time steps" << std::endl;
    
    std::vector<double> values = initialValues;
    std::vector<std::vector<double>> results;
    double lastTime = 0;
    for (i=0; i<times.size(); i++)
    {
        values = network.evolve(values, times[i] - lastTime);
        results.push_back(values);
        lastTime = times[i];
    }
    
    std::cout << "Simulation completed with " << results.size() 
              << " results." << std::endl;
    
    size_t j;
    std::ofstream file;
    file.open(arguments.outputFilename);
    if (!file.is_open())
    {
        arguments.outputFilename = "output.txt";
        std::cout << "Invalid output filename provided. "
                     "Redirect simulation results to " 
                  << arguments.outputFilename << std::endl;
        file.open(arguments.outputFilename);
    }
    for (i=0; i<results.size(); i++)
    {
        for (j=0; j<results[j].size(); j++)
        {
            if (j > 0)
                file << ',' << results[i][j];
            else
                file << results[i][j];
        }
        file << std::endl;
    }
    
    return 0;
}

