#include "Bison.h"
#include "Continent.h"
#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

Bison::Bison(const double InputWeight, const bool InputBAlive, const Continent& InputCont) : Herbivore(InputWeight, InputBAlive, InputCont) {}

void Bison::eatGrass() { weight += 10; }

void Bison::print() 
{
    std::cout << "Bison weight: " << weight << " kg" << std::endl;
    std::cout << "Is alive: " << (isAlive() ? "Yes" : "No") << std::endl;
}