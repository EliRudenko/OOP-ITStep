#pragma once

#include "Test.h"
#include "Score.h"

class Exam 
{
public:
    virtual void take_test(Test* test) = 0; // сам теста (чисто виртуал)
    virtual void calculate_results(Test* test) = 0; // Результаты (чисто виртуал)
    virtual void assign_grade(Score* score) = 0; // Оценка(чисто виртуал)
};


