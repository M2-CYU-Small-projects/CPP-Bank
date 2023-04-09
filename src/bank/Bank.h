#ifndef __BANK_H__
#define __BANK_H__

#include <list>
#include <stdexcept>

#include "Cashier.h"
#include "WaitingLine.h"
#include "../event/SED.h"
#include "../random/PoissonRandomGenerator.h"

/**
 * @brief The root of the simulation. This contains all methods relative to a bank and it's mechanics.
 * @author
 * @since Thu Sep 08 2022
 * @see SED
 */
class Bank : public SED
{

private:

    Cashier** _cashiers;

    int _nbCashier;

    double _estimatedLength;

    double _realLength;

    WaitingLine _waitingLine;

    double _averageArrivalTime;
    /**
     * The random generator used for computing next client arrival
     */
    PoissonRandomGenerator _arrivalTimeGenerator;
public:

    Bank(int nbCashier, double estimatedLength, std::list<double> cashierServiceTimes, double averageArrivalTime);
    Bank(Bank& bank);
    ~Bank();

    Bank& operator=(const Bank& other);
    bool operator==(const Bank& other);

    /**
     * @brief Run the simulation
     * @return (void)
     */
    void run();

   
    /**
     * @brief Getter for the "estimatedLength" input
     * @return double - Estimated Length
     */
    double estimatedLength() const;

    
    /**
     * @brief Getter for the "nbCashier" input
     * @return integer - number of Cashier
     */
    int nbCashier() const;

    
    /**
     * @brief Getter for the "average arrival time" input
     * @return double - Time between two arrivals
     */
    double timeBetweenArrival() const;

    /**
     * @brief getter for the real length of the simulation
     * @return double - real length
     */
    double realLength() const;

    /**
     * @brief getter of the number of clients served by the Bank
     * @return int - number of clients served
     */
    int nbClientsServed() const;

    /**
     * @brief Getter of the reference of the waitingLine
     * @return WaitingLine& - reference of the waitingLing
     */
    WaitingLine& waitingLine();

    /**
     * @brief Getter of the first free cashier in the Bank
     * @return Cashier* - a Cashier
     */
    Cashier* firstFree();

    /**
     * @brief Add a client to the waitingLine
     * @param client
     * @return (void)
     */
    void addToLine(Client* client);

    /**
     * @brief Get the first client in the waiting List
     * @return Client* - a client
     */
    Client* getWaitingClient();

    /**
     * @brief get the next Arrival Time
     * @return double - Arrival Time
     */
    double computeNextArrivalTime();

    /**
     * @brief Display the data of the simulation, such as the length of th simulation, the occupation of each cashier, ...
     * @return (void)
     */
    void displaySimulationDatas();

    /**
     * @brief Set the real length of the simulation
     * @param hour 
     * @return (void)
     */
    void setRealLength(double hour);

};


/**
 * @brief Exception raised when the number of averageServiceTime isnt the same as the number of Cashier
 * @author 
 * @since Sat Sep 17 2022
 */
class InvalidTimeNumberException : public std::exception {
    public:

    const int nbCashier;

    const int nbServiceTimes;

    const std::string message;

    InvalidTimeNumberException(int cashierCount, int serviceTimeCount);

    const char* what();
};


#endif // __BANK_H__