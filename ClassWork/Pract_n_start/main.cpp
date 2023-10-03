#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

#include<iostream>
#include<string>

#include "Student.cpp"
#include "Teacher.cpp"
#include "Doctor.cpp"
#include "Driver.cpp"

int main()
{
    Student obj("Lara", 18, "Step");
    obj.Print(); // АВТОМАТИЧЕСКИ ПОНИМАЕТ ДЛЯ КАКОГО КЛАССА НАДО ВЫЗВАЯ МЕТОД 

    Teacher teacher("Olga", 30, "High", 2500, new std::string[2]{"Math", "Programming"}, 2);
    teacher.Print();

    Doctor doctor("Doc Mark", 40, "Neurologist", 10, false);
    doctor.Print();

    Driver driver("Sam", 25, "BH2886PM", "886826");
    driver.Print();

    return 0;
}


//наследование ДЗ
//добавить классы в код 
//препод - школа, зарплата, массив предметов
//доктор - специальность, стаж работы, bool семейный врач(да/нет)
//водила - номер авто, сериая номер водительских прав
//предусматреть необходимый интерфейс
//использовать переопределение и замещение