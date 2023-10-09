#pragma once

#include <string>

class User 
{
protected: // потому что данные будут использоваться в потомках (Admin)
    std::string login;
    std::string encryptedPassword;
    std::string fullName;
    std::string address;
    std::string phone;

public:
    // Конструктор класса User, инициализация
    User(const std::string& login, const std::string& encryptedPassword, const std::string& fullName, const std::string& address, const std::string& phone);

    // Методы для регистрации пользователя и входа
    void registerUser();
    bool authorize();

    // Просмотр результатов и прохождение теста
    virtual void viewResults();
    void takeTest();
};

