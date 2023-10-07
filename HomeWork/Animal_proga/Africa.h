#pragma once
#include "Continent.h"
#include <string>

class Africa : public Continent 
{
private:
    int temperature;
    float area;
    std::string* animals;
    int numAnimals;
    int maxAnimals;
public:
    Africa();
    ~Africa();
    void SetTemperature(int temp);
    void SetArea(float area);
    void AddAnimal(std::string animal);
    void ShowInfo();
};


