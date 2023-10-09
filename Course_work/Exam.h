#pragma once

#include "Test.h"
#include "Score.h"

class Exam 
{
public:
    virtual void take_test(Test* test) = 0; // Взятие теста (чисто виртуальный метод).
    virtual void calculate_results(Test* test) = 0; // Расчет результатов (чисто виртуальный метод).
    virtual void assign_grade(Score* score) = 0; // Назначение оценки (чисто виртуальный метод).
};


