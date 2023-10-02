#include "RAM_L.h"

RAM::RAM() : price(0.0), sizeGB(0) {}

RAM::RAM(const std::string& inputRAMName, double inputPrice, int inputSizeGB) : RAM() 
{
    RAM_name = inputRAMName;
    price = inputPrice;
    sizeGB = inputSizeGB;
}

void RAM::set_RAM_name(const std::string& inputRAMName) { RAM_name = inputRAMName; }

void RAM::set_price(double inputPrice) { price = inputPrice; }

void RAM::set_sizeGB(int inputSizeGB) { sizeGB = inputSizeGB; }

const std::string& RAM::get_RAM_name() const { return RAM_name; }

double RAM::get_price() const { return price; }

int RAM::get_sizeGB() const { return sizeGB; }

RAM::~RAM() {}
