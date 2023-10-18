#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#pragma once
#include <string>

class GPU 
{
private:
    std::string GPU_name;
    double price;

public:
    GPU();
    GPU(const std::string& inputGPUName, double inputPrice);

    void set_GPU_name(const std::string& inputGPUName);
    void set_price(double inputPrice);

    const std::string& get_GPU_name() const;
    double get_price() const;

    ~GPU();
};
