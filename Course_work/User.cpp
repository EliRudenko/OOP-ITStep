#include <iostream>

#include "User.h"


User User::registeredUsers[maxUsers];
int User::numUsers = 0;

User::User() {}

User::User(const std::string& login, const std::string& password, const std::string& fullName, const std::string& address, const std::string& phone) : login(login), password(password), full_name(fullName), address(address), phone(phone) {}

std::string User::getStringFromUser(const std::string& message) 
{
    std::string input;
    std::cout << message;
    std::cin >> input;
    return input;
}

int User::getModeFromUser() 
{
    int mode;
    std::cout << "Select mode (1 - User, 2 - Admin): ";
    std::cin >> mode;
    return mode;
}

void User::register_user() 
{
    bool isUniqueLogin = false;

    while (!isUniqueLogin) 
    {
        std::string newLogin = getStringFromUser("Enter login: ");

        if (isLoginTaken(newLogin)) 
        {
            std::cout << "This login is already taken. Please choose another one." << std::endl;
        } 
        else
        {
            isUniqueLogin = true;
            login = newLogin;
            
            password = getStringFromUser("Enter password: ");

            std::cout << "Enter full name: ";
            std::cin.ignore();
            std::getline(std::cin, full_name);
            std::cout << "Enter address: ";
            std::getline(std::cin, address);
            
            phone = getStringFromUser("Enter phone number: ");

/*
            password = getStringFromUser("Enter password: ");
            std::cin.ignore(); // Очистка буфера после cin
            full_name = getStringFromUser("Enter full name: ");
            std::cin.ignore(); // Очистка буфера после cin
            address = getStringFromUser("Enter address: ");
            phone = getStringFromUser("Enter phone number: ");
*/
            registeredUsers[numUsers++] = *this; // Добавляем пользователя в список зареганых
        }
    }
}

std::string User::getFullName() const { return full_name; }

bool User::authorize() 
{
    std::string inputLogin = getStringFromUser("Enter login: ");
    std::string inputPassword = getStringFromUser("Enter password: ");

    return (inputLogin == login && inputPassword == password);
}

bool User::isAuthorized() const { return !login.empty() && !password.empty(); }

void User::setLogin(const std::string& newLogin) { login = newLogin; }

bool User::isLoginTaken(const std::string& login) 
{
    for (int i = 0; i < numUsers; ++i) 
    {
        if (registeredUsers[i].login == login) {  return true; }
    }
    return false;
}


const std::string& User::getPassword() const { return password; }

void User::setPassword(const std::string& newPassword) { password = newPassword; }
