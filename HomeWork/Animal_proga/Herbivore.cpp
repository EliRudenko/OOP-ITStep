#include "Herbivore.h"
#include "Continent.h"
#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

Herbivore::Herbivore(const double InputWeight, const bool InputBAlive, const Continent& InputCont) : Animal(InputWeight, InputBAlive, &InputCont) {}

void Herbivore::eat() { weight += 10; }

void Herbivore::print() 
{
    std::cout << "Herbivore weight: " << weight << " kg" << std::endl;
    std::cout << "Is alive: " << (isAlive() ? "Yes" : "No") << std::endl;
}