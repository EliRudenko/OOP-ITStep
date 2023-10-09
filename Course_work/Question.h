#pragma once

#include <string>

class Question 
{
private: //(protected)
    std::string questionText; // Текст вопроса
    std::string* answerOptions; // Массив вариантов ответов
    int correctAnswerIndex; // Индекс правильного ответа
    int numOptions; // Количество вариантов ответов

public:
    // Конструктор класса Question, инициализирующий его основные атрибуты.
    Question(const std::string& questionText);

    // Деструктор класса Question, освобождающий память, выделенную под варианты ответов.
    ~Question();

    void addAnswerOption(const std::string& option); // Добавление варианта ответа.
    void removeAnswerOption(int index); // Удаление варианта ответа.
};
