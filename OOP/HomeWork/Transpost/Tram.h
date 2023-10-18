#pragma once
#include "Transport.h"

class Tram : public Transport 
{
private:
    std::string name;
    int routeNumber;
    int maxSpeed;

public:
    Tram(double speed = 0, double volume = 0, std::string fuelType = "", std::string name = "", int routeNumber = 0, int maxSpeed = 0);

    void display() const;

    std::string getName() const;
    void setName(std::string name);
    int getRouteNumber() const;
    void setRouteNumber(int routeNumber);
    int getMaxSpeed() const;
    void setMaxSpeed(int maxSpeed);
    
    void Input();
};

