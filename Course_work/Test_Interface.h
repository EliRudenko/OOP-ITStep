#pragma once

#include <vector>
#include <string>


struct Question 
{
    std::string text;
    std::vector<std::string> options;
    char correctOption;
};

class TestInterface 
{
public:

    void startTesting(); // void

    std::vector<std::string> categories = {"Maths", "Physics"};
    std::vector<std::vector<std::string>> subCategories = {{"Combinatorics", "Mathematical analysis"}, {"Quantum physics", "Mechanics"}};
    std::vector<std::vector<std::vector<Question>>> tests;

    void loadTests();
    void displayCategories();
    void displaySubCategories(int categoryIndex);
    void displayQuestions(int categoryIndex, int subCategoryIndex);
    void displayResults(int categoryIndex, int subCategoryIndex, int correctAnswers);
    int getUserChoice(int min, int max);

};


