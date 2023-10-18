#pragma once

class CPU 
{
private:
    char* CPU_name;
    double price;
    double GHz;

public:
    CPU();
    CPU(const char* inputCPUName, double inputPrice, double inputGHz);
    
    CPU(const CPU& copyCPU);

    void set_CPU_name(const char* inputCPUName);
    void set_price(double inputPrice);
    void set_GHz(double inputGHz);

    void print_CPU();

    char* get_CPU_name();
    double get_price();
    double get_GHz();

    ~CPU();
};

