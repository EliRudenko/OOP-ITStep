#include "Wolf.h"
#include "Continent.h"

Wolf::Wolf(const double InputWeight, const bool InputBAlive, const Continent& InputCont) : Carnivore(InputWeight, InputBAlive, InputCont) {}

void Wolf::eat(Animal* prey) 
{
    double predatorPower = getWeight(); // Сила хищника (волка)
    double preyWeight = prey->getWeight(); // Вес добычи

    if (predatorPower > preyWeight) 
    {
        predatorPower += 10; // Если сила хищника больше веса добычи, увеличиваем силу
    } else { predatorPower -= 10; }

    // Применяем измененную силу к хищнику
    weight = predatorPower;
}

void Wolf::print() 
{
    std::cout << "Wolf weight: " << getWeight() << " kg" << std::endl;
    std::cout << "Is alive: " << (isAlive() ? "Yes" : "No") << std::endl;
}
