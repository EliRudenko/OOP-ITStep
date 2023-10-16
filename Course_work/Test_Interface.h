#pragma once

#include <vector>
#include <string>

#include "User.h"


struct Question 
{
    std::string text; // текст вопроса
    std::vector<std::string> options; //выотанты ответов
    char correctOption; // правильные варики
};

class TestInterface 
{
private:
    
    std::vector<std::string> categories = {"Maths", "Physics"}; // ВЕКТОР КАТЕГОРИЙ
    std::vector<std::vector<std::string>> subCategories = {{"Combinatorics", "Mathematical analysis"}, {"Quantum physics", "Mechanics"}}; // ВЕКТОР ПОДКАТЕГОРИЙ
    std::vector<std::vector<std::vector<Question>>> tests; //ВЕКТОР ТЕСТОВ состоит из:
    // 1 std::vector<std::vector<Question>> КАТЕГОРИЯ
    // 2 std::vector<Question> ПОДКАТЕГОРИИ ТЕСТОВ  внутри каждой категории
    // 3 std::vector<Question> ВОПРОСЫ внутри каждой подкатегории

public:

    void startTesting(); // ЗАПУСК ТЕСТИРОВАНИЯ

    void loadTests(); // запуск ТЕСТОВ

    void displayCategories(); //вывод КАТЕГОРИЙ
    void displaySubCategories(int categoryIndex); // вывод ПОДКАТЕГОРИЙ
    void displayQuestions(int categoryIndex, int subCategoryIndex); // вывод ВОПРОСОВ

    void displayResults(int categoryIndex, int subCategoryIndex, int correctAnswers); // РЕЗУЛЬТАТЫ

    int getUserChoice(int min, int max); 

    void addCategory(Admin& admin); // ДОБАВИТЬ категорию теста
    void addTestToCategory(Admin& admin); // ДОБАВИТЬ подкатегорию теста 
    void addQuestionToTest(Admin& admin); // ДОБАВИТЬ вопрос 


    std::vector<Question> getQuestionsForTest(int categoryIndex, int subCategoryIndex) 
    {
        return tests[categoryIndex][subCategoryIndex]; // получение вопроса для теста
    }
 
    std::vector<std::string> getCats(); // получение КАТЕГОРИИ
    std::vector<std::vector<std::string>> getSubCats(); // получение ПОДКАТЕГОРИИ
    std::vector<std::vector<std::vector<Question>>> getTest(); // получении ТЕСТА

};

