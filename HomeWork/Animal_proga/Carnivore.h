#pragma once
#include "Animal.h"

class Carnivore : public Animal 
{
public:
    Carnivore(const double InputWeight, const bool InputBAlive, const Continent& InputCont);

    virtual void eat(Animal* prey) = 0;

    void print();

    virtual ~Carnivore() = 0;
};
