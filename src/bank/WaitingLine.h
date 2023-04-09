#ifndef __WAITINGLINE_H__
#define __WAITINGLINE_H__

#include <queue>
#include <list>

#include "Client.h"

class Bank;

/**
 * @brief The lin
 * @author  
 * @since Fri Sep 09 2022
 */
class WaitingLine
{

private:
    Bank* _bank;
    std::queue<Client*> _queue;

    double _totalWaitingTime = 0.0;

    /**
     * The current maximum length of the queue.
     */
    double _maximumLength = 0.0;

    /**
     * For each client arrival / departure, the current length of the queue will be added to the total sum.
     * This is used for the computation of the average length.
     */
    double _sumLengthPerStep = 0.0;

    /**
     * For each client arrival / departure, the counter will increment
     * Used for the computation of the average length
     */
    int _stepCount = 0.0;

    /**
     * Update the average and maximum length of the queue.
     */
    void updateLengthAttributes();

public:

    WaitingLine(Bank& bank);
    ~WaitingLine();


    /**
     * @brief Compute the average length from all the previous lengths over each step (1 step = 1 departure or arrival).
     * @return 
     */
    double averageLength();

    /**
     * @brief Get the maximum length of the line
     * @return 
     */
    double maximumLength();

    /**
     * @brief Compute the average waiting time for all the clients. This is updated when removing a client.
     * @return 
     */
    double averageWaitingTime();

   
    /**
     * @brief Add a client to the queue and update the average (and possibly the maximum) length.
     * @param client
     * @return (void)
     */
    void addClient(Client& client);

    /**
     * @brief Check if the waitingLine is empty
     * @return 
     */
    bool isEmpty();

    /**
     * @brief Remove and returns the first client on the queue or null if the queue is empty. If the queue was not empty, this operation will trigger a new step,  so the average length will be altered. Moreover, removing a client will also alter the total and average waiting time.
     * @return Client*
     */
    Client* removeFirst();
};



#endif // __WAITINGLINE_H__