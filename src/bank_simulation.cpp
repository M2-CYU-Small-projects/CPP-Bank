
#include "Bank.h"

#include "Input.h"

int main(int argc, char *argv[])
{
    try
    {
        Input input = retrieveInput(argc, argv);
        Bank bank(
            input.cashierCount,
            input.expectedDuration,
            input.averageTimes,
            input.averageArrivalTime
        );
        bank.run();
        bank.displaySimulationDatas();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}
