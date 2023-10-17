#pragma once

#include <string>
#include <vector>
//registeredUsers - для ХРАНЕНИЯ ПОЛЬЗОВАТЕЛЕЙ (+динам память под эти обьекты)
//registeredUsers.push_back(*this); ДОБАВЛЯЕТ обьект User в КОНЕЦ вектора = регистрация

//Юзер сзязан с тестами чисто методами (самостоятельные классы, не щависят ни от кого)


class User 
{
protected:
    static const int maxUsers = 100; // максимальное количество пользователей
    static std::vector<User> registeredUsers; //ЗАРЕГИСТРИРОВАННЫЕ пользователи

//инфа для регистрации и тп
    std::string login;
    std::string password;
    std::string full_name;
    std::string address;
    std::string phone;

    int finalScore;// итоговый бал

public:
    User();
    User(const std::string& login, const std::string& password, const std::string& fullName, const std::string& address, const std::string& phone);

    static std::string getStringFromUser(const std::string& message); //строка от пользователя

    static int getModeFromUser(); // РЕЖИМ (Пользователь или Админ)

    void register_user(); // РЕГИСТРАЦИЯ

    //ПРОВЕРКА провильности ввода
    bool validateEmail(const std::string& email);
    bool validatePhoneNumber(const std::string& phoneNumber);

    bool authorize(); // ВХОД
    void setLogin(const std::string& newLogin); // установка Логина

    std::string getFullName() const; // получение полного имени
    std::string getLogin() const; // получение логина

//ПРОВЕРКА занят/не занят логин
    static bool isLoginTaken(const std::string& login);
//ПРОВЕРКА авторизировался ли пользователь
    bool isAuthorized() const;

    void setPassword(const std::string& newPassword); // установка пароля
    const std::string& getPassword() const; //получение пароля


    void delete_user(const std::string& login); // УДАЛЕНИЕ

    int getFinalScore() const; //результат
};