#pragma once

class Score 
{
private: //поля принадлежат только обьектам этого класса, за пределами НЕ доступны
    int correct_answers;  
    double percentage; 
    int grade;

public:
    Score(int correctAnswers, double percentage, int grade);

    int get_correct_answers() const;
    double get_percentage() const;
    int get_grade() const;
};


