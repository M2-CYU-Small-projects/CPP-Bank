#include "ClientArrival.h"
#include <iostream>
using namespace std;

ClientArrival::ClientArrival(Bank& bank, double hour) : Event(bank, hour), _bank(&bank)
{

}

ClientArrival::~ClientArrival()
{}

void ClientArrival::execute()
{
    Client* client = new Client(hour());
    Cashier* firstFreeCashier = _bank->firstFree();
    // manage client depending if a cashier is free or not
    if(firstFreeCashier != nullptr){
        // cout << "serve" << endl;
        firstFreeCashier->serve(client);
    }
    else{
        _bank->addToLine(client);
    }
    // calculation of the arrival of the next client
    double hpa = _bank->computeNextArrivalTime();
    double time = hour() + hpa;
    if(time < _bank->estimatedLength()){
        // create the new Arrival
        ClientArrival* newArrival = new ClientArrival(*_bank, time);
        // add it to the simulation
        _bank->add(*newArrival);
    }
    
}