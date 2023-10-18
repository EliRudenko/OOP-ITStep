#pragma onse
#include "Person.h"
#include <string>

class Doctor : public Person
{
private:
    std::string specialty;
    int experience;
    bool family_doc;

public:
    Doctor(const char* n, int a, const std::string& spec, int exp, bool fam);
    ~Doctor();
    void Print();
    void Input(const std::string& spec, int exp, bool fam);
};
