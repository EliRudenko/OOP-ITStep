#include <iostream>

#include "Base.h"
#include "Vehicle.h"

Base::Base() : vehicle_count(0), people_on_base(0), vehicles_on_base(0), petrol_on_base(2800.0), goods_on_base(686.0) 
{
    for (int i = 0; i < MAX_VEHICLES; i++) { vehicles[i] = nullptr; }
}

void Base::addVehicle(Vehicle* new_vehicle) 
{
    if (vehicle_count < MAX_VEHICLES) {  vehicles[vehicle_count++] = new_vehicle; }
}

void Base::delVehicle(int index) 
{
    if (index >= 0 && index < vehicle_count) 
    {
        delete vehicles[index];
        vehicles[index] = nullptr;

        if (index != vehicle_count - 1) 
        {
            vehicles[index] = vehicles[vehicle_count - 1];
            vehicles[vehicle_count - 1] = nullptr;
        }

        vehicle_count--;
    }
}

void Base::addPeople(int count) {  people_on_base += count; }

void Base::delPeople(int count) 
{
    people_on_base -= count;
    if (people_on_base < 0) { people_on_base = 0; } 
}

void Base::addPetrol(double amount)  { petrol_on_base += amount; }

void Base::delPetrol(double amount) 
{
    petrol_on_base -= amount;
    if (petrol_on_base < 0) { petrol_on_base = 0; } 
}

void Base::addGoods(double amount) { goods_on_base += amount; }

void Base::delGoods(double amount) 
{
    goods_on_base -= amount;
    if (goods_on_base < 0) { goods_on_base = 0; }
}

void Base::printStats() 
{
    std::cout << "People on base: " << people_on_base << std::endl;
    std::cout << "Vehicles on base: " << vehicles_on_base << std::endl;
    std::cout << "Petrol on base: " << petrol_on_base << " liters" << std::endl;
    std::cout << "Goods on base: " << goods_on_base << " tons" << std::endl;
}

int Base::getPeopleOnBase() { return people_on_base; }

int Base::getVehiclesOnBase() { return vehicles_on_base; }

double Base::getPetrolOnBase() {  return petrol_on_base; }

double Base::getGoodsOnBase() { return goods_on_base; }
