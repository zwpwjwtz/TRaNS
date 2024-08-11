#include "NoiseGenerator.h"


NoiseGenerator::NoiseGenerator()
{
    randomGenerator.seed(std::random_device()());
}

double NoiseGenerator::addNoise(double value)
{
    return value;
}

void NoiseGenerator::setSeed(int seed)
{
    randomGenerator.seed(seed == -1 ? std::random_device()() : seed);
}

GaussianNoiseGenerator::GaussianNoiseGenerator(double minNoise, 
                                               double relativeNoise) : 
    distribution1(0, minNoise), distribution2(0, relativeNoise)
{
    this->minNoise = minNoise;
    this->relativeNoise = relativeNoise;
}

double GaussianNoiseGenerator::addNoise(double value)
{
    if (value * relativeNoise <= minNoise)
        return value + distribution1(randomGenerator);
    return value * (1.0 + distribution2(randomGenerator));
}

void GaussianNoiseGenerator::setMinNoise(double minNoise)
{
    if (minNoise < 0)
        minNoise = 0;
    this->minNoise = minNoise;
    distribution1 = std::normal_distribution<double>(0, minNoise);
}

void GaussianNoiseGenerator::setRelativeNoise(double relativeNoise)
{
    this->relativeNoise = relativeNoise;
    distribution2 = std::normal_distribution<double>(0, relativeNoise);
}

void GaussianNoiseGenerator::setSeed(int seed)
{
    this->NoiseGenerator::setSeed(seed);
    distribution1.reset();
    distribution2.reset();
}

