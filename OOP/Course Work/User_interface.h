#pragma once

#include "User.h"
#include "Admin.h"

#include <iostream>
#include <vector>


class UserInterface 
{
private:
    static std::vector<User> registeredUsers;  //ВЕКТОР ДЛЯ ХРАНЕНИЕ ЗАРЕГАНЫХ ПОЛЬЗОВАТЕЛЕЙ
    static Admin admin; // обьекто класса Admin, так как есть функционал для админа
    static bool isAdmin; // зашел как админ?

public:
    static void for_main(); // база)
    static void handleUserMode(); // ПОЛЬЗОВАТЕЛЬ
    static void handleAdminMode(); // АДМИН
    static void chooseActionAfterAuthorization(); // действия ПОСЛЕ входа
    static void performAdminActions(); // особые функции АДМИНА
    static bool askToExit(); // до побачення
};

