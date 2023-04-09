#ifndef __RANDOMGENERATOR_H__
#define __RANDOMGENERATOR_H__

/**
 * @brief An abstract class with an internal state for generating numbers
 * @author 
 * @since Fri Sep 09 2022
 */
class RandomGenerator
{
private:
public:
    RandomGenerator();
    ~RandomGenerator();

    /**
     * Returns the next number of the state in the double format.
     */
    virtual double nextDouble() = 0;
};

#endif // __RANDOMGENERATOR_H__