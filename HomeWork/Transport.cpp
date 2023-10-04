#include "Transport.h"
#include <iostream>

Transport::Transport(double speed, double volume, std::string fuelType) : speed(speed), volume(volume), fuelType(fuelType) {}

Transport::~Transport() {}

void Transport::display() const 
{
    std::cout << "Speed: " << this->speed << " km/h" << std::endl;;
    std::cout << "Volume: " << this->volume << " liters" << std::endl;;
    std::cout << "Fuel Type: " << this->fuelType << std::endl;;
}

void Transport::setSpeed(double speed) { this->speed = speed; }

double Transport::getSpeed() const { return this->speed; }

void Transport::setVolume(double volume) { this->volume = volume; }

double Transport::getVolume() const {  return this->volume; }

void Transport::setFuelType(std::string fuelType) {  this->fuelType = fuelType; }

std::string Transport::getFuelType() const {  return this->fuelType; }

void Transport::Input() 
{
    std::cout << "Enter speed: ";
    std::cin >> this->speed;
    std::cout << "Enter volume: ";
    std::cin >> this->volume;
    std::cout << "Enter fuel type: ";
    std::cin >> this->fuelType;
}
