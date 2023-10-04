#include "Car.h"
#include <iostream>

Car::Car(double speed, double volume, std::string fuelType, std::string name, int capacity) : Transport(speed, volume, fuelType), name(name), capacity(capacity) {}

void Car::display() const 
{
    Transport::display();
    std::cout << "Name: " << this->name << std::endl;;
    std::cout << "Capacity: " << this->capacity << " passengers" << std::endl;;
}

std::string Car::getName() const { return this->name; }

void Car::setName(std::string name) { this->name = name; }

int Car::getCapacity() const { return this->capacity; }

void Car::setCapacity(int capacity) { this->capacity = capacity; }

void Car::Input() 
{
    Transport::Input();
    std::cout << "Enter name: ";
    std::cin >> this->name;
    std::cout << "Enter capacity: ";
    std::cin >> this->capacity;
}
