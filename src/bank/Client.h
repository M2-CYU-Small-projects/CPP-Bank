#ifndef __CLIENT_H__
#define __CLIENT_H__

/**
 * @brief Modelisation of a client
 * @author Nicolas CIBULKA
 * @since Thu Sep 08 2022
 */
class Client
{

private:
    double _arrivalTime;

public:
    Client(double arrivalTime);
    ~Client();

    /**
     * @brief Get the arrival Time of the client
     * @return double
     */
    double arrivalTime();
};



#endif // __CLIENT_H__