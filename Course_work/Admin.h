#pragma once

#include <string>

#include "User.h"

class Admin : public User 
{
public:
    // Конструктор класса Admin, унаследованный от User, добавляющий
    // дополнительные атрибуты и методы администратора.
    Admin(const std::string& login, const std::string& encryptedPassword);

    bool authorize(); // Переопределение метода авторизации для администратора.
    void manage_users(); // Управление пользователями.
    void view_statistics(); // Просмотр статистики результатов тестирования.

    void manage_testing();
    void import_export_categories_tests();

    bool authorize_admin(const std::string& inputLogin, const std::string& inputPassword);
    void change_admin_password(const std::string& newAdminPassword);
    void change_admin_login(const std::string& newAdminLogin);
};
