#pragma once

#include <string>

class User 
{
protected: // потому что данные будут использоваться в потомках (Admin)
    std::string login;
    std::string encrypted_password;
    std::string full_name;
    std::string address;
    std::string phone;

public:
    // Конструктор класса User, инициализация
    User(const std::string& login, const std::string& encryptedPassword, const std::string& fullName, const std::string& address, const std::string& phone);

    //для регистрации пользователя и входа
    void register_user();
    bool authorize();

    //просмотр результатов и прохождение теста
    virtual void print_results();
    void take_test();

//?
    static int getModeFromUser(); // Добавленный метод для выбора режима
    static std::string getStringFromUser(const std::string& message);
};



