#include "Regulator.h"
#include "name.h"
#include <cmath>


std::string Regulator::name() const
{
    return TRANS_NAME_REGULATOR;
}

unsigned int Regulator::parameterCount() const
{
    return 0;
}

void Regulator::setParameter(int index, double value)
{}

double Regulator::operator()(const std::vector<double>& values) const
{
    return 0.0;
}

std::string ConstantRegulator::name() const
{
    return TRANS_NAME_REGULATOR_CONSTANT;
}

unsigned int ConstantRegulator::parameterCount() const
{
    return 1;
}

void ConstantRegulator::setParameter(int index, double value)
{
    if (index == 0)
        constant = value;
}

double ConstantRegulator::operator()(const std::vector<double>& values) const
{
    return constant;
}

std::string LinearRegulator::name() const
{
    return TRANS_NAME_REGULATOR_LINEAR;
}

unsigned int LinearRegulator::parameterCount() const
{
    return 2;
}

void LinearRegulator::setParameter(int index, double value)
{
    if (index == 0)
        intercept = value;
    else if (index == 1)
        slope = value;
}

double LinearRegulator::operator()(const std::vector<double>& values) const
{
    return intercept + values[0] * slope;
}

unsigned int Hill::parameterCount() const
{
    return 4;
}

void Hill::setParameter(int index, double value)
{
    switch (index)
    {
        case 0:
            min = value;
            break;
        case 1:
            max = value;
            break;
        case 2:
            K = value;
            break;
        case 3:
            n = value;
        default:;
    }
}

unsigned int Hill2::parameterCount() const
{
    return 6;
}

void Hill2::setParameter(int index, double value)
{
    switch (index)
    {
        case 0:
            min = value;
            break;
        case 1:
            max = value;
            break;
        case 2:
            K1 = value;
            break;
        case 3:
            n1 = value;
            break;
        case 4:
            K2 = value;
            break;
        case 5:
            n2 = value;
        default:;
    }
}

std::string HillA::name() const
{
    return TRANS_NAME_REGULATOR_HILLA;
}

double HillA::operator()(const std::vector<double>& values) const
{
    if (values[0] > 0)
        return min + max / (1.0 + std::pow(K / values[0], n));
    else
        return min;
}

std::string HillR::name() const
{
    return TRANS_NAME_REGULATOR_HILLR;
}

double HillR::operator()(const std::vector<double>& values) const
{
    return min + max / (1.0 + std::pow(values[0] / K, n));
}

std::string HillAR::name() const
{
    return TRANS_NAME_REGULATOR_HILLAR;
}

double HillAR::operator()(const std::vector<double>& values) const
{
    double A = values[0] > 0 ? std::pow(values[0] / K1, n1) : 0;
    double R = values[1] > 0 ? std::pow(values[1] / K2, n2) : 0;
    return min + max * A / (1.0 + A + R);
}

std::string HillRR::name() const
{
    return TRANS_NAME_REGULATOR_HILLRR;
}

double HillRR::operator()(const std::vector<double>& values) const
{
    double R1 = values[0] > 0 ? std::pow(values[0] / K1, n1) : 0;
    double R2 = values[1] > 0 ? std::pow(values[1] / K2, n2) : 0;
    return min + max / (1.0 + R1 + R2);
}

