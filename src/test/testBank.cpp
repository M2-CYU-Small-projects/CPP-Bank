
#include <iostream>

#include "../bank/Bank.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "----- Test bank simulation -----" << endl;
    int nbCashier = 4;
    double estimatedLength = 200; 
    list<double> efficiencylist{6, 7, 7, 9};
    double averageArrivalInterval = 5;
    cout << " nbCashier : " << nbCashier << endl;
    cout << " estimatedLength : " << estimatedLength << endl;
    // cout << " efficiencylist : " << efficiencylist << endl;
    cout << " averageArrivalInterval : " << averageArrivalInterval << endl;

    Bank bank(nbCashier, estimatedLength, efficiencylist, averageArrivalInterval);

    bank.run();
    bank.displaySimulationDatas();
    return 0;
}

