#pragma once
#include "Herbivore.h"

class Wildebeest : public Herbivore 
{
public:
    Wildebeest(const double InputWeight, const bool InputBAlive, const Continent& InputCont);

    void eatGrass();

    void print();

    virtual ~Wildebeest() = 0;
};

