#include <iostream>

#include "Bus.h"
#include "Base.h"


Bus::Bus(Base* base, int people, int max_people, double petrol, double max_petrol) : Vehicle(base, petrol, max_petrol), people_count(people), max_people(max_people) 
{}

int Bus::getPeopleCount() { return people_count; }

int Bus::getMaxPeople() {  return max_people; }

void Bus::arrive() 
{
    base->addPeople(people_count);
    base->addVehicle(this);
    std::cout << "bus has arrived!" << std::endl;
}

bool Bus::leave() 
{
    if (base->getPeopleOnBase() >= people_count) 
    {
        base->delPeople(people_count);
        base->addPetrol(getTankVolume() - getPetrolAmount());
        petrol_amount = getTankVolume();

        std::cout << "bus has left!" << std::endl;
        return true;
    } 
    else 
    {
        std::cout << "Cannot leave!" << std::endl;
        return false;
    }
}

