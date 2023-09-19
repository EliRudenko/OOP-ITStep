#include "Laptop.h"
#include <iostream>
#include <cstring>


Laptop::Laptop() : name(nullptr), color(nullptr) {}

Laptop::Laptop(const char* inputName, const char* inputColor, const SSD& inputSSD, const CPU& inputCPU, const RAM& inputRAM, const GPU& inputGPU) : laptop_SSD(inputSSD), laptop_CPU(inputCPU), laptop_RAM(inputRAM), laptop_GPU(inputGPU) 
{
    name = new char[strlen(inputName) + 1];
    strcpy_s(name, strlen(inputName) + 1, inputName);

    color = new char[strlen(inputColor) + 1];
    strcpy_s(color, strlen(inputColor) + 1, inputColor);
}

Laptop::Laptop(const Laptop& copyLaptop) : laptop_SSD(copyLaptop.laptop_SSD), laptop_CPU(copyLaptop.laptop_CPU), laptop_RAM(copyLaptop.laptop_RAM), laptop_GPU(copyLaptop.laptop_GPU) 
{
    name = new char[strlen(copyLaptop.name) + 1];
    strcpy_s(name, strlen(copyLaptop.name) + 1, copyLaptop.name);

    color = new char[strlen(copyLaptop.color) + 1];
    strcpy_s(color, strlen(copyLaptop.color) + 1, copyLaptop.color);
}

void Laptop::set_name(const char* inputName) 
{
    if (name != nullptr) 
    {
        delete[] name;
        name = nullptr;
    }
    name = new char[strlen(inputName) + 1];
    strcpy_s(name, strlen(inputName) + 1, inputName);
}

void Laptop::set_color(const char* inputColor) 
{
    if (color != nullptr) 
    {
        delete[] color;
        color = nullptr;
    }
    color = new char[strlen(inputColor) + 1];
    strcpy_s(color, strlen(inputColor) + 1, inputColor);
}

void Laptop::set_SSD(const SSD& inputSSD) { laptop_SSD = inputSSD; }

void Laptop::set_CPU(const CPU& inputCPU) { laptop_CPU = inputCPU; }

void Laptop::set_RAM(const RAM& inputRAM) { laptop_RAM = inputRAM; }

void Laptop::set_GPU(const GPU& inputGPU) { laptop_GPU = inputGPU; }

void Laptop::print_Laptop() 
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << std::endl;
    std::cout << "Laptop Specs:" << std::endl;

    std::cout << "SSD" << std::endl;
    laptop_SSD.print_SSD();
    std::cout << std::endl;
    std::cout << "CPU" << std::endl;
    laptop_CPU.print_CPU();
    std::cout << std::endl;
    std::cout << "RAM" << std::endl;
    laptop_RAM.print_RAM();
    std::cout << std::endl;
    std::cout << "GPU" << std::endl;
    laptop_GPU.print_GPU();
}

Laptop::~Laptop() 
{
    delete[] name;
    delete[] color;
}
