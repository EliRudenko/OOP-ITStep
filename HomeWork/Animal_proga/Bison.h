#pragma once
#include "Herbivore.h"

class Bison : public Herbivore 
{
public:
    Bison(const double InputWeight, const bool InputBAlive, const Continent& InputCont);

    void eatGrass();

    void print();

    virtual ~Bison() = 0;
};

