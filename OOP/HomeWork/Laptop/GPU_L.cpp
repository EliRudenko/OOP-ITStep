#include "GPU_L.h"
#include <iostream>
#include <cstring>

GPU::GPU() 
{
    this->GPU_name = nullptr;
    this->price = 0.0;
    this->memory = 0;
    this->GHz = 0.0;
}

GPU::GPU(const char* inputGPUName) : GPU() 
{
    this->GPU_name = new char[strlen(inputGPUName) + 1];
    strcpy_s(this->GPU_name, strlen(inputGPUName) + 1, inputGPUName);
}

GPU::GPU(const char* inputGPUName, double inputPrice) : GPU(inputGPUName) { this->price = inputPrice; }

GPU::GPU(const char* inputGPUName, double inputPrice, int inputGPUMemory) : GPU(inputGPUName, inputPrice) { this->memory = inputGPUMemory;}

GPU::GPU(const char* inputGPUName, double inputPrice, int inputGPUMemory, double inputGPUGHz) : GPU(inputGPUName, inputPrice, inputGPUMemory) { this->GHz = inputGPUGHz; }

GPU::GPU(const GPU& copyGPU) 
{
    this->GPU_name = new char[strlen(copyGPU.GPU_name) + 1];
    strcpy_s(GPU_name, strlen(copyGPU.GPU_name) + 1, copyGPU.GPU_name);

    this->price = copyGPU.price;
    this->memory = copyGPU.memory;
    this->GHz = copyGPU.GHz;
}

void GPU::set_GPU_name(const char* inputGPUName) 
{
    if (this->GPU_name != nullptr) 
    {
        delete[] this->GPU_name;
        this->GPU_name = nullptr;
    }

    this->GPU_name = new char[strlen(inputGPUName) + 1];
    strcpy_s(this->GPU_name, strlen(inputGPUName) + 1, inputGPUName);
}

void GPU::set_GPU_price(double inputPrice) { this->price = inputPrice; }

void GPU::set_GPU_memory(int inputGPUMemory) { this->memory = inputGPUMemory; }

void GPU::set_GPU_GHz(double inputGPUGHz) { this->GHz = inputGPUGHz; }

void GPU::print_GPU() 
{
    std::cout << "Name: " << this->GPU_name << std::endl;
    std::cout << "Price: $" << this->price << std::endl;
    std::cout << "Memory: " << this->memory << " GB" << std::endl;
    std::cout << "GHz: " << this->GHz << std::endl;
}

char* GPU::get_GPU_name() { return this->GPU_name; }

double GPU::get_GPU_price() { return this->price; }

int GPU::get_GPU_memory() { return this->memory; }

double GPU::get_GPU_GHz() { return this->GHz; }

GPU::~GPU() { delete[] this->GPU_name; }