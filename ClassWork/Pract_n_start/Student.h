#pragma onse
#include "Person.h"

class Student : public Person
{
private:
    char* Uni;

public:
    Student(const char* n, int a, const char* u);
    ~Student();
    void Print();
    void Input(const char* uni);
};

