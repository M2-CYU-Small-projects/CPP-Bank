#ifndef __POISSONRANDOMGENERATOR_H__
#define __POISSONRANDOMGENERATOR_H__

#include <random>

#include "RandomGenerator.h"

/**
 * @brief Implementation of the {@link RandomGenerator} following the Poisson's law
 * @author
 * @since Fri Sep 09 2022
 * @see RandomGenerator
 */
class PoissonRandomGenerator : RandomGenerator
{
private:
    double _mean;
    double _lambda;

    std::default_random_engine _generator;
    // The poisson process is done by using poisson arrival rate lambda
    // on an exponential distribution
    std::exponential_distribution<double> _distribution;

public:
    PoissonRandomGenerator(double mean);
    ~PoissonRandomGenerator();

    /**
     * Returns the next number of the state in the double format.
     */
    double nextDouble();
};

#endif // __POISSONRANDOMGENERATOR_H__