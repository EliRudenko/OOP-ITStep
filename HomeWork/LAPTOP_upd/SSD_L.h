#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#pragma once
#include <string>
class SSD 
{
private:
    std::string SSD_name;
    double price;
    int capacityGB;

public:
    SSD();
    SSD(const std::string& inputSSDName, double inputPrice, int inputCapacityGB);

    void set_SSD_name(const std::string& inputSSDName);
    void set_price(double inputPrice);
    void set_capacityGB(int inputCapacityGB);

    const std::string& get_SSD_name() const;
    double get_price() const;
    int get_capacityGB() const;

    ~SSD();
};


