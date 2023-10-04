#include "Tram.h"
#include <iostream>

Tram::Tram(double speed, double volume, std::string fuelType, std::string name, int routeNumber, int maxSpeed) : Transport(speed, volume, fuelType), name(name), routeNumber(routeNumber), maxSpeed(maxSpeed) {}

void Tram::display() const 
{
    Transport::display();
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Route Number: " << this->routeNumber <<std::endl;
    std::cout << "Max Speed: " << this->maxSpeed << " km/h" << std::endl;
}

std::string Tram::getName() const { return this->name; }

void Tram::setName(std::string name) { this->name = name; }

int Tram::getRouteNumber() const { return this->routeNumber; }

void Tram::setRouteNumber(int routeNumber) { this->routeNumber = routeNumber; }

int Tram::getMaxSpeed() const { return this->maxSpeed; }

void Tram::setMaxSpeed(int maxSpeed) {  this->maxSpeed = maxSpeed; }

void Tram::Input() 
{
    Transport::Input();
    std::cout << "Enter name: ";
    std::cin >> this->name;
    std::cout << "Enter route number: ";
    std::cin >> this->routeNumber;
    std::cout << "Enter max speed: ";
    std::cin >> this->maxSpeed;
}
