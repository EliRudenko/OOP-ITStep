#include "User.h"
#include <iostream>

User User::registeredUsers[maxUsers];
int User::numUsers = 0;

User::User() {}

User::User(const std::string& login, const std::string& encryptedPassword, const std::string& fullName, const std::string& address, const std::string& phone)
    : login(login), encrypted_password(encryptedPassword), full_name(fullName), address(address), phone(phone) {}

void User::register_user() {
    bool isUniqueLogin = false;
    while (!isUniqueLogin) {
        std::string newLogin = getStringFromUser("Enter login: ");

        if (isLoginTaken(newLogin)) {
            std::cout << "This login is already taken. Please choose another one." << std::endl;
        } else {
            isUniqueLogin = true;
            login = newLogin;

            std::cout << "Enter encrypted password: ";
            std::cin >> encrypted_password;
            std::cout << "Enter full name: ";
            std::cin.ignore();
            std::getline(std::cin, full_name);
            std::cout << "Enter address: ";
            std::getline(std::cin, address);
            std::cout << "Enter phone number: ";
            std::cin >> phone;

            registeredUsers[numUsers++] = *this; // Добавляем пользователя в список зарегистрированных
        }
    }
}

bool User::authorize() {
    std::string inputLogin, inputPassword;
    std::cout << "Enter login: ";
    std::cin >> inputLogin;
    std::cout << "Enter encrypted password: ";
    std::cin >> inputPassword;

    return (inputLogin == login && inputPassword == encrypted_password);
}

void User::setLogin(const std::string& newLogin) {
    login = newLogin;
}

int User::getModeFromUser() {
    int mode;
    std::cout << "Select mode (1 - User, 2 - Admin): ";
    std::cin >> mode;
    return mode;
}

std::string User::getStringFromUser(const std::string& message) {
    std::string input;
    std::cout << message;
    std::cin >> input;
    return input;
}

std::string User::getFullName() const {
    return full_name;
}

bool User::isLoginTaken(const std::string& login) {
    for (int i = 0; i < numUsers; ++i) {
        if (registeredUsers[i].login == login) {
            return true;
        }
    }
    return false;
}
