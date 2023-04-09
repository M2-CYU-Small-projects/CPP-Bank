#include "Cashier.h"
#include "../event/ClientDeparture.h"

Cashier::Cashier(Bank& bank, double averageServiceTime): _randomGenerator(averageServiceTime)
{
    _bank = &bank;
    _averageServiceTime = averageServiceTime;
    _client = nullptr;
    _nbClientsServed = 0;
    _workingTime = 0;
    
}

Cashier::Cashier(Cashier &cashier): _randomGenerator(cashier._averageServiceTime)
{
    _bank = cashier._bank;
    _averageServiceTime = cashier._averageServiceTime;
    _client = cashier._client;
    _nbClientsServed = cashier._nbClientsServed;
    _workingTime = cashier._workingTime;
}

Cashier::~Cashier()
{}

double Cashier::averageServiceTime() const
{
    return _averageServiceTime;
}

int Cashier::nbClients() const
{
    return _nbClientsServed;
}

double Cashier::OccupationRate()
{
    return _workingTime/_bank->realLength();
}

bool Cashier::isFree()
{
    return _client==nullptr;
}

void Cashier::free()
{
    _client = nullptr;
}

void Cashier::serve(Client* client)
{
    // cout << "serving" << endl;
    _nbClientsServed++;
    _client = client;
    double servingTime = _randomGenerator.nextDouble();
    // The service only begins when the client starts to be served,
    // so the departure event must be set at this moment, not the client arrival time
    double eventTime = _bank->hour() + servingTime;
    ClientDeparture* newEvent = new ClientDeparture(*_bank, eventTime, *_client, *this); 
    _workingTime += servingTime;
    _bank->add(*newEvent);

}

void Cashier::wait()
{

}
