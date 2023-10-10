#pragma once

#include "Test.h"
#include "Category.h"

class ExamManager 
{
public:
    void manageTests(Category* category); // Управление тестами.
    void addCategory(Category* category); // Добавление категории.
    void removeCategory(Category* category); // Удаление категории.
    void addTest(Test* test, Category* category); // Добавление теста.
    void removeTest(Test* test, Category* category); // Удаление теста.
    void addQuestion(Question* question, Test* test); // Добавление вопроса.
    void removeQuestion(Question* question, Test* test); // Удаление вопроса.
    void interruptTesting(Test* test); // Прерывание тестирования.
    void continueTesting(Test* test); // Продолжение тестирования.
}; 


/*
#include "Score.h"

    virtual void manageTests(Test* test) = 0;
    virtual void addCategory(Category* category) = 0;
    virtual void removeCategory(Category* category) = 0;
    virtual void addTest(Test* test, Category* category) = 0;
    virtual void removeTest(Test* test, Category* category) = 0;
    virtual void addQuestion(Question* question, Test* test) = 0;
    virtual void removeQuestion(Question* question, Test* test) = 0;
    virtual void interruptTesting(Test* test) = 0;
    virtual void continueTesting(Test* test) = 0;

*/
