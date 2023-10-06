#include "AnimalWorld.h"

AnimalWorld::AnimalWorld() : numHerbivores(0), numCarnivores(0) {}

void AnimalWorld::addHerbivore(Herbivore* herbivore) 
{
    if (numHerbivores < MAX_HERBIVORES) 
    {
        herbivores[numHerbivores] = herbivore;
        ++numHerbivores;
    }
    else { std::cout << "The herbivore array is completely full." << std::endl; }
}

void AnimalWorld::addCarnivore(Carnivore* carnivore) 
{
    if (numCarnivores < MAX_CARNIVORES) 
    {
        carnivores[numCarnivores] = carnivore;
        ++numCarnivores;
    }
    else { std::cout << "The carnivore array is completely full." << std::endl; }
}

void AnimalWorld::MealsHerbivores() 
{
    for (int i = 0; i < numHerbivores; ++i) { herbivores[i]->eat(); }
}

void AnimalWorld::NutritionCarnivores() 
{
    for (int i = 0; i < numCarnivores; ++i) 
    {
        Herbivore* prey = getHerbivore(); 
        if (prey) { carnivores[i]->eat(prey); }
    }
}

Herbivore* AnimalWorld::getHerbivore() 
{    
    if (numHerbivores > 0) { return herbivores[0]; } 
    else { return nullptr;  }
}