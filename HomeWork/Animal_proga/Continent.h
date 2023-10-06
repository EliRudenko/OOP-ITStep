#pragma once
#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#include "Animal.h"

class Continent 
{
protected:
    double medTemp;
    double area;
    char* name; //пробн
    Animal* herbivor;
    Animal* carnivor;

public:
    //Continent(const double InputMedTemp, const double InputArea, const Animal& InputHerb, const Animal& InputCarn);

    Continent(const double InputMedTemp, const double InputArea, Animal* InputHerb, Animal* InputCarn, const char* InputName);

    virtual void printContSpecs(void) const = 0;

    char* getContName() const;
    double getContMedTemp() const;
    double getArea() const;

    virtual ~Continent() = 0;
};

