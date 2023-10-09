#pragma once

class Score 
{
private: //поля принадлежат только обьектам этого класса, за пределами НЕ доступны
    int correct_answers; // Количество правильных ответов
    double percentage; // Процент правильных ответов
    int grade; // Оценка

public:
    // Конструктор класса Score, инициализирующий его атрибуты.
    Score(int correctAnswers, double percentage, int grade);

    // Геттеры для атрибутов.
    int get_correct_answers() const;
    double get_percentage() const;
    int get_grade() const;
};


