#pragma once

#include "Vehicle.h"
#include "Base.h"

class Bus : public Vehicle 
{
private:
    int people_count;
    int max_people;

public:
    Bus(Base* base, int people, int max_people, double petrol, double max_petrol);
    int getPeopleCount();
    int getMaxPeople();
    
    void arrive();
    bool leave();
};

