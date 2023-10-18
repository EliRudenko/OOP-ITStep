#pragma once
#include <string>

class Transport 
{
protected:
    double speed;
    double volume;
    std::string fuelType;

public:
    Transport(double speed = 0, double volume = 0, std::string fuelType = "");
    virtual ~Transport();

    virtual void display() const;
   
    void setSpeed(double speed);
    double getSpeed() const;
    void setVolume(double volume);
    double getVolume() const;
    void setFuelType(std::string fuelType);
    std::string getFuelType() const;
    
    virtual void Input();

};

