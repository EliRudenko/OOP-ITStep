#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#pragma once
#include <string>

class Touchpad 
{
private:
    std::string touchpad_type;

public:
    Touchpad();
    Touchpad(const std::string& inputType);

    void set_touchpad_type(const std::string& inputType);

    const std::string& get_touchpad_type() const;

    ~Touchpad();
};
