#include "RegulatorFactory.h"
#include "name.h"


Regulator* RegulatorFactory::createFromName(const std::string& name)
{
    if (name == TRANS_NAME_REGULATOR_CONSTANT)
        return new ConstantRegulator;
    if (name == TRANS_NAME_REGULATOR_LINEAR)
        return new LinearRegulator;
    if (name == TRANS_NAME_REGULATOR_HILLA)
        return new HillA;
    if (name == TRANS_NAME_REGULATOR_HILLR)
        return new HillR;
    if (name == TRANS_NAME_REGULATOR_HILLAR)
        return new HillAR;
    if (name == TRANS_NAME_REGULATOR_HILLRR)
        return new HillRR;
    return nullptr;
}

