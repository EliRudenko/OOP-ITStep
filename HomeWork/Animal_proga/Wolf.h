#pragma once
#include "Carnivore.h"

class Wolf : public Carnivore 
{
public:
    Wolf(const double InputWeight, const bool InputBAlive, const Continent& InputCont);

    void eat(Animal* prey);

    void print();

    virtual ~Wolf() = 0;
};

