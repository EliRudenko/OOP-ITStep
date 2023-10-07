#include <iostream>
#include "Africa.cpp"
#include "NorthAmerica.cpp"
#include "Wildebeest.cpp"
#include "Bison.h"
#include "Lion.h"
#include "Wolf.h"
#include "AnimalWorld.h"

/*
int main() 
{
    // Мир животных
    AnimalWorld animalWorld;

    // Создаем травоядных и хищников с помощью указателей
    Herbivore* wildebeest = new Wildebeest;
    Herbivore* bison = new Bison;
    Carnivore* lion = new Lion;
    Carnivore* wolf = new Wolf;

    // Добавляем травоядных в мир
    animalWorld.addHerbivore(wildebeest);
    animalWorld.addHerbivore(bison);

    // Добавляем хищников в мир
    animalWorld.addCarnivore(lion);
    animalWorld.addCarnivore(wolf);

    // Кормим травоядных
    animalWorld.MealsHerbivores();

    // Плотоядные охотятся друг на друга
    animalWorld.NutritionCarnivores();

    // Освобождаем память для избежания утечек
    delete wildebeest;
    delete bison;
    delete lion;
    delete wolf;

    return 0;
}
*/

int main() 
{
//быстрая проверочка))
    AnimalWorld animalWorld;

//указатели на зищьников и травоядн.
    Herbivore* wildebeest = new Wildebeest(100, true, africa);
    Herbivore* bison = new Bison(120, true, northAmerica);
    Carnivore* lion = new Lion(150, true, africa);
    Carnivore* wolf = new Wolf(90, true, northAmerica);

    animalWorld.addHerbivore(wildebeest);
    animalWorld.addHerbivore(bison);
    animalWorld.addCarnivore(lion);
    animalWorld.addCarnivore(wolf);


//кормежка
    animalWorld.MealsHerbivores();
    animalWorld.NutritionCarnivores();


    delete wildebeest;
    delete bison;
    delete lion;
    delete wolf;

    return 0;
}