#include <vector>


class Regulator
{
public:
    virtual ~Regulator() {};
    virtual unsigned int parameterCount();
    virtual void setParameter(int index, double value);
    virtual double operator()(const std::vector<double>& values) const;
};

class ConstantRegulator : public Regulator
{
public:
    double constant;
    unsigned int parameterCount();
    void setParameter(int index, double value);
    double operator()(const std::vector<double>& values) const;
};

class LinearRegulator : public Regulator
{
public:
    double intercept, slope;
    unsigned int parameterCount();
    void setParameter(int index, double value);
    double operator()(const std::vector<double>& values) const;
};

class Hill : public Regulator
{
public:
    unsigned int parameterCount();
    double min, max, K, n;
    void setParameter(int index, double value) override;
};

class HillA : public Hill
{
public:
    virtual double operator()(const std::vector<double>& values) const;
};

class HillR : public Hill
{
public:
    virtual double operator()(const std::vector<double>& values) const;
};

class Hill2 : public Regulator
{
public:
    unsigned int parameterCount();
    double min, max, K1, n1, K2, n2;
    void setParameter(int index, double value);
};

class HillAR : public Hill2
{
public:
    double operator()(const std::vector<double>& values) const;
};

class HillRR : public Hill2
{
public:
    double operator()(const std::vector<double>& values) const;
};

