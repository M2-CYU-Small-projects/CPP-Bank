#include "WaitingLine.h"

#include "Bank.h"

WaitingLine::WaitingLine(Bank& bank) : _bank(&bank)
{}

WaitingLine::~WaitingLine()
{}

double WaitingLine::averageLength()
{
    if (_stepCount <= 0)
    {
        return 0.0;
    }
    return _sumLengthPerStep / _stepCount;
}

double WaitingLine::maximumLength()
{
    return _maximumLength;
}

double WaitingLine::averageWaitingTime()
{
    double nbClientsServed = _bank->nbClientsServed();
    if (nbClientsServed <= 0)
    {
        return 0.0;
    }
    return _totalWaitingTime / nbClientsServed;
}

void WaitingLine::updateLengthAttributes()
{
    int currentLength = _queue.size();
    _sumLengthPerStep += currentLength;
    _stepCount++;
    if (currentLength > _maximumLength)
    {
        _maximumLength = currentLength;
    }
}

void WaitingLine::addClient(Client& client)
{
    _queue.push(&client);
    updateLengthAttributes();
}

bool WaitingLine::isEmpty()
{
    return _queue.empty();
}

Client* WaitingLine::removeFirst()
{
    if (isEmpty())
    {
        return nullptr;
    }

    Client* client = _queue.front();
    _queue.pop();

    updateLengthAttributes();

    // When removing client, we must also update the waiting time (that the "addClient" operation does not)
    double waitingDuration = _bank->hour() - client->arrivalTime();
    _totalWaitingTime += waitingDuration;

    return client;
}
