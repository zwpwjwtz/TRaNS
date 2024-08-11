#include "RegulatorFactory.h"
#include "name.h"


int RegulatorFactory::countParameter(const std::string& name)
{
    if (name == TRANS_NAME_REGULATOR_CONSTANT)
        return 1;
    if (name == TRANS_NAME_REGULATOR_LINEAR)
        return 2;
    if (name == TRANS_NAME_REGULATOR_HILLA)
        return 4;
    if (name == TRANS_NAME_REGULATOR_HILLR)
        return 4;
    if (name == TRANS_NAME_REGULATOR_HILLAR)
        return 6;
    if (name == TRANS_NAME_REGULATOR_HILLRR)
        return 6;
    if (name == TRANS_NAME_REGULATOR_HILLARC)
        return 7;
    return 0;
}

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
    if (name == TRANS_NAME_REGULATOR_HILLARC)
        return new HillARc;
    return nullptr;
}

