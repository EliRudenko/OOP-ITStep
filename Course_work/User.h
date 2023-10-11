#pragma once

#include <string>

class User 
{
protected:// потому что данные будут использоваться в потомках (Admin)
    static const int maxUsers = 100;
    static User registeredUsers[maxUsers];
    static int numUsers;

    std::string login;
    std::string encrypted_password;
    std::string full_name;
    std::string address;
    std::string phone;

public:
    User();
    User(const std::string& login, const std::string& encryptedPassword, const std::string& fullName, const std::string& address, const std::string& phone);

    void register_user();
    bool authorize();
    void setLogin(const std::string& newLogin);

    static int getModeFromUser();
    static std::string getStringFromUser(const std::string& message);
    std::string getFullName() const;
    static bool isLoginTaken(const std::string& login);

    bool isAuthorized() const;
    const std::string& getEncryptedPassword() const;
    void setEncryptedPassword(const std::string& newPassword);

};
