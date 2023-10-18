#include <iostream>

#include "Vehicle.h"
#include "Base.h"


Vehicle::Vehicle(Base* base, double petrol_amount, double tank_volume) : petrol_amount(petrol_amount), tank_volume(tank_volume), base(base) 
{}

double Vehicle::getTankVolume() { return tank_volume; }

double Vehicle::getPetrolAmount() { return petrol_amount; }

void Vehicle::arrive() 
{
    base->addPeople(1);
    base->addVehicle(this);
    std::cout << "vehicle has arrived!" << std::endl;
}

bool Vehicle::leave() 
{
    if (base->getPeopleOnBase() > 0) 
    {
        base->delPeople(1);
        base->addPetrol(getTankVolume() - getPetrolAmount());
        petrol_amount = getTankVolume();

        std::cout << "vehicle has left!" << std::endl;
        return true;
    } 
    else 
    {
        std::cout << "Cannot leave!" << std::endl;
        return false;
    }
}

