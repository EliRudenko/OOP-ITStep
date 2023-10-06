#include "Animal.h"

Animal::Animal(const double InputWeight, const bool InputBAlive, const Continent* InputCont) : weight(InputWeight), alive(InputBAlive), continent(InputCont) 
{}

bool Animal::isAlive() const { return alive; }

double Animal::getWeight() const { return weight; }