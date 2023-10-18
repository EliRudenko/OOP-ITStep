#pragma once
#include "Transport.h"

class Car : public Transport 
{
private:
    std::string name;
    int capacity;

public:
    Car(double speed = 0, double volume = 0, std::string fuelType = "", std::string name = "", int capacity = 0);

    void display() const;

    std::string getName() const;
    void setName(std::string name);
    int getCapacity() const;
    void setCapacity(int capacity);
    
    void Input();
};

