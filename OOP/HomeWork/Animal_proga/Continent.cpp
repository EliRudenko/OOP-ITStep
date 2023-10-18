#include "Continent.h"
#include <cstring>

Continent::Continent(const double InputMedTemp, const double InputArea, Animal* InputHerb, Animal* InputCarn, const char* InputName) : medTemp(InputMedTemp), area(InputArea), herbivor(InputHerb), carnivor(InputCarn) 
{
        name = new char[strlen(InputName) + 1];
        strcpy(name, InputName);
}


char* Continent::getContName() const 
{
    int length = strlen(name);
    char* nameCopy = new char[length + 1];
    strcpy(nameCopy, name);
    return nameCopy;
}

double Continent::getContMedTemp() const { return medTemp; }

double Continent::getArea() const { return area; }
