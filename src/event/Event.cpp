#include "Event.h"

Event::Event(SED& sed, double hour){
    _sed = &sed;
    _hour = hour;
}

Event::~Event()
{}

double Event::hour() const{
    return _hour;
}

