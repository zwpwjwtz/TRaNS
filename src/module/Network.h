#include "Regulator.h"


using NetworkRegulation = std::pair<std::vector<int>, const Regulator*>;

class Network
{
public:
    const unsigned int nodeCount;
    std::vector<std::vector<NetworkRegulation>> regulations;
    
    Network(unsigned int nodeCount);
    ~Network();
    void setRegulation(const std::vector<int>& sourceIndexes, int target, 
                       const Regulator* regulator);
    std::vector<double> evolve(const std::vector<double>& values, 
                               double time) const;
    void dynamics(const std::vector<double>& values, 
                  std::vector<double>& results) const;
};

