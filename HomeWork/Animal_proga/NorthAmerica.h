#pragma once
#include "Continent.h"

class NorthAmerica : public Continent 
{
private:
    char* name;

public:
    NorthAmerica(const double InputMedTemp, const double InputArea, const Animal& InputHerb, const Animal& InputCarn);

    void printContSpecs(void) const;
    char* getContName(void) const;

    ~NorthAmerica();
};

