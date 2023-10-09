#pragma once

#include <string>

#include "Test.h"

class Category 
{
private: //поля принадлежат только обьектам этого класса, за пределами НЕ доступны
    std::string categoryName; // Название категории
    Test* tests; // Массив тестов
    int numTests; // Количество тестов

public:
    // Конструктор класса Category, инициализирующий его основные атрибуты.
    Category(const std::string& categoryName);

    // Деструктор класса Category, освобождающий память, выделенную под тесты.
    ~Category();

    void addTest(const Test& test); // Добавление теста в категорию.
    void removeTest(int index); // Удаление теста из категории.
};

