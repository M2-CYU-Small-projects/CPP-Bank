#include "ClientDeparture.h"

ClientDeparture::ClientDeparture( Bank& bank, double hour, Client& client, Cashier& cashier) : Event(bank, hour), _bank(&bank)
{
    _client = &client;
    _cashier = &cashier;
}

ClientDeparture::~ClientDeparture()
{}

void ClientDeparture::execute()
{
    // remove client
    // update realLength
    delete _client;
    // delete does not set the cashier's _client pointer to null
    _cashier->free();
    // manage Cashier depending presence of other clients
    WaitingLine& waitingLine = _bank->waitingLine();
    if (waitingLine.isEmpty())
    {
        _cashier->wait();
    }
    else{
        Client* newClient = waitingLine.removeFirst();
        if (newClient != nullptr)
        {
            _cashier->serve(newClient);
        }
    }
}
