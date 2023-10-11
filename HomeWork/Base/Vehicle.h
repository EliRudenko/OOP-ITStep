#pragma once

#include "Base.h"
//class Base;

class Vehicle 
{
protected:
    double petrol_amount;
    double tank_volume;
    Base* base;

public:
    Vehicle(Base* base, double petrol_amount, double tank_volume);
    double getTankVolume();
    double getPetrolAmount();
    
    void arrive();
    bool leave();
};

