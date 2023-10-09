#pragma once

#include "Test.h"
#include "Score.h"

class Exam 
{
public:
    virtual void takeTest(Test* test) = 0; // Взятие теста (чисто виртуальный метод).
    virtual void calculateResults(Test* test) = 0; // Расчет результатов (чисто виртуальный метод).
    virtual void assignGrade(Score* score) = 0; // Назначение оценки (чисто виртуальный метод).
};


