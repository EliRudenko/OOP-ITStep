#include "RAM_L.h"
#include <iostream>
#include <cstring>


RAM::RAM() 
{
    this->RAM_name = nullptr;
    this->price = 0.0;
    this->memory = 0;
}

RAM::RAM(const char* inputRAMName, double inputPrice, int inputMemory) : RAM() 
{
    this->RAM_name = new char[strlen(inputRAMName) + 1];
    strcpy_s(this->RAM_name, strlen(inputRAMName) + 1, inputRAMName);

    this->price = inputPrice;
    this->memory = inputMemory;
}


RAM::RAM(const RAM& copyRAM) : RAM(copyRAM.RAM_name, copyRAM.price, copyRAM.memory)
{
    RAM_name = new char[strlen(copyRAM.RAM_name) + 1];
    strcpy_s(RAM_name, strlen(copyRAM.RAM_name) + 1, copyRAM.RAM_name);
}


void RAM::set_RAM_name(const char* inputRAMName) 
{
    if (this->RAM_name != nullptr) {
        delete[] this->RAM_name;
        this->RAM_name = nullptr;
    }

    this->RAM_name = new char[strlen(inputRAMName) + 1];
    strcpy_s(this->RAM_name, strlen(inputRAMName) + 1, inputRAMName);
}

void RAM::set_price(double inputPrice) { this->price = inputPrice; }

void RAM::set_memory(int inputMemory) { this->memory = inputMemory; }

void RAM::print_RAM() 
{
    std::cout << "Name: " << this->RAM_name << std::endl;
    std::cout << "Price: " << this->price << std::endl;
    std::cout << "Memory: " << this->memory << std::endl;
}

char* RAM::get_RAM_name() { return this->RAM_name; }


double RAM::get_price() { return this->price; }

int RAM::get_memory() { return this->memory; }

RAM::~RAM() { delete[] this->RAM_name; }
    



