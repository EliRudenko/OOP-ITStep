#pragma once

#include <string>

#include "Question.h"

class Test 
{
private: //поля принадлежать только обьектам этого класса, за пределами НЕ доступны
    std::string testName; // Название теста
    std::string category; // Категория теста
    Question* questions; // Массив вопросов
    int numQuestions; // Количество вопросов

public:
    // Конструктор класса Test, инициализирующий его основные атрибуты.
    Test(const std::string& testName, const std::string& category);

    // Деструктор класса Test, освобождающий память, выделенную под вопросы.
    ~Test();

    void add_question(const Question& question); // Добавление вопроса в тест.
    void remove_question(int index); // Удаление вопроса из теста.
};

