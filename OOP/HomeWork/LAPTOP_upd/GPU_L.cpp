#include "GPU_L.h"


GPU::GPU() : price(0.0) {}

GPU::GPU(const std::string& inputGPUName, double inputPrice) : GPU() 
{
    GPU_name = inputGPUName;
    price = inputPrice;
}

void GPU::set_GPU_name(const std::string& inputGPUName) { GPU_name = inputGPUName; }

void GPU::set_price(double inputPrice) { price = inputPrice; }

const std::string& GPU::get_GPU_name() const { return GPU_name; }

double GPU::get_price() const { return price; }

GPU::~GPU() {}
