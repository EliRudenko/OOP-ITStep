#pragma onse
#include "Person.h"
#include <string>

class Teacher : public Person
{
private:
    char* school;
    int salary;
    std::string* subjects_arr;
    int subjects_count;

public:
    Teacher(const char* n, int a, const char* s, int sal, const std::string* sub, int num);
    ~Teacher();
    void Print();
    void Input(const char* s, int sal, const std::string* sub, int num);
};
