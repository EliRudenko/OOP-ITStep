#pragma once

#include "Test.h"

class Questionnaire 
{
public:
    virtual void generateQuestions(Test* test) = 0; // Генерация вопросов (чисто виртуальный метод).
};


