#ifndef __EVENT_H__
#define __EVENT_H__

class SED;

/**
 * @brief This class represents all the events that can happen during a SED simulation.
 * @author 
 * @since Fri Sep 09 2022
 */
class Event
{
private:
    SED* _sed;
    double _hour;

public:

    Event(SED& sed, double hour);
    ~Event();

    /**
     * @brief Launch the scenario corresponding to the event we created.
     */
    virtual void execute() = 0;

    /**
     * @brief get the hour of the event
     * @return 
     */
    double hour() const;

};


#endif // __EVENT_H__