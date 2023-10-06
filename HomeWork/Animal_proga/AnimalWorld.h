#pragma once
/*
class AnimalWorld 
{
public:

    void MealsHerbivores();

    void NutritionCarnivores();
};
*/

#include "Continent.h"
#include "Herbivore.h"
#include "Carnivore.h"

class AnimalWorld 
{
private:
    static const int MAX_HERBIVORES = 100; // Максимальное количество травоядных
    Herbivore* herbivores[MAX_HERBIVORES]; // Массив указателей на травоядных
    int numHerbivores; // Текущее количество травоядных

    static const int MAX_CARNIVORES = 100; // Максимальное количество плотоядных
    Carnivore* carnivores[MAX_CARNIVORES]; // Массив указателей на плотоядных
    int numCarnivores; // Текущее количество плотоядных

public:
    AnimalWorld();

    void addHerbivore(Herbivore* herbivore);

    void addCarnivore(Carnivore* carnivore);

    void MealsHerbivores();

    void NutritionCarnivores();

    Herbivore* getHerbivore();
};
