#ifndef REGULATOR_H
#define REGULATOR_H

#include "NoiseGenerator.h"
#include <vector>
#include <string>


class Regulator
{
public:
    Regulator();
    virtual ~Regulator();
    virtual std::string name() const;
    virtual unsigned int parameterCount() const;
    virtual void setParameter(int index, double value);
    virtual void setNoise(NoiseGenerator* noise);
    virtual void setSeed(int seed = -1);
    virtual double operator()(const std::vector<double>& values) const;
    
protected:
    NoiseGenerator* noise;
    virtual double addNoise(double value) const;
};

class ConstantRegulator : public Regulator
{
public:
    double constant;
    
    std::string name() const;
    unsigned int parameterCount() const;
    void setParameter(int index, double value);
    double operator()(const std::vector<double>& values) const;
};

class LinearRegulator : public Regulator
{
public:
    double intercept, slope;
    
    std::string name() const;
    unsigned int parameterCount() const;
    void setParameter(int index, double value);
    double operator()(const std::vector<double>& values) const;
};

class Hill : public Regulator
{
public:
    double min, max, K, n;
    
    unsigned int parameterCount() const;
    void setParameter(int index, double value) override;
};

class HillA : public Hill
{
public:
    std::string name() const;
    virtual double operator()(const std::vector<double>& values) const;
};

class HillR : public Hill
{
public:
    std::string name() const;
    virtual double operator()(const std::vector<double>& values) const;
};

class Hill2 : public Regulator
{
public:
    double min, max, K1, n1, K2, n2;
    
    unsigned int parameterCount() const;
    void setParameter(int index, double value);
};

class HillAR : public Hill2
{
public:
    std::string name() const;
    double operator()(const std::vector<double>& values) const;
};

class HillRR : public Hill2
{
public:
    std::string name() const;
    double operator()(const std::vector<double>& values) const;
};

class Hill2c : public Hill2
{
public:
    double correction;
    
    unsigned int parameterCount() const;
    void setParameter(int index, double value);
};

class HillARc : public Hill2c
{
public:
    std::string name() const;
    double operator()(const std::vector<double>& values) const;
};

#endif

