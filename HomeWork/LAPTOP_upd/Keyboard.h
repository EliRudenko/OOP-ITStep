#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#pragma once
#include <string>

class Keyboard 
{
private:
    std::string keyboard_type;

public:
    Keyboard();
    Keyboard(const std::string& inputType);

    void set_keyboard_type(const std::string& inputType);

    const std::string& get_keyboard_type() const;

    ~Keyboard();
};
