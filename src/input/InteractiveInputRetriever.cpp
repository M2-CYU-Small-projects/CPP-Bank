#include "InteractiveInputRetriever.h"

#include <iostream>
#include <sstream>

#include "Input.h"

using namespace std;

InteractiveInputRetriever::InteractiveInputRetriever() : InputRetriever()
{}

double askDuration()
{
    double duration;
    do
    {
        cout << "Expected duration : ";
        cin >> duration;
        if (duration <= 0.0)
        {
            cout << "Duration must be greater than 0" << endl;
        }
    } while (duration <= 0.0);
    return duration;
}

int askCashierCount()
{
    int cashierCount;
    do
    {
        cout << "Number of cashiers : ";
        cin >> cashierCount;
        if (cashierCount <= 0.0)
        {
            cout << "Must have more than 0 cashier in the bank" << endl;
        }
    } while (cashierCount <= 0);
    return cashierCount;
}

list<double> askAverageTimes(int cashierCount)
{
    list<double> times;
    do
    {
        times.clear();
        cout << "Put the average processing times of each cashier (separated by a space) :" << endl;
        
        string line;
        // Flush the stream for avoiding any wrong readings
        cin.ignore();
        getline(cin, line);

        // Read the line number by number
        stringstream ss(line);
        string numStr;
        while (ss >> numStr)
        {
            double time = stod(numStr);
            times.push_back(time);
        }

        int nbTimes = times.size();

        if (nbTimes < cashierCount)
        {
            cout << "Not enough times are provided (expected " << cashierCount << ", got " << nbTimes << ")" << endl;
        } else if (nbTimes > cashierCount)
        {
            cout << "Too much times are provided (expected " << cashierCount << ", got " << nbTimes << ")" << endl;
        }
    } while (times.size() != cashierCount);

    return times;
}

double askAverageArrivalTime()
{
    double average;
    do
    {
        cout << "Average arrival time : ";
        cin >> average;
        if (average <= 0.0)
        {
            cout << "Average time must be greater than 0" << endl;
        }
    } while (average <= 0.0);
    return average;
}

Input InteractiveInputRetriever::retrieve()
{
    double duration = askDuration();
    int cashierCount = askCashierCount();
    list<double> averageTimes = askAverageTimes(cashierCount);
    double averageArrivalTime = askAverageArrivalTime();

    return Input(duration, cashierCount, averageTimes, averageArrivalTime);
}
