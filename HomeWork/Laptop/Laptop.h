#pragma once

#include "SSD_L.h"
#include "CPU_L.h"
#include "RAM_L.h"
#include "GPU_L.h"

class Laptop 
{
private:
    char* name;
    char* color;
    SSD laptop_SSD;
    CPU laptop_CPU;
    RAM laptop_RAM;
    GPU laptop_GPU;

public:

    Laptop();
    Laptop(const char* inputName, const char* inputColor, const SSD& inputSSD, const CPU& inputCPU, const RAM& inputRAM, const GPU& inputGPU);
    Laptop(const Laptop& copyLaptop);

    void set_name(const char* inputName);
    void set_color(const char* inputColor);
    void set_SSD(const SSD& inputSSD);
    void set_CPU(const CPU& inputCPU);
    void set_RAM(const RAM& inputRAM);
    void set_GPU(const GPU& inputGPU);

    void print_Laptop();

    ~Laptop();
};



















/*
#include "SSD_L.h"
#include "CPU_L.h"
#include "SSD_L.h"
#include "RAM_L.h"
#include "GPU_L.h"

class LAPTOP {
private:
    char* name;
    char* color;
    SSD laptopSSD;
    CPU laptopCPU;
    RAM laptopRAM;
    GPU laptopGPU;

public:
    LAPTOP();
    LAPTOP(const char* inputName, const char* inputColor, const SSD& inputLaptopSSD, const CPU& inputLaptopCPU, const RAM& inputLaptopRAM, const GPU& inputLaptopGPU);
    LAPTOP(const LAPTOP& copyLAPTOP);

    void setName(const char* inputName);
    void setColor(const char* inputColor);
    void setLaptopSSD(const SSD& inputLaptopSSD);
    void setLaptopCPU(const CPU& inputLaptopCPU);
    void setLaptopRAM(const RAM& inputLaptopRAM);
    void setLaptopGPU(const GPU& inputLaptopGPU);

    void printLaptopSpecs();

    char* getName();
    char* getColor();
    SSD getLaptopSSD();
    CPU getLaptopCPU();
    RAM getLaptopRAM();
    GPU getLaptopGPU();

    ~LAPTOP();
};
*/