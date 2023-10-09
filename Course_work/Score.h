#pragma once

class Score 
{
private: //поля принадлежат только обьектам этого класса, за пределами НЕ доступны
    int correctAnswers; // Количество правильных ответов
    double percentage; // Процент правильных ответов
    int grade; // Оценка

public:
    // Конструктор класса Score, инициализирующий его атрибуты.
    Score(int correctAnswers, double percentage, int grade);

    // Геттеры для атрибутов.
    int getCorrectAnswers() const;
    double getPercentage() const;
    int getGrade() const;
};

