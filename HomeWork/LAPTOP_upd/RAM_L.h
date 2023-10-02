#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#pragma once
#include <string>

class RAM 
{
private:
    std::string RAM_name;
    double price;
    int sizeGB;

public:
    RAM();
    RAM(const std::string& inputRAMName, double inputPrice, int inputSizeGB);

    void set_RAM_name(const std::string& inputRAMName);
    void set_price(double inputPrice);
    void set_sizeGB(int inputSizeGB);

    const std::string& get_RAM_name() const;
    double get_price() const;
    int get_sizeGB() const;

    ~RAM();
};
