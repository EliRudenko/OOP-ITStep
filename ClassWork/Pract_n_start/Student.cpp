#include "Student.h"
#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#include <iostream>
#include <cstring>

//проверка доступа
//ибо нет смысла писать и таек все получили от родителя, просто делинагия 
Student::Student(const char* n, int a, const char* u) : Person(n,a) // ВСЕ ИЗ ПЕРСОНА + НОВОЕ 
{
    Uni = new char[strlen(u) + 1];
    strcpy_s(Uni, strlen(u) + 1, u);
    std::cout << "Student Constr" << std::endl;
}

void Student::Print() // ПЕРЕОПРЕДЕЛЕНИЕ
{
    Person::Print(); // вызов метоида Print родительского класса
    std::cout << "Uni: " << Uni << std::endl;
}

void Student::Input(const char* uni) //ЗАМЕЩЕНИЕ
{
    if (Uni != nullptr)
    {
        delete[] Uni;
    }

    Uni = new char[strlen(uni) + 1];
    strcpy_s(Uni, strlen(uni) + 1, uni);

    Person::Input();
}

Student::~Student()
{
    delete[] Uni;
    std::cout << "Student Destr" << std::endl;
}
