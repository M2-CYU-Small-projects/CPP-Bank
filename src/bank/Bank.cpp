#include "Bank.h"

#include <sstream>

#include "../event/ClientArrival.h"


Bank::Bank(int nbCashier, double estimatedLength, std::list<double> cashierServiceTimes, double averageArrivalTime): 
    SED(),
    _waitingLine(*this),
    _arrivalTimeGenerator(averageArrivalTime)
{
    _nbCashier = nbCashier;
    _estimatedLength = estimatedLength;
    _realLength = 0.0;
    _averageArrivalTime = averageArrivalTime;
    _cashiers = new Cashier*[nbCashier];
    if(nbCashier != cashierServiceTimes.size()){
        throw InvalidTimeNumberException(nbCashier, cashierServiceTimes.size());
    }

    int index = 0;
    for (std::list<double>::iterator it = cashierServiceTimes.begin(); it != cashierServiceTimes.end(); it++)
    {
        _cashiers[index] = new Cashier(*this, *it);
        index++;
    }
}

Bank::Bank(Bank& bank):
    SED(),
    _waitingLine(bank._waitingLine),
    _arrivalTimeGenerator(bank._averageArrivalTime)
{
    _nbCashier = bank._nbCashier;
    _estimatedLength = bank._estimatedLength;
    _realLength = bank._realLength;
    _averageArrivalTime = bank._averageArrivalTime;
    _cashiers = new Cashier*[bank._nbCashier];
    for (int i = 0; i < _nbCashier; i++)
    {
        _cashiers[i] = new Cashier(*bank._cashiers[i]);
    }
}

Bank::~Bank()
{
    delete[] _cashiers;
}

void Bank::run(){
    ClientArrival* newClient  = new ClientArrival(*this, computeNextArrivalTime());
    add(*newClient);
    SED::run();
    _realLength = SED::hour();
}

Bank& Bank::operator=(const Bank& other)
{
    if (this == &other)
    {
        return *this;
    }

    _waitingLine = other._waitingLine;
    _nbCashier = other._nbCashier;
    _estimatedLength = other._estimatedLength;
    _realLength = other._realLength;
    _averageArrivalTime = other._averageArrivalTime;
    _cashiers = new Cashier*[other._nbCashier];

    return *this;
}

bool Bank::operator==(const Bank& other)
{
    if (this == &other)
    {
        return true;
    }

    return _nbCashier == other._nbCashier
        && _estimatedLength == other._estimatedLength
        && _realLength == other._realLength
        && _averageArrivalTime == other._averageArrivalTime;
}

double Bank::estimatedLength() const
{
    return _estimatedLength;
}

int Bank::nbCashier() const
{
    return _nbCashier;
}

double Bank::timeBetweenArrival() const
{
    return _averageArrivalTime;
}

double Bank::realLength() const
{
    return _realLength;
}

int Bank::nbClientsServed() const
{
    int totalNbClients = 0;
    for (int i = 0; i < _nbCashier; i++)
    {
        totalNbClients += _cashiers[i]->nbClients();
    }
    return totalNbClients;
}

WaitingLine& Bank::waitingLine()
{
    return _waitingLine;
}

Cashier* Bank::firstFree()
{

    for (int i = 0; i < _nbCashier; i++)
    {
        Cashier* cashier(_cashiers[i]);
        if (cashier->isFree())
        {
            return cashier;
        }
    }
    return nullptr;
}

void Bank::addToLine(Client* client)
{
    _waitingLine.addClient(*client);
}

Client* Bank::getWaitingClient()
{
    return _waitingLine.removeFirst();
}

double Bank::computeNextArrivalTime()
{
    return _arrivalTimeGenerator.nextDouble();
}

void Bank::setRealLength(double hour){
    _realLength = hour;
}


void Bank::displaySimulationDatas(){
    cout << "----- Simulation Datas -----"<< endl;
    cout << "\tEstimated Length : " << _estimatedLength << endl;  
    cout << "\tReal Length : " << _realLength << endl;  
    cout << "\tAverage Waiting Time : " << _waitingLine.averageWaitingTime() << endl;
    cout << "\tMaximal Waiting Line Length : " << _waitingLine.maximumLength() << endl;
    cout << "\tAverage Waiting Line Length : " << _waitingLine.averageLength() << endl;
    cout << "-> Cashier data" << endl;
    for (int i = 0; i < _nbCashier; i++)
    {
        cout << "Cashier n°" << i << endl;
        cout << "\tOccupation rate : " << _cashiers[i]->OccupationRate() << endl;
        cout << "\tNumber of client served : " << _cashiers[i]->nbClients() << endl;
    }
    
}

// Exception definition

InvalidTimeNumberException::InvalidTimeNumberException(int cashierCount, int serviceTimeCount):
    nbCashier(cashierCount),
    nbServiceTimes(serviceTimeCount),
    message(
        "Number of cashiers is not the same as the number of times provided : nb cashiers : "
        + to_string(nbCashier) + ", nb times provided : " + to_string(serviceTimeCount)
    )
{}

const char* InvalidTimeNumberException::what()
{
    return message.c_str();
}