#pragma once

#include "Test.h"
#include "Category.h"

class ExamManager 
{
public:
    void manageTests(Category* category); 
    void addCategory(Category* category); 
    void removeCategory(Category* category); 
    void addTest(Test* test, Category* category); 
    void removeTest(Test* test, Category* category);
    void addQuestion(Question* question, Test* test); 
    void removeQuestion(Question* question, Test* test); 
    void interruptTesting(Test* test);
    void continueTesting(Test* test); 
}; 
