#include "PoissonRandomGenerator.h"
#include <ctime>

PoissonRandomGenerator::PoissonRandomGenerator(double mean):
    _mean(mean),
    _lambda(1.0 / _mean),
    _generator(time(0)),
    _distribution(_lambda)
{}

PoissonRandomGenerator::~PoissonRandomGenerator()
{}

double PoissonRandomGenerator::nextDouble()
{
    return _distribution(_generator);
}
