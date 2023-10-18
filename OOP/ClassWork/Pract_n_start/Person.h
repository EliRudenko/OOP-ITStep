#pragma onse

class Person
{
protected:
    char* name;
    int age;

public:
    Person();
    Person(const char* n, int a);
    void Print();
    //void Print();
    void Input();
    ~Person();
};

