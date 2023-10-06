#include "Carnivore.h"
#include "Continent.h"
#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

Carnivore::Carnivore(const double InputWeight, const bool InputBAlive, const Continent& InputCont) : Animal(InputWeight, InputBAlive, &InputCont) {}

void Carnivore::print() 
{
    std::cout << "Carnivore weight: " << weight << " kg" << std::endl;
    std::cout << "Is alive: " << (isAlive() ? "Yes" : "No") << std::endl;
}
