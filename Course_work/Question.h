#pragma once

#include <string>

class Question 
{
private: //(protected)
    std::string question_text; // текст вопроса
    std::string* answer_options; // варианты ответов (массив)
    int correct_answerIndex; // правильный ответ (ИНДЕКС)
    int num_options; //варики ответов, кол во

public:
    Question(const std::string& questionText);
    ~Question();

    void add_answer_option(const std::string& option);
    void del_answer_option(int index);
};
