#include "SED.h"
#include <iostream>
using namespace std;

SED::SED(){
    _hour = 0;
}

SED::~SED(){

}

void SED::add(Event& event){
    _eventSet.insert(&event);
}

double SED::hour(){
    return _hour;
}

void SED::run(){
    while(_eventSet.size() != 0){
        Event* event = *_eventSet.begin();
        _eventSet.erase(_eventSet.begin());
        _hour = event->hour();
        event->execute();
        delete event;
    }
}

bool EventComparator::operator()(const Event* event1, const Event* event2) const
{
    return (event1->hour() < event2->hour());
}
