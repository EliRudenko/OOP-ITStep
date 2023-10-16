#include <iostream>

#include "Admin.h"


Admin::Admin() {}
Admin::Admin(const std::string& login, const std::string& encryptedPassword) : User(login, encryptedPassword, "", "", "") 
{}

bool Admin::authorize() 
{
    std::string inputPassword;
    std::cout << "Enter password: "; 
    std::cin >> inputPassword;

    return inputPassword == password;
}

bool Admin::authorize_admin(const std::string& inputLogin, const std::string& inputPassword) { return (login == inputLogin && password == inputPassword); }

void Admin::change_admin_password(const std::string& newAdminPassword) { password = newAdminPassword; }

void Admin::change_admin_login(const std::string& newAdminLogin) { login = newAdminLogin; }


bool  Admin::isAuthorized() const { return User::isAuthorized(); }


/*
void Admin::manage_users() 
{
    std::cout << "User management actions: create, delete, modify." << std::endl;   
}

void Admin::view_statistics() 
{}

void Admin::manage_testing() 
{
    std::cout << "Testing management actions: add categories, tests, questions." << std::endl;   
}

void Admin::import_export_categories_tests() 
{}
*/


//const std::string& Admin::getEncryptedPassword() const { return User::getEncryptedPassword(); }
//void Admin::setEncryptedPassword(const std::string& newPassword) { User::setEncryptedPassword(newPassword); }

