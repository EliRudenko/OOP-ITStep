
/*
#pragma once

#include "User.h"

class UserInterface 
{
public:
    virtual void print_menu() = 0; 
    virtual void get_userInput() = 0;
};
*/

#pragma once

#include "User.h"
#include "Admin.h"

class UserInterface 
{
private:
    User user;
    Admin admin;
    bool isAdmin;

public:
    void for_main();

    void handleUserMode();

    void handleAdminMode();
    void performAdminActions();

    bool askToExit();
    
};




