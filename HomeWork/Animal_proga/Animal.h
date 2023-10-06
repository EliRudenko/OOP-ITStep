#pragma once
#include "Continent.h"

class Animal 
{
protected:
    double weight;
    bool alive;
    //Continent* continent;
    const Continent* continent;

public:
    //Animal(const double InputWeight, const bool InputBAlive, const Continent& InputCont);

    Animal(const double InputWeight, const bool InputBAlive, const Continent* InputCont);


    virtual void eat(void) = 0;

    bool isAlive(void) const;
    double getWeight(void) const;

    virtual void print(void) = 0;

    virtual ~Animal() = 0;
};

