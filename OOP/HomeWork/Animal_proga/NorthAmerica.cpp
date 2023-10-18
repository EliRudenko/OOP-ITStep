#include "NorthAmerica.h"
#include <iostream>

NorthAmerica::NorthAmerica() 
{
    // Инициализация по умолчанию
    temperature = 20;
    area = 24.71; // Пример значения
    numAnimals = 0;
    maxAnimals = 10; // Пример значения
    animals = new std::string[maxAnimals];
}

NorthAmerica::~NorthAmerica() { delete[] animals; }

void NorthAmerica::SetTemperature(int temp) { temperature = temp; }

void NorthAmerica::SetArea(float a) { area = a; }

void NorthAmerica::AddAnimal(std::string animal) 
{
    if (numAnimals < maxAnimals) { animals[numAnimals++] = animal; }
}

void NorthAmerica::ShowInfo() 
{
    std::cout << "North America Info:" << std::endl;
    std::cout << "Temperature: " << temperature << "°C" << std::endl;
    std::cout << "Area: " << area << " million sq km" << std::endl;
    std::cout << "Animals: ";
    for (int i = 0; i < numAnimals; ++i) 
    {
        std::cout << animals[i];
        if (i < numAnimals - 1) {  std::cout << ", "; }
    }
    std::cout << std::endl;
}
