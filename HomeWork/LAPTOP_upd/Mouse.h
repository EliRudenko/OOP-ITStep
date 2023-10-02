#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#pragma once
#include <string>

class Mouse 
{
private:
    std::string mouse_n;

public:
    Mouse();
    Mouse(const std::string& inputN);

    void set_mouse_n(const std::string& inputN);

    const std::string& get_mouse_n() const;

    ~Mouse();
};
