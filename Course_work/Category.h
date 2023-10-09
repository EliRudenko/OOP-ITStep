#pragma once

#include <string>

#include "Test.h"

class Category 
{
private: //поля принадлежат только обьектам этого класса, за пределами НЕ доступны
    std::string category_name; // Название категории
    Test* tests; // Массив тестов
    int num_tests; // Количество тестов

public:
    // Конструктор класса Category, инициализирующий его основные атрибуты.
    Category(const std::string& categoryName);

    // Деструктор класса Category, освобождающий память, выделенную под тесты.
    ~Category();

    void add_test(const Test& test); // Добавление теста в категорию
    void del_Test(int index); // Удаление теста из категории
};


