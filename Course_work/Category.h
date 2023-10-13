#pragma once

#include <string>
#include "Test.h"

class Category 
{
private: //поля принадлежат только обьектам этого класса, за пределами НЕ доступны
    std::string category_name; 
    Test* tests; // Массив тестов
    int num_tests; 

public:
    Category(const std::string& categoryName);
    ~Category();

    void add_test(const Test& test);
    void del_Test(int index); 
};


