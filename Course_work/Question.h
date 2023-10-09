#pragma once

#include <string>

class Question 
{
private: //(protected)
    std::string question_text; // Текст вопроса
    std::string* answer_options; // Массив вариантов ответов
    int correct_answerIndex; // Индекс правильного ответа
    int num_options; // Количество вариантов ответов

public:
    // Конструктор класса Question, инициализирующий его основные атрибуты.
    Question(const std::string& questionText);

    // Деструктор класса Question, освобождающий память, выделенную под варианты ответов.
    ~Question();

    void add_answer_option(const std::string& option); // Добавление варианта ответа.
    void del_answer_option(int index); // Удаление варианта ответа.
};
