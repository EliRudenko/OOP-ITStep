#include <iostream>
//#include <fstream>

#include "Admin.h"


Admin::Admin() {}
Admin::Admin(const std::string& login, const std::string& encryptedPassword) : User(login, encryptedPassword, "", "", "") {}


//ВХОД!!!______________
bool Admin::authorize() 
{
    std::string inputLogin = getStringFromUser("Enter login: ");
    std::string inputPassword = getStringFromUser("Enter password: ");

    return (inputLogin == login && inputPassword == password); // возвращает true
}

bool Admin::authorize_admin(const std::string& inputLogin, const std::string& inputPassword) 
{
    return (login == inputLogin && password == inputPassword);
}

bool  Admin::isAuthorized() const { return User::isAuthorized(); }



void Admin::change_admin_password(const std::string& newAdminPassword) { password = newAdminPassword; }

void Admin::change_admin_login(const std::string& newAdminLogin) { login = newAdminLogin; }



void Admin::create_user() 
{
    bool isUniqueLogin = false;

    while (!isUniqueLogin) 
    {
        std::string newLogin = getStringFromUser("Enter login for the new user: ");

        if (isLoginTaken(newLogin)) 
        {
            std::cout << "This login is already taken. Please choose another one." << std::endl;
        } 
        else 
        {
            isUniqueLogin = true;
            std::string newPassword = getStringFromUser("Enter password for the new user: ");
            std::string newFullName = getStringFromUser("Enter full name for the new user: ");
            std::string newAddress = getStringFromUser("Enter address for the new user: ");
            std::string newPhone = getStringFromUser("Enter phone number for the new user: ");

            User newUser(newLogin, newPassword, newFullName, newAddress, newPhone);
            registeredUsers.push_back(newUser);

            std::cout << "User " << newLogin << " has been created." << std::endl;
        }
    }
}




void Admin::addCategory(const std::string& categoryName) 
{
    auto categoryExists = std::find(categories.begin(), categories.end(), categoryName);
    if (categoryExists == categories.end()) 
    {
        categories.push_back(categoryName);
        tests.push_back({}); 
        std::cout << "Category '" << categoryName << "' added successfully!" << std::endl;
    } 
    else { std::cout << "Category '" << categoryName << "' already exists!" << std::endl; }
}

void Admin::addTestToCategory(const std::string& categoryName, const std::string& testName) 
{
    auto categoryExists = std::find(categories.begin(), categories.end(), categoryName);
    if (categoryExists != categories.end()) 
    {
        int categoryIndex = categoryExists - categories.begin();
        auto& testsInCategory = tests[categoryIndex];
        auto testExists = std::find(testsInCategory.begin(), testsInCategory.end(), testName);
        if (testExists == testsInCategory.end()) 
        {
            testsInCategory.push_back(testName);
            std::cout << "Test '" << testName << "' added to category '" << categoryName << "' successfully!" << std::endl;
        } 
        else { std::cout << "Test '" << testName << "' already exists in category '" << categoryName << "'!" << std::endl; }
    } 
    else { std::cout << "Category '" << categoryName << "' does not exist!" << std::endl; }
}

void Admin::addQuestionToTest(const std::string& categoryName, const std::string& testName, const std::string& questionText, const std::vector<std::string>& options, char correctOption) 
{
    auto categoryExists = std::find(categories.begin(), categories.end(), categoryName);
    if (categoryExists != categories.end()) 
    {
        int categoryIndex = categoryExists - categories.begin();
        auto& testsInCategory = tests[categoryIndex];
        auto testExists = std::find(testsInCategory.begin(), testsInCategory.end(), testName);
        
        if (testExists != testsInCategory.end()) 
        {
            Question_for_actions newQuestion = {questionText, options, correctOption};
            std::cout << "Question added to test '" << testName << "' in category '" << categoryName << "' successfully!" << std::endl;
        } 
        else { std::cout << "Test '" << testName << "' does not exist in category '" << categoryName << "'!" << std::endl; }

    } else { std::cout << "Category '" << categoryName << "' does not exist!" << std::endl; }
}

bool Admin::areNewCategoriesAdded() {  return !categories.empty(); }

bool Admin::areNewTestsAdded() { return !tests.empty(); }



