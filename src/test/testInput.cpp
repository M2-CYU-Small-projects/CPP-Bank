
#include <iostream>
#include <sstream>

#include "../input/Input.h"

using namespace std;

string listToString(list<double> list)
{
    stringstream ss;
    ss << "[ ";
    for (std::list<double>::iterator it = list.begin(); it != list.end(); it++)
    {
        ss << *it << " ";
    }
    ss << "]";
    return ss.str();
}

int main(int argc, char *argv[])
{
    Input input = retrieveInput(argc, argv);

    cout << "Expected duration : " << input.expectedDuration << "\n"
        << "Cashier count : " << input.cashierCount << "\n"
        << "Average times : " << listToString(input.averageTimes) << "\n"
        << "Average arrival time : " << input.averageArrivalTime << "\n";

    return 0;
}
