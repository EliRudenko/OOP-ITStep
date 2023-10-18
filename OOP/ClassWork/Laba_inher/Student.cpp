#include "Student.h"

#include <iostream>

Student::Student(std::string name, int age, std::string universityName, std::string faculty, std::string group)  : Human(name, age), University(universityName, faculty), group(group), numGrades(0) {}

std::string Student::getGroup() const { return group; }

void Student::setGroup(const std::string& newGroup) { group = newGroup; }

void Student::addGrade(int grade) 
{
    if (numGrades < 5) 
    {
        grades[numGrades] = grade;
        numGrades++;
    }
}

void Student::printGrades() const 
{
    for (int i = 0; i < numGrades; i++) {  std::cout << "Grade " << i + 1 << ": " << grades[i] << std::endl; }
}
