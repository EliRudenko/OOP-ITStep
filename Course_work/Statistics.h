#pragma once

#include "Score.h"

class Statistics 
{
private: //поля принадлежат только обьектам этого класса, за пределами НЕ доступны
    Score* scores; // Массив результатов
    int numScores; // Количество результатов

public:
    Statistics(); // Конструктор класса Statistics.
    ~Statistics(); // Деструктор класса Statistics.

    void viewResults(); // Просмотр результатов тестирования.
    void writeResultsToFile(); // Запись результатов в файл.
};

