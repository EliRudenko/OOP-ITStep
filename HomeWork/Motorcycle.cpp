#include "Motorcycle.h"
#include <iostream>

Motorcycle::Motorcycle(double speed, double volume, std::string fuelType, std::string name) : Transport(speed, volume, fuelType), name(name){}

void Motorcycle::display() const 
{
    Transport::display();
    std::cout << "Name: " << this->name << "\n";
}

std::string Motorcycle::getName() const { return this->name; }

void Motorcycle::setName(std::string name) { this->name = name; }


void Motorcycle::Input() 
{
    Transport::Input();
    std::cout << "Enter name: ";
    std::cin >> this->name;
}
