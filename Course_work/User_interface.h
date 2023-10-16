#pragma once

#include "User.h"
#include "Admin.h"

#include <iostream>
#include <vector>


class UserInterface 
{
private:
    static std::vector<User> registeredUsers; 
    static Admin admin;
    static bool isAdmin;

public:
    static void for_main();
    static void handleUserMode();
    static void handleAdminMode();
    static void chooseActionAfterAuthorization();
    static void performAdminActions();
    static bool askToExit();
};

