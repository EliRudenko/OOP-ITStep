#pragma onse
#include "Person.h"
#include <string>

class Driver : public Person
{
private:
    std::string car_num;
    std::string license_num;

public:
    Driver(const char* n, int a, const std::string& carNum, const std::string& licenseNum);
    ~Driver();
    void Print();
    void Input(const std::string& carNum, const std::string& licenseNum);
};