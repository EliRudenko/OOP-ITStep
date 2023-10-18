#include "SSD_L.h"


SSD::SSD() : price(0.0), capacityGB(0) {}

SSD::SSD(const std::string& inputSSDName, double inputPrice, int inputCapacityGB) : SSD() 
{
    SSD_name = inputSSDName;
    price = inputPrice;
    capacityGB = inputCapacityGB;
}

void SSD::set_SSD_name(const std::string& inputSSDName)  { SSD_name = inputSSDName; }

void SSD::set_price(double inputPrice) { price = inputPrice; }

void SSD::set_capacityGB(int inputCapacityGB) { capacityGB = inputCapacityGB; }

const std::string& SSD::get_SSD_name() const { return SSD_name; }

double SSD::get_price() const { return price; }

int SSD::get_capacityGB() const { return capacityGB; }

SSD::~SSD() {}
