
#include "Ship.h"
#include <iostream>

Ship::Ship(double speed, double volume, std::string fuelType, std::string name, int cargoCapacity) : Transport(speed, volume, fuelType), name(name), cargoCapacity(cargoCapacity) {}

void Ship::display() const 
{
    Transport::display();
    std::cout << "Name: " << this->name << std::endl;;
    std::cout << "Cargo Capacity: " << this->cargoCapacity << " tons" << std::endl;;
}

std::string Ship::getName() const { return this->name; }

void Ship::setName(std::string name) { this->name = name; }

int Ship::getCargoCapacity() const { return this->cargoCapacity; }

void Ship::setCargoCapacity(int cargoCapacity) { this->cargoCapacity = cargoCapacity; }

void Ship::Input() 
{
    Transport::Input();
    std::cout << "Enter name: ";
    std::cin >> this->name;
    std::cout << "Enter cargo capacity: ";
    std::cin >> this->cargoCapacity;
}
