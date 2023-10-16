#pragma once

#include <string>

#include "User.h"


//для ВОПРОСА и вариков ОТВЕТА
//функция addQuestionToTest использует этот класс, создает новый обьект, передан текст вопр и вварики ответа
class Question_for_actions 
{
public:
    std::string text; //текст вопроса
    std::vector<std::string> options; // ВАРИКИ ОТВЕТОВ
    char correctOption;// правильный ответ

    Question_for_actions(const std::string& t, const std::vector<std::string>& o, char c) : text(t), options(o), correctOption(c) {}
};


class Admin : public User //НАСЛЕДОВАНИЕ
{
    std::vector<std::string> categories; //ВЕКТОР категорий   пнеременная, вектор строк, хранит название КАТЕГОРИЙ тесетов
    std::vector<std::vector<std::string>> tests; // ВЕКТОР текстов, КАЖДЫЙ текст = ВЕКТОР строки
    //вложенный, внутренний Вектор хранит ТЕКСТ
    //внешний хранит ТЕСТЫ
    //=> тесты типо входят в категории, якобы сгруппировали 
    //пример (то что тут в коде) categories - Мат, tests  - каждый элемент ВЕКТОР ТЕСТА, это йкатегории
public:

    Admin();
    Admin(const std::string& login, const std::string& encryptedPassword);

//ВХОД
    bool authorize();
    bool authorize_admin(const std::string& inputLogin, const std::string& inputPassword);// вход с логином и паролем
//ПРОВЕРКА, вошел ли админ
    bool isAuthorized() const;

//ФУНКЦИОНАЛ АДМИНА

    void change_admin_password(const std::string& newAdminPassword); // ИЗМЕНЕНИЕ пароля
    void change_admin_login(const std::string& newAdminLogin); // ИЗМЕНЕНИЕ логина

    void create_user(); // создание пользователя через админа, ТОЖЕ САМОЕ ЧТО И РЕГИСТРАЦИЯ В User

    //для ТЕСТОВ
    void addCategory(const std::string& categoryName); // +категория
    void addTestToCategory(const std::string& categoryName, const std::string& testName); // +тест
    void addQuestionToTest(const std::string& categoryName, const std::string& testName, const std::string& questionText, const std::vector<std::string>& options, char correctOption); // +вопр

    std::vector<std::string> getCategories() const {  return categories;} // получаем список категорий

    //ПРОВЕРКИ
    bool areNewCategoriesAdded(); // добавлены новые категории через админа ?
    bool areNewTestsAdded(); // добавлены новые тесты через админра?

};
