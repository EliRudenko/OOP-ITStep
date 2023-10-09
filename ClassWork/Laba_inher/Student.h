#pragma once

#include "Human.h"
#include "Uni.h"

#include <string>

class Student : public Human, public University 
{
private:
    std::string group;
    int grades[5]; 
    int numGrades; 

public:
    Student(std::string name, int age, std::string universityName, std::string faculty, std::string group);
    std::string getGroup() const;
    void setGroup(const std::string& group);
    void addGrade(int grade);
    void printGrades() const;


};


