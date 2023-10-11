#include <iostream>

#include "Truck.h"
#include "Base.h"


Truck::Truck(Base* base, double load, double max_load, double petrol, double max_petrol) : Vehicle(base, petrol, max_petrol), load(load), max_load(max_load) 
{}

double Truck::getCurrentLoad() { return load; }

double Truck::getMaxLoad() { return max_load; }

void Truck::arrive() 
{
    base->addGoods(load);
    base->addVehicle(this);
    std::cout << "truck has arrived!" << std::endl;
}

bool Truck::leave() 
{
    if (base->getGoodsOnBase() >= load) 
    {
        base->delGoods(load);
        base->addPetrol(getTankVolume() - getPetrolAmount());
        petrol_amount = getTankVolume();

        std::cout << "truck has left!" << std::endl;
        return true;
    } 
    else 
    {
        std::cout << "Cannot leave!" << std::endl;
        return false;
    }
}

