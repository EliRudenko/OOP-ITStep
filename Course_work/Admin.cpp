#include "Admin.h"
#include <iostream>

Admin::Admin(const std::string& login, const std::string& encryptedPassword)
    : User(login, encryptedPassword, "", "", "") {}

bool Admin::authorize() {
    std::string inputPassword;
    std::cout << "Enter encrypted password: "; // В реальной программе здесь будет шифрование пароля
    std::cin >> inputPassword;

    return inputPassword == encrypted_password;
}

void Admin::manage_users() {
    std::cout << "User management actions: create, delete, modify." << std::endl;
    // Здесь реализуйте управление пользователями
}

void Admin::view_statistics() {
    std::cout << "View statistics for testing results." << std::endl;
    // Здесь реализуйте просмотр статистики
}

void Admin::manage_testing() {
    std::cout << "Testing management actions: add categories, tests, questions." << std::endl;
    // Здесь реализуйте управление тестированием
}

void Admin::import_export_categories_tests() {
    std::cout << "Import/Export categories and tests from/to a file." << std::endl;
    // Здесь реализуйте импорт и экспорт категорий и тестов
}


bool Admin::authorize_admin(const std::string& inputLogin, const std::string& inputPassword) {
    return (login == inputLogin && encrypted_password == inputPassword);
}

void Admin::change_admin_password(const std::string& newAdminPassword) {
    encrypted_password = newAdminPassword;
}

void Admin::change_admin_login(const std::string& newAdminLogin) {
    login = newAdminLogin;
}