#pragma once

#include "User.h"

class UserInterface 
{
public:
    virtual void print_menu() = 0; 
    virtual void get_userInput() = 0;
};




