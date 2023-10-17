#include "Test_Interface.h"
#include "User_Interface.h"

#include <iostream>


void TestInterface::startTesting() 
{
    loadTests(); //Загрузна тестов

    while (true) 
    {
        displayCategories(); // вывод КАТЕГОРИЙ

        int categoryChoice = getUserChoice(0, categories.size()); // выбор категории пользователя (0 - минимальное значение, categories.size() - максимальное )
        if (categoryChoice == 0) break;

        std::cout << std::endl;
        displaySubCategories(categoryChoice - 1); //вывод подкатегории

        int subCategoryChoice = getUserChoice(0, subCategories[categoryChoice - 1].size()); // выбор поткатегории от пользователя
        if (subCategoryChoice == 0) continue;

        while (true) 
        {
            displayQuestions(categoryChoice - 1, subCategoryChoice - 1); // ВЫВОД ВОПРОСОВ
            
            break;
        }
    }
}



void TestInterface::loadTests() 
{
    //РАЗМЕРЫ ВЕКТОРОВ ТЕКСТОВ (в зависимости от кол во категорий и подкатегорий)
    tests.resize(categories.size()); // изменяет размер вектора tests, что бы в нем было элементы = кол во категорий
    tests[0].resize(subCategories[0].size()); // изменяет размер ВНУТРЕННЕГО/ВЛОЖЕННОГО ВЕКТОРА для категории, элементы = кол во ПОДКАТЕГОРИЙ в категории
  
    // ПЕРВАЯ КАТЕГОРИЯ ПЕРВАЯ ПОДКАТЕГОРИЯ
    // вопрос, варианты ответов и правильный ответ
    tests[0][0].push_back({"Ten horses are participating in a race. How many possible combinations for the top three horses are there?", {"A 100", "B 60", "C 120"}, 'C'});
    tests[0][0].push_back({"In how many ways can 7 different books be arranged on a bookshelf?", {"A 5040", "B 70", "C 2032"}, 'A'});
    tests[0][0].push_back({"There are four identical seats for passengers on a carousel. How many ways are there to seat 4 passengers for a ride?", {"A 24", "B 35", "C 18"}, 'B'});

}

void TestInterface::displayCategories()  // вывод КАТЕГОРИЙ
{
    std::cout << "Select a category (enter the number):" << std::endl;
    for (int i = 0; i < categories.size(); ++i) { std::cout << i + 1 << ". " << categories[i] << std::endl; }
    std::cout << "0. Back" << std::endl;
}

void TestInterface::displaySubCategories(int categoryIndex)  // вывод ПОДКАТЕГОРИИ для категории
{
    std::cout << "Select a subcategory (enter the number):" << std::endl;
    for (int i = 0; i < subCategories[categoryIndex].size(); ++i) { std::cout << i + 1 << ". " << subCategories[categoryIndex][i] << std::endl; }
    std::cout << "0. Back" <<std::endl;
}

void TestInterface::displayQuestions(int categoryIndex, int subCategoryIndex) 
{
    int correctAnswers = 0; // счетчик правильных ответов

    for (const Question& question : tests[categoryIndex][subCategoryIndex]) //ПЕРЕБОР ВОПРОСОВ ДЛЯ ВЫБРАННОЙ КАТЕГОРИИ И ПОДКАТЕГОРИИ
    {
        //диапозон 
        //const Question& question   переменная question константная ссылка на ВЕКТОР (тип элемента ввектора Question)
        // tests[categoryIndex][subCategoryIndex] обращение к ВЕКТОРУ tests 
        //categoryIndex - индект внешнего(КАТЕГОРИЯ)     subCategoryIndex - интекс вложенного, внутреннего вектора (ПОДКАТЕГОРИЯ)
        // ссылка на вопр которая получает категорию и полкатегорию, защет этого получает тесты

        //каждый элемент в ВЕКТОРЕ tests[categoryIndex][subCategoryIndex] последовательно присваивается переменной  question = работа с каждым вопросов внутри цикла 


        std::cout << std::endl;
        std::cout << question.text << std::endl; //выбор текста вопроса

        for (const std::string& option : question.options) { std::cout << option << std::endl; } // вывод вариантов ответа
        //const std::string& option   переменная option константная ссылка на элемент вектора (ТИП ВЕКТОРА std::string)
        //question.options ОБРАЩЕНИЕ К ВЕКТОРУ options ВНУТРИ ОБЬЕКТА questionй!!!!!
        //потому что там строки с вариантами ответов

        std::cout << "Your answer: ";
        char userAnswer;
        std::cin >> userAnswer;

        if (userAnswer == question.correctOption) // проверка ответа
        {
            std::cout << "Correct!" << std::endl;
            ++correctAnswers;
        } else { std::cout << "Incorrect. Correct answer: " << question.correctOption << std::endl; }
    }

    //РЕЗУЛЬТАТЫЫ
    std::cout << std::endl;
    displayResults(categoryIndex, subCategoryIndex, correctAnswers);
}


