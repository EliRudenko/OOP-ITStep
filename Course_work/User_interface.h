#pragma once

#include "User.h"

class UserInterface 
{
public:
    virtual void print_menu() = 0; // oтображение меню (чисто виртуальный метод)
    virtual void get_userInput() = 0; // ввод пользователя (чисто виртуальный метод)
};




