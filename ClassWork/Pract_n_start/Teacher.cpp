#include "Teacher.h"
#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#include <iostream>
#include <cstring>

Teacher::Teacher(const char* n, int a, const char* s, int sal, const std::string* sub, int num) : Person(n, a), salary(sal), subjects_count(num)
{
    school = new char[strlen(s) + 1];
    strcpy_s(school, strlen(s) + 1, s);

    subjects_arr = new std::string[subjects_count];
    for (int i = 0; i < subjects_count; i++) { subjects_arr[i] = sub[i]; }

    std::cout << "Teacher Constr" << std::endl;
}

void Teacher::Print()
{
    Person::Print();
    std::cout << "School: " << school << "   " << "Salary: " << salary << "   ";
    std::cout << "Subjects: ";
    for (int i = 0; i < subjects_count; i++) { std::cout << subjects_arr[i] << " "; }
    std::cout << std::endl;
}

void Teacher::Input(const char* s, int sal, const std::string* sub, int num)
{
    delete[] school;
    delete[] subjects_arr;

    school = new char[strlen(s) + 1];
    strcpy_s(school, strlen(s) + 1, s);

    salary = sal;
    subjects_count = num;

    subjects_arr = new std::string[subjects_count];
    for (int i = 0; i < subjects_count; i++) { subjects_arr[i] = sub[i]; }

    Person::Input();
}

Teacher::~Teacher()
{
    delete[] school;
    delete[] subjects_arr;
    std::cout << "Teacher Destr" << std::endl;
}
