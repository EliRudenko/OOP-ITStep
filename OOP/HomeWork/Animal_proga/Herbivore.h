#pragma once
#include "Animal.h"

class Herbivore : public Animal 
{
public:
    Herbivore(const double InputWeight, const bool InputBAlive, const Continent& InputCont);

    void eat();

    void print();

    virtual ~Herbivore() = 0;
};

