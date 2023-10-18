#pragma once
#include <string>

class Human 
{
private:
    std::string name;
    int age;

public:
    Human(std::string name, int age);

    std::string getName() const;
    int getAge() const;

    void setName(const std::string& name);
    void setAge(int age);

};

