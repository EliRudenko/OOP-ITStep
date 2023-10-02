#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#pragma once
#include <string>

class Camera 
{
private:
    std::string camera_n;

public:
    Camera();
    Camera(const std::string& inputN);

    void set_camera_n(const std::string& inputN);

    const std::string& get_camera_n() const;

    ~Camera();
};
