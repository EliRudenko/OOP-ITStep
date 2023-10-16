#include <iostream>

#include "Admin.h"


Admin::Admin() {}
Admin::Admin(const std::string& login, const std::string& encryptedPassword) : User(login, encryptedPassword, "", "", "") {} //+ конструктор базового класса User с параметрами


//ВХОД!!!______________
bool Admin::authorize() 
{
    std::string inputLogin = getStringFromUser("Enter login: ");
    std::string inputPassword = getStringFromUser("Enter password: ");

    return (inputLogin == login && inputPassword == password); // возвращает true если СОВПОДАЮТ (логин пароль)
}

bool Admin::authorize_admin(const std::string& inputLogin, const std::string& inputPassword) 
{
    return (login == inputLogin && password == inputPassword);
}

bool  Admin::isAuthorized() const { return User::isAuthorized(); } //возвращает РЕЗУЛЬТАТ МЕТОДА класса User


void Admin::change_admin_password(const std::string& newAdminPassword) { password = newAdminPassword; } // МЕНЯЕМ пароль

void Admin::change_admin_login(const std::string& newAdminLogin) { login = newAdminLogin; } // МЕНЯЕМ логин


//РЕГИСТРАЦИЯ через админа(такой же метод +/-)
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

            User newUser(newLogin, newPassword, newFullName, newAddress, newPhone);// создается новый пользователь
            registeredUsers.push_back(newUser); // ДОБАВЛЯЕМ ЕГО В СПИСОК ПОЛЬЗОВАТЕЛЬ = зареган

            std::cout << "User " << newLogin << " has been created." << std::endl;
        }
    }
}


//ДЛЯ ТЕСТОВ


void Admin::addCategory(const std::string& categoryName) 
{
    auto categoryExists = std::find(categories.begin(), categories.end(), categoryName); // есть ли такая категория
    //ПОИСКТ элемента categoryName в ВЕКТООРЕ categories

    //categories.begin() начало векетора 
    //categories.end() конец вектора

    //std::find ищет значение в этом диапазоне если нашла ВОЗВРАЩАЕТ ИТЕРАТОР(указывает на элемент который нашли)
    //если не нашла - вовращает ИТЕРАТОР на categories.end()


    if (categoryExists == categories.end()) //категории НЕт
    {
        categories.push_back(categoryName); //ДОБАВЛЯЕМ НОВУЮ категорию
        tests.push_back({});  //!!!!ПУСТОЙ ВЕКТОР ДЛЯ ТЕСТА КАТЕГОРИИ
        std::cout << "Category '" << categoryName << "' added successfully!" << std::endl;
    } 
    else { std::cout << "Category '" << categoryName << "' already exists!" << std::endl; }
}

void Admin::addTestToCategory(const std::string& categoryName, const std::string& testName) 
{
    auto categoryExists = std::find(categories.begin(), categories.end(), categoryName); // есть ли категория, так же как в методе выше

    if (categoryExists != categories.end()) // категория ЕСТЬ
    {
        int categoryIndex = categoryExists - categories.begin(); //ИНДЕКС КАТЕГОРИИ В ВЕКТОРЕ КАТЕГОРИЙ
        auto& testsInCategory = tests[categoryIndex]; // ССЫЛКА НА ВЕКТОР ТЕСТОВ КАТЕГОРИИ
       
        auto testExists = std::find(testsInCategory.begin(), testsInCategory.end(), testName); //Есть ли этот тест 
        if (testExists == testsInCategory.end()) // теста НЕТ
        {
            testsInCategory.push_back(testName); // ДОБАВЛЯЕМ НОВЫЙ текст к категории
            std::cout << "Test '" << testName << "' added to category '" << categoryName << "' successfully!" << std::endl;
        } 
        else { std::cout << "Test '" << testName << "' already exists in category '" << categoryName << "'!" << std::endl; }
    } 
    else { std::cout << "Category '" << categoryName << "' does not exist!" << std::endl; }
}

void Admin::addQuestionToTest(const std::string& categoryName, const std::string& testName, const std::string& questionText, const std::vector<std::string>& options, char correctOption) 
{
    auto categoryExists = std::find(categories.begin(), categories.end(), categoryName); // есть ли категория
    if (categoryExists != categories.end()) // категория ЕСТЬ
    {
        int categoryIndex = categoryExists - categories.begin(); //поиск ИНДЕКСА категории в ВЕКТОРЕ категорий
        auto& testsInCategory = tests[categoryIndex]; //ССЫЛКА НА ВЕКТОР ТЕСТОВ КАТЕГОРИИ

        auto testExists = std::find(testsInCategory.begin(), testsInCategory.end(), testName); // есть ли тест 
        
        if (testExists != testsInCategory.end()) // тест ЕСТЬ
        {
            Question_for_actions newQuestion = {questionText, options, correctOption}; //СОЗДАНИЕ НОВОГО ВОПРОСА
            std::cout << "Question added to test '" << testName << "' in category '" << categoryName << "' successfully!" << std::endl;
        } 
        else { std::cout << "Test '" << testName << "' does not exist in category '" << categoryName << "'!" << std::endl; }

    } else { std::cout << "Category '" << categoryName << "' does not exist!" << std::endl; }
}

bool Admin::areNewCategoriesAdded() {  return !categories.empty(); } //ЕСЛИ ВЕКТОР КАТЕГОРИЙ НЕЕЕ ПУСТОЙ

bool Admin::areNewTestsAdded() { return !tests.empty(); } // ЕСЛИ ВЕКТОР ТЕСТОВ НЕЕЕ ПУСТОЙ



