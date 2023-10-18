#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#pragma once

#include "SSD_L.h"
#include "CPU_L.h"
#include "RAM_L.h"
#include "GPU_L.h"
#include "Keyboard.h"
#include "Touchpad.h"

#include "Mouse.h"
#include "Camera.h"
#include "FlashDrive.h"

class Laptop 
{
private:
// КОМПОЗИЦИЯ
    CPU cpu;
    GPU gpu;
    RAM ram;
    SSD ssd;
    Keyboard keyboard;
    Touchpad touchpad;

 // УКАЗАТЕЛИ на объекты => АГРЕГАЦИЯ
    Mouse* mouse;
    Camera* camera;
    FlashDrive* flashDrive;

public:
    Laptop();
    ~Laptop();

//АГРЕГАЦИЯ
    void setMouse(Mouse* m);
    void setCamera(Camera* c);
    void setFlashDrive(FlashDrive* f);

    void print_info() const; //общий принт для всей инфы
};
