#include "Wildebeest.h"
#include "Continent.h"
#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

Wildebeest::Wildebeest(const double InputWeight, const bool InputBAlive, const Continent& InputCont) : Herbivore(InputWeight, InputBAlive, InputCont) {}

void Wildebeest::eatGrass() { weight += 10; }

void Wildebeest::print() 
{
    std:: cout << "Wildebeest weight: " << weight << " kg" << std::endl;
    std:: cout << "Is alive: " << (isAlive() ? "Yes" : "No") << std::endl;
}

Wildebeest::~Wildebeest()
{

}
