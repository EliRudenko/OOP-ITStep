#include "Doctor.h"
#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#include <iostream>

Doctor::Doctor(const char* n, int a, const std::string& spec, int exp, bool fam) : Person(n, a), specialty(spec), experience(exp), family_doc(fam)
{
    std::cout << "Doctor Constr" << std::endl;
}

void Doctor::Print()
{
    Person::Print();
    std::cout << "Specialty: " << specialty << "    " << "Experience: " << experience << "    " << " Family Doctor: " << (family_doc ? "Yes" : "No") << std::endl;
}

void Doctor::Input(const std::string& spec, int exp, bool fam)
{
    specialty = spec;
    experience = exp;
    family_doc = fam;

    Person::Input();
}

Doctor::~Doctor()
{
    std::cout << "Doctor Destr" << std::endl;
}
