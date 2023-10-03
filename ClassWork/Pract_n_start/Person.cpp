#include "Person.h"
#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#include <iostream>
#include <cstring>

Person::Person() : name(nullptr), age(0) {}

Person::Person(const char* n, int a) : age(a)
{
    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
    std::cout << "Person Constr" << std::endl;
}

void Person::Print()
{
    std::cout << "Name: " << name << "  " << "Age: " << age << std::endl;
}

void Person::Input()
{
    char buff[20];
    std::cout << "Enter Name: ";
    std::cin.getline(buff, 20);
    delete[] name;
    name = new char[strlen(buff) + 1];
    strcpy_s(name, strlen(buff) + 1, buff);
    std::cout << "Enter Age: ";
    std::cin >> age;
    std::cin.ignore();
}

Person::~Person()
{
    delete[] name;
    std::cout << "Person Destr" << std::endl;
}
