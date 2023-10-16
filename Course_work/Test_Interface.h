#pragma once

#include <vector>
#include <string>

#include "User.h"


struct Question 
{
    std::string text;
    std::vector<std::string> options;
    char correctOption;
};

class TestInterface 
{
private:
    
    std::vector<std::string> categories = {"Maths", "Physics"};
    std::vector<std::vector<std::string>> subCategories = {{"Combinatorics", "Mathematical analysis"}, {"Quantum physics", "Mechanics"}};
    std::vector<std::vector<std::vector<Question>>> tests;

public:

    void startTesting(); 

    void loadTests();

    void displayCategories();
    void displaySubCategories(int categoryIndex);
    void displayQuestions(int categoryIndex, int subCategoryIndex);
    void displayResults(int categoryIndex, int subCategoryIndex, int correctAnswers);

    int getUserChoice(int min, int max);

    void addCategory(Admin& admin);
    void addTestToCategory(Admin& admin);
    void addQuestionToTest(Admin& admin);


    std::vector<Question> getQuestionsForTest(int categoryIndex, int subCategoryIndex) 
    {
        return tests[categoryIndex][subCategoryIndex];
    }

    std::vector<std::string> getCats();
    std::vector<std::vector<std::string>> getSubCats();
    std::vector<std::vector<std::vector<Question>>> getTest();

};

