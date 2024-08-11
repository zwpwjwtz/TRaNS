#ifndef REGULATORFACTORY_H
#define REGULATORFACTORY_H

#include "Regulator.h"
#include <string>


class RegulatorFactory {
public:
    static int countParameter(const std::string& name);
    static Regulator* createFromName(const std::string& name);
};

#endif
