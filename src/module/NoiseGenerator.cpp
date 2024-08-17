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
                                               double relativeNoise)
{
    this->minNoise = minNoise;
    this->relativeNoise = relativeNoise;
}

double GaussianNoiseGenerator::addNoise(double value)
{
    double sigma = std::abs(value * relativeNoise);
    if (sigma < minNoise)
        sigma = minNoise;
    return value + distribution(randomGenerator) * sigma;
}

void GaussianNoiseGenerator::setMinNoise(double minNoise)
{
    if (minNoise < 0)
        minNoise = 0;
    this->minNoise = minNoise;
}

void GaussianNoiseGenerator::setRelativeNoise(double relativeNoise)
{
    this->relativeNoise = relativeNoise;
}

void GaussianNoiseGenerator::setSeed(int seed)
{
    this->NoiseGenerator::setSeed(seed);
    distribution.reset();
}

