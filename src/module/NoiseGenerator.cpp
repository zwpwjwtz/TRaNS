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

GaussianNoiseGenerator::GaussianNoiseGenerator(double stdev)
{
    distribution = new std::normal_distribution<double>(0, stdev);
}

GaussianNoiseGenerator::~GaussianNoiseGenerator()
{
    delete distribution;
}

double GaussianNoiseGenerator::addNoise(double value)
{
    return value + std::max(value * (*distribution)(randomGenerator), 
                            minNoise);
}

void GaussianNoiseGenerator::setMinNoise(double minNoise)
{
    this->minNoise = minNoise >= 0 ? minNoise : 0;
}

void GaussianNoiseGenerator::setRelativeNoise(double relativeNoise)
{
    this->relativeNoise = relativeNoise;
    delete distribution;
    distribution = new std::normal_distribution<double>(0, relativeNoise);
}

void GaussianNoiseGenerator::setSeed(int seed)
{
    this->NoiseGenerator::setSeed(seed);
    distribution->reset();
}

