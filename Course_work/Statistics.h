#pragma once

#include "Score.h"

class Statistics 
{
private: //поля принадлежат только обьектам этого класса, за пределами НЕ доступны
    Score* scores; // Массив результатов
    int num_scores; // Количество результатов

public:
    Statistics(); // Конструктор класса Statistics.
    ~Statistics(); // Деструктор класса Statistics.

    void print_results(); // Просмотр результатов тестирования.
    void write_results_To_file(); // Запись результатов в файл.
};


