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















/*
Admin::Admin(const std::string& login, const std::string& encryptedPassword) : User(login, encryptedPassword, "", "", "") 
{}
/*
bool Admin::authorize() 
{
    std::string inputPassword;
    std::cout << "Enter encrypted password: "; 
    std::cin >> inputPassword;

    return (inputPassword == Security::decrypt_password(encrypted_password));
}
*/

/*
bool Admin::authorize() 
{
    std::string inputLogin, inputPassword;
    std::cout << "Enter admin login: ";
    std::cin >> inputLogin;
    std::cout << "Enter admin encrypted password: "; // В реальной программе здесь будет шифрование пароля
    std::cin >> inputPassword;

    return (inputLogin == login && inputPassword == Security::decrypt_password(encrypted_password));
}

bool Admin::authorize_admin(const std::string& inputLogin, const std::string& inputPassword) {
    std::string decryptedPassword = Security::decrypt_password(inputPassword);
    return (inputLogin == login && decryptedPassword == encrypted_password);
}
*/


/*
void Admin::manage_users() 
{
    std::cout << "User management actions: create, delete, modify." << std::endl;
    
}

void Admin::view_statistics() 
{
    std::cout << "View statistics for testing results." << std::endl;
   
}

void Admin::manage_testing() 
{
    std::cout << "Testing management actions: add categories, tests, questions." << std::endl;
    
}

void Admin::import_export_categories_tests() 
{
    std::cout << "Import/Export categories and tests from/to a file." << std::endl;
    
}
*/


//void Admin::change_admin_password(const std::string& newAdminPassword) { encrypted_password = newAdminPassword; }

/*
void Admin::change_admin_password(const std::string& newPassword) { User::setEncryptedPassword(newPassword); }


void Admin::change_admin_login(const std::string& newAdminLogin) { login = newAdminLogin; }



bool  Admin::isAuthorized() const { return User::isAuthorized(); }

const std::string& Admin::getEncryptedPassword() const { return User::getEncryptedPassword(); }

void Admin::setEncryptedPassword(const std::string& newPassword) { User::setEncryptedPassword(newPassword); }

*/


