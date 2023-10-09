#include "Student.cpp"

#include <iostream>

int main() 
{
    Student student("Lara", 18, "Step", "Programming", "KH-P1");

    student.addGrade(10);
    student.addGrade(9);
    student.addGrade(11);

    std::cout << "Name: " << student.Human::getName() << std::endl;

    std::cout << "Age: " << student.getAge() << std::endl;

    std::cout << "University Name: " << student.University::getName() << std::endl;

    std::cout << "Faculty: " << student.getFaculty() << std::endl;
    std::cout << "Group: " << student.getGroup() << std::endl;

    student.printGrades();

    return 0;
}
