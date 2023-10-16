#include "Test_Interface.h"
#include "User_Interface.h"

#include <iostream>


void TestInterface::startTesting() 
{
    loadTests();

    while (true) 
    {
        displayCategories();

        int categoryChoice = getUserChoice(0, categories.size());
        if (categoryChoice == 0) break;

        std::cout << std::endl;
        displaySubCategories(categoryChoice - 1);

        int subCategoryChoice = getUserChoice(0, subCategories[categoryChoice - 1].size());
        if (subCategoryChoice == 0) continue;

        while (true) 
        {
            displayQuestions(categoryChoice - 1, subCategoryChoice - 1);
            
            break;
        }
    }
}



void TestInterface::loadTests() 
{
    tests.resize(categories.size());
    tests[0].resize(subCategories[0].size());

    tests[0][0].push_back({"Ten horses are participating in a race. How many possible combinations for the top three horses are there?", {"A 100", "B 60", "C 120"}, 'C'});
    tests[0][0].push_back({"In how many ways can 7 different books be arranged on a bookshelf?", {"A 5040", "B 70", "C 2032"}, 'A'});
    tests[0][0].push_back({"There are four identical seats for passengers on a carousel. How many ways are there to seat 4 passengers for a ride?", {"A 24", "B 35", "C 18"}, 'B'});

}

void TestInterface::displayCategories() 
{
    std::cout << "Select a category (enter the number):" << std::endl;
    for (size_t i = 0; i < categories.size(); ++i) { std::cout << i + 1 << ". " << categories[i] << std::endl; }
    std::cout << "0. Back" << std::endl;
}

void TestInterface::displaySubCategories(int categoryIndex) 
{
    std::cout << "Select a subcategory (enter the number):" << std::endl;
    for (size_t i = 0; i < subCategories[categoryIndex].size(); ++i) { std::cout << i + 1 << ". " << subCategories[categoryIndex][i] << std::endl; }
    std::cout << "0. Back" <<std::endl;
}

void TestInterface::displayQuestions(int categoryIndex, int subCategoryIndex) 
{
    int correctAnswers = 0;

    for (const Question& question : tests[categoryIndex][subCategoryIndex]) 
    {
        std::cout << std::endl;
        std::cout << question.text << std::endl;

        for (const std::string& option : question.options) { std::cout << option << std::endl; }

        std::cout << "Your answer: ";
        char userAnswer;
        std::cin >> userAnswer;

        if (userAnswer == question.correctOption) 
        {
            std::cout << "Correct!" << std::endl;
            ++correctAnswers;
        } else { std::cout << "Incorrect. Correct answer: " << question.correctOption << std::endl; }
    }

    std::cout << std::endl;
    displayResults(categoryIndex, subCategoryIndex, correctAnswers);
}


void TestInterface::displayResults(int categoryIndex, int subCategoryIndex, int correctAnswers) 
{
    int totalQuestions = tests[categoryIndex][subCategoryIndex].size();
    double percentCorrect = (double(correctAnswers) / totalQuestions) * 100;

    std::cout << "Results:" << std::endl;
    std::cout << "Correct answers: " << correctAnswers << " out of " << totalQuestions << std::endl;

    // два знака после запятой
    std::cout.precision(2); 
    std::cout << "Percentage correct: " << std::fixed << percentCorrect << "%" << std::endl;

    double rawScore = (double(correctAnswers) / totalQuestions) * 12;
    int finalScore = int(rawScore + 0.5); 

    std::cout << "Final Score: " << finalScore << " out of 12" << std::endl;

    std::cout << std::endl;
}



int TestInterface::getUserChoice(int min, int max) 
{
    int choice;
    while (true) 
    {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (choice >= min && choice <= max) { return choice; }

        std::cout << "Incorrect input. Please try again: ";
        std::cin.clear();
        while (std::cin.get() != '\n') {}
    }
    return -1; 
}