void TestInterface::displayResults(int categoryIndex, int subCategoryIndex, int correctAnswers) 
{
    int totalQuestions = tests[categoryIndex][subCategoryIndex].size(); // расчет КОЛ ВО вопросов в категории и подкатегории
    double percentCorrect = (double(correctAnswers) / totalQuestions) * 100; // ПРОЦЕНТ

    std::cout << "Results:" << std::endl;
    std::cout << "Correct answers: " << correctAnswers << " out of " << totalQuestions << std::endl;

    std::cout.precision(2); //ДВА ЗНАКА ПОСЛЕ ЗАЯТОЙ для процентов
    std::cout << "Percentage correct: " << std::fixed << percentCorrect << "%" << std::endl;

//итоговый бал (12 быльная система) расчет
    double rawScore = (double(correctAnswers) / totalQuestions) * 12;
    int finalScore = int(rawScore + 0.5); 

    std::cout << "Final Score: " << finalScore << " out of 12" << std::endl;

    std::cout << std::endl;

}


int TestInterface::getUserChoice(int min, int max) // общий метод, для ответов от пользователя
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

void TestInterface::addCategory(Admin& admin) 
{
    std::string categoryName;
    std::cout << "Enter the name of the new category: ";
    std::cin.ignore();
    std::getline(std::cin, categoryName);

    admin.addCategory(categoryName); // передаем введенное имя категории в метод обьекта Админ
    std::cout << "Category added successfully!" << std::endl;
}

void TestInterface::addTestToCategory(Admin& admin) 
{
    std::string categoryName, testName;
    std::cout << "Enter the name of the category: ";
    std::cin.ignore();
    std::getline(std::cin, categoryName);
    std::cout << "Enter the name of the new test: ";
    std::getline(std::cin, testName);

    admin.addTestToCategory(categoryName, testName); // передаем название категории и теста в метод обьекта Админ
    std::cout << "Test added to category successfully!" << std::endl;
}

void TestInterface::addQuestionToTest(Admin& admin) 
{
    std::string categoryName, testName, questionText;
    std::vector<std::string> options; // ВЕКТОР СТРОК ДЛЯ ХРАНЕНИЕ ВАРИКОВ ОТВЕТА
    char correctOption;

    std::cout << "Enter the name of the category: ";
    std::cin.ignore();
    std::getline(std::cin, categoryName);
    std::cout << "Enter the name of the test: ";
    std::getline(std::cin, testName);
    std::cout << "Enter the question text: ";
    std::getline(std::cin, questionText);

    for (int i = 0; i < 4; i++)  // 4 потому что 4 раза вводить
    {
        std::string option;
        std::cout << "Enter option " << i+1 << ": ";
        std::getline(std::cin, option);
        options.push_back(option); // добавляются варианты ответов в ВЕКТОР option
    }

    std::cout << "Enter the correct option (A, B, C, or D): ";
    std::cin >> correctOption;

    admin.addQuestionToTest(categoryName, testName, questionText, options, correctOption); // для параметры для теста
    std::cout << "Question added to test successfully!" << std::endl;
}



std::vector<std::string> TestInterface::getCats() { return categories; }

std::vector<std::vector<std::string>> TestInterface::getSubCats() { return subCategories; }

std::vector<std::vector<std::vector<Question>>> TestInterface::getTest() { return tests; }