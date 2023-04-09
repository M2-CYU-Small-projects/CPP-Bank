#ifndef __CASHIER_H__
#define __CASHIER_H__

#include "Client.h"
#include "../random/PoissonRandomGenerator.h"
#include <iostream>
using namespace std;

class Bank;

/**
 * @brief Modelisation of a Cashier that will serve clients during a defined average service time.
 * @author Nicolas CIBULKA
 * @since Thu Sep 08 2022
 */
class Cashier
{

private:
    Bank* _bank;
    double _averageServiceTime;
    int _nbClientsServed;
    double _workingTime;
    PoissonRandomGenerator _randomGenerator;

    /// @brief Can be null.
    Client* _client;

public:

    Cashier(Bank& bank, double averageServiceTime);
    Cashier(Cashier &cashier);
    ~Cashier();

    /**
     * @brief get the Average service time of this Cashier
     * @return double
     */
    double averageServiceTime() const;

    /**
     * @brief get the number of clients served by the Cashier
     * @return integer
     */
    int nbClients() const;

    /**
     * @brief Get the occupation rate
     * @return double
     */
    double OccupationRate();

    /**
     * @brief get if the cashier doesn't handle a client currently
     * @return Boolean
     */
    bool isFree();
  
    /**
     * @brief  Remove the client currently served. This does not free the client memory.
     * @return (void)
     */
    void free();

    /**
     * @brief Serve the given Client
     * @param client
     * @return (void)
     */
    void serve(Client* client);

    /**
     * @brief called when cashier wait for a client
     * @return (void)
     */
    void wait();
};


#endif // __CASHIER_H__