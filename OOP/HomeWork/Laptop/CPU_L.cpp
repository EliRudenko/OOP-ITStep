#include "CPU_L.h"
#include <iostream>
#include <cstring>


CPU::CPU() 
{
    this->CPU_name = nullptr;
    this->price = 0.0;
    this->GHz = 0.0;
}

CPU::CPU(const char* inputCPUName, double inputPrice, double inputGHz) : CPU() 
{
    this->CPU_name = new char[strlen(inputCPUName) + 1];
    strcpy_s(this->CPU_name, strlen(inputCPUName) + 1, inputCPUName);

    this->price = inputPrice;
    this->GHz = inputGHz;
}

CPU::CPU(const CPU& copyCPU) : CPU(copyCPU.CPU_name, copyCPU.price, copyCPU.GHz)
{
    CPU_name = new char[strlen(copyCPU.CPU_name) + 1];
    strcpy_s(CPU_name, strlen(copyCPU.CPU_name) + 1, copyCPU.CPU_name);
}

void CPU::set_CPU_name(const char* inputCPUName) 
{
    if (this->CPU_name != nullptr)
    {
        delete[] this->CPU_name;
        this->CPU_name = nullptr;
    }

    this->CPU_name = new char[strlen(inputCPUName) + 1];
    strcpy_s(this->CPU_name, strlen(inputCPUName) + 1, inputCPUName);
}

void CPU::set_price(double inputPrice) { this->price = inputPrice; }

void CPU::set_GHz(double inputGHz) { this->GHz = inputGHz; }

void CPU::print_CPU() 
{
    std::cout << "Name: " << this->CPU_name << std::endl;
    std::cout << "Price: " << this->price << std::endl;
    std::cout << "GHz: " << this->GHz << std::endl;
}

char* CPU::get_CPU_name() { return this->CPU_name; }

double CPU::get_price() { return this->price; }

double CPU::get_GHz() { return this->GHz; }

CPU::~CPU() { delete[] this->CPU_name;}
