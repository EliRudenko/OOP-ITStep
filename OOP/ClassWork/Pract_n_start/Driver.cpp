#include "Driver.h"
#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#include <iostream>

Driver::Driver(const char* n, int a, const std::string& carNum, const std::string& licenseNum) : Person(n, a), car_num(carNum), license_num(licenseNum)
{
    std::cout << "Driver Constr" << std::endl;
}

void Driver::Print()
{
    Person::Print();
    std::cout << "Car Number: " << car_num << "    " << "License Number: " << license_num << std::endl;
}

void Driver::Input(const std::string& carNum, const std::string& licenseNum)
{
    car_num = carNum;
    license_num = licenseNum;

    Person::Input();
}

Driver::~Driver()
{
    std::cout << "Driver Destr" << std::endl;
}
