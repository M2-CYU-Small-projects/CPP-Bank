#ifndef __SED_H__
#define __SED_H__

#include <set>

#include "Event.h"

/**
 * @brief This is a comparator between two events, used for kepping events in the right order in the set used by the SED class.
 * @author 
 * @since Fri Sep 09 2022
 */
class EventComparator{
    
    public:

    /**
     * @brief Override the operator () to compare events according to date
     * @param Event
     * @param event2
     * @return bool - true if event1 arrive after event2, false if not
     */
    bool operator()(const Event* event1, const Event* event2) const;
};

/**
 * @brief This class represent a discrete-event simulation
 * @author
 * @since Thu Sep 08 2022
 */
class SED
{
private:
    std::set<Event*, EventComparator> _eventSet;

    double _hour;

public:

    SED();

    ~SED();

    /**
     * @brief Add an event to the event queue
     * @param event
     * @return (void)
     */
    void add(Event& event);

    /**
     * @brief Execute the simulation
     * @return (void)
     */
    virtual void run();

    /**
     * @brief Get the simulation time
     * @return (double)
     */
    double hour();


};


#endif // __SED_H__