#ifndef __CLIENTARRIVAL_H__
#define __CLIENTARRIVAL_H__

#include "../bank/Bank.h"
#include "Event.h"

/**
 * @brief An event that create a client and manage it in the bank depending if a Cashier is free.
 * @since Fri Sep 09 2022
 */
class ClientArrival : public Event
{
private:
    Bank* _bank;

public:

    ClientArrival(Bank& bank, double hour);
    ~ClientArrival();

    void execute();

};


#endif // __CLIENTARRIVAL_H__