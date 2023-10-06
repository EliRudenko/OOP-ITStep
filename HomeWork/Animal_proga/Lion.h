#pragma once
#include "Carnivore.h"

class Lion : public Carnivore 
{
public:
    Lion(const double InputWeight, const bool InputBAlive, const Continent& InputCont);

    void eat(Animal* prey);

    void print();

    virtual ~Lion() = 0;
};

