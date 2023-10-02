#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#pragma once
#include <string>

class CPU 
{
private:
    std::string CPU_name;
    double price;
    double GHz;

public:
    CPU();
    CPU(const std::string& inputCPUName, double inputPrice, double inputGHz);
    
    void set_CPU_name(const std::string& inputCPUName);
    void set_price(double inputPrice);
    void set_GHz(double inputGHz);

    const std::string& get_CPU_name() const;
    double get_price() const;
    double get_GHz() const;

    ~CPU();
};
