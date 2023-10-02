#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#pragma once
#include <string>

class FlashDrive 
{
private:
    std::string flashdrive_n;

public:
    FlashDrive();
    FlashDrive(const std::string& inputN);

    void set_flashdrive_n(const std::string& inputN);

    const std::string& get_flashdrive_n() const;

    ~FlashDrive();
};
