#include "Input.h"

#include "InputRetriever.h"
#include "ArgumentsInputRetriever.h"
#include "InteractiveInputRetriever.h"

Input::Input(double excpectedDur, int nbCashiers, std::list<double> averageTimeList, double averageArrivalTm):
    expectedDuration(excpectedDur),
    cashierCount(nbCashiers),
    averageTimes(averageTimeList),
    averageArrivalTime(averageArrivalTm)
{}

/**
 * Create a retriever depending on the implementation to use 
 */
InputRetriever* createRetriever(int argc, char *argv[])
{
    // No argument provided : interactive mode
    if (argc == 1)
    {
        return new InteractiveInputRetriever();
    }

    // Default case : CLI mode
    return new ArgumentsInputRetriever(argc, argv);
}

Input retrieveInput(int argc, char *argv[])
{
    InputRetriever* retriever = createRetriever(argc, argv);
    Input input = retriever->retrieve();
    delete retriever;
    return input;
}