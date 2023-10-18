#include "Africa.h"
#include <iostream>

Africa::Africa() 
{
    temperature = 35;
    area = 28.82; 
    numAnimals = 0;
    maxAnimals = 10; 
    animals = new std::string[maxAnimals];
}

Africa::~Africa() { delete[] animals; }

void Africa::SetTemperature(int temp) { temperature = temp; }

void Africa::SetArea(float a) { area = a; }

void Africa::AddAnimal(std::string animal) 
{
    if (numAnimals < maxAnimals) { animals[numAnimals++] = animal; }
}

void Africa::ShowInfo() 
{
    std::cout << "Africa Info:" << std::endl;
    std::cout << "Temperature: " << temperature << "°C" << std::endl;
    std::cout << "Area: " << area << " million sq km" << std::endl;
    std::cout << "Animals: ";
    for (int i = 0; i < numAnimals; ++i) 
    {
        std::cout << animals[i];
        if (i < numAnimals - 1) { std::cout << ", "; }
    }
    std::cout << std::endl;
}
