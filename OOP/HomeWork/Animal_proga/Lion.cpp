#include "Lion.h"
#include "Continent.h"
#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

Lion::Lion(const double InputWeight, const bool InputBAlive, const Continent& InputCont) : Carnivore(InputWeight, InputBAlive, InputCont) {}

void Lion::eat(Animal* prey) 
{
    double predatorPower = getWeight(); // Сила хищника (лева)
    double preyWeight = prey->getWeight(); // Вес добычи

    if (predatorPower > preyWeight) 
    {
        predatorPower += 10; // Если сила хищника больше веса добычи, увеличиваем силу
    } else 
    {
        predatorPower -= 10; // Иначе уменьшаем силу
    }
    weight = predatorPower;
}

void Lion::print() 
{
    std::cout << "Lion weight: " << getWeight() << " kg" << std::endl;
    std::cout << "Is alive: " << (isAlive() ? "Yes" : "No") << std::endl;
}