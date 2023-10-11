#pragma once

#include "Vehicle.h"

class Base 
{
private:
    static const int MAX_VEHICLES = 100;
    Vehicle* vehicles[MAX_VEHICLES];
    int vehicle_count;
    int people_on_base;
    int vehicles_on_base;
    double petrol_on_base;
    double goods_on_base;

public:
    Base();

    void addVehicle(Vehicle* new_vehicle);
    void delVehicle(int index);

    void addPeople(int count);
    void delPeople(int count);

    void addPetrol(double amount);
    void delPetrol(double amount);
    
    void addGoods(double amount);
    void delGoods(double amount);

    void printStats(); 

    int getPeopleOnBase();
    int getVehiclesOnBase();
    double getPetrolOnBase();
    double getGoodsOnBase();
};

