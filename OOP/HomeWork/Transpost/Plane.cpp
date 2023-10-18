#include "Plane.h"
#include <iostream>


Plane::Plane(double speed, double volume, std::string fuelType, std::string name, int passengerCapacity) : Transport(speed, volume, fuelType), name(name), passengerCapacity(passengerCapacity) {}

void Plane::display() const 
{
    Transport::display();
    std::cout << "Name: " << this->name << std::endl;;
    std::cout << "Passenger Capacity: " << this->passengerCapacity << " passengers" << std::endl;;
}

std::string Plane::getName() const { return this->name; }

void Plane::setName(std::string name) { this->name = name; }

int Plane::getPassengerCapacity() const {  return this->passengerCapacity; }

void Plane::setPassengerCapacity(int passengerCapacity) {  this->passengerCapacity = passengerCapacity; }

void Plane::Input() 
{
    Transport::Input();
    std::cout << "Enter name: ";
    std::cin >> this->name;
    std::cout << "Enter passenger capacity: ";
    std::cin >> this->passengerCapacity;
}