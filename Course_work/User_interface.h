#pragma once

#include "User.h"
#include "Admin.h"

#include <iostream>
#include <vector>

class UserInterface 
{
private:
    User user;
    Admin admin;
    bool isAdmin;

public:
    UserInterface();
    void for_main();

    void handleUserMode();
    void handleAdminMode();
    void chooseActionAfterAuthorization();
    void performAdminActions();
    bool askToExit();

};