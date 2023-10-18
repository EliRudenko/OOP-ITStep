#pragma once

#include "Continent.h"
#include <string>

class NorthAmerica : public Continent 
{
private:
    int temperature;
    float area;
    std::string* animals;
    int numAnimals;
    int maxAnimals;
public:
    NorthAmerica();
    ~NorthAmerica();
    void SetTemperature(int temp);
    void SetArea(float area);
    void AddAnimal(std::string animal);
    void ShowInfo();

};

