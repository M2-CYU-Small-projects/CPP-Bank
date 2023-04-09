#ifndef __CLIENTDEPARTURE_H__
#define __CLIENTDEPARTURE_H__

#include "../bank/Bank.h"
#include "../bank/Client.h"
#include "../bank/Cashier.h"
#include "Event.h"

/**
 * @brief An event triggered when client is not served by a cashier anymore.
 * The cashier will try to take another client if the waiting line is not empty.
 * @since Fri Sep 09 2022
 */
class ClientDeparture : public Event
{
private:
    
    Bank* _bank;
    Client* _client;
    Cashier* _cashier;

public:

    ClientDeparture(Bank& bank, double hour, Client& client, Cashier& cashier);
    ~ClientDeparture();

    void execute();

};

#endif // __CLIENTDEPARTURE_H__