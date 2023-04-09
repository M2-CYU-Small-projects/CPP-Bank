#ifndef __INPUT_H__
#define __INPUT_H__

#include <list>
#include <stdexcept>

/**
 * @brief The structure containing all needed parameters for the simulation to run.
 * An instance of this structure created by an InputRetriever is garanteed to be valid.
 * @author 
 * @since Fri Sep 09 2022
 * @see InputRetriever
 */
class Input
{
public:
    const double expectedDuration;
    const int cashierCount;
    const std::list<double> averageTimes;
    const double averageArrivalTime;

    Input(double excpectedDur, int nbCashiers, std::list<double> averageTimeList, double averageArrivalTm);
};

/**
 * @brief  the user input. The type of retrieval depends on what the user provided as arguments with the process call.
 * 
 * @throw An exception depending on the retrieval method. Garanteed to be subtype of std::exception.
 */
Input retrieveInput(int argc, char *argv[]);

#endif // __INPUT_H__