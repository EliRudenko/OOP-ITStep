#pragma once

#include "Score.h"

class Statistics 
{
private: //поля принадлежат только обьектам этого класса, за пределами НЕ доступны
    Score* scores; // результаты (МАССИВ)
    int num_scores; // кол во

public:
    Statistics(); 
    ~Statistics();

    void print_results(); 
    void write_results_To_file(); 
};


