#pragma once

class UserInterface 
{
public:
    virtual void displayMenu() = 0; // Отображение меню (чисто виртуальный метод).
    virtual void getUserInput() = 0; // Получение ввода пользователя (чисто виртуальный метод).
};


