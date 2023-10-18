#include "CPU_l.h"

CPU::CPU() : price(0.0), GHz(0.0) {}

CPU::CPU(const std::string& inputCPUName, double inputPrice, double inputGHz) : CPU() 
{
    CPU_name = inputCPUName;
    price = inputPrice;
    GHz = inputGHz;
}

void CPU::set_CPU_name(const std::string& inputCPUName) { CPU_name = inputCPUName; }

void CPU::set_price(double inputPrice) { price = inputPrice; }

void CPU::set_GHz(double inputGHz) { GHz = inputGHz; }

const std::string& CPU::get_CPU_name() const { return CPU_name; }

double CPU::get_price() const { return price; }

double CPU::get_GHz() const { return GHz; }

CPU::~CPU() {}
