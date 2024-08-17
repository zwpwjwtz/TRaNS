#ifndef NOISEGENERATOR_H
#define NOISEGENERATOR_H

#include <random>


class NoiseGenerator
{
public:
    NoiseGenerator();
    virtual ~NoiseGenerator() {};
    virtual double addNoise(double value);
    virtual void setSeed(int seed = -1);
    
protected:
    std::mt19937 randomGenerator;
};

class GaussianNoiseGenerator : public NoiseGenerator
{
public:
    double minNoise, relativeNoise;
    
    GaussianNoiseGenerator(double minNoise = 0, double relativeNoise = 0);
    double addNoise(double value);
    void setMinNoise(double minNoise);
    void setRelativeNoise(double relativeNoise);
    void setSeed(int seed = -1);

private:
    std::normal_distribution<double> distribution;
};

#endif
