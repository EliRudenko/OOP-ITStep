#pragma once

#include "Vehicle.h"
#include "Base.h"

class Truck : public Vehicle 
{
private:
    double load;
    double max_load;

public:
    Truck(Base* base, double load, double max_load, double petrol, double max_petrol);
    double getCurrentLoad();
    double getMaxLoad();

    void arrive();
    bool leave();
};
