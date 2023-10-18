#pragma once
#include "Transport.h"

class Motorcycle : public Transport 
{
private:
    std::string name;

public:
     Motorcycle(double speed = 0, double volume = 0, std::string fuelType = "", std::string name = "");

    void display() const;
    
    std::string getName() const;
    void setName(std::string name);
    bool getHasSidecar() const;
    void setHasSidecar(bool hasSidecar);

    void Input();
};

