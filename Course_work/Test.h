#pragma once

#include <string>
#include "Question.h"

class Test 
{
private: //поля принадлежать только обьектам этого класса, за пределами НЕ доступны
    std::string testName; 
    std::string category; //категория
    Question* questions; // сам массив воппр
    int numQuestions; // кол во 

public:
    Test(const std::string& testName, const std::string& category);
    ~Test();

    void add_question(const Question& question); 
    void remove_question(int index); 
};

