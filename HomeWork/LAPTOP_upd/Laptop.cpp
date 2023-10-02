#include "Laptop.h"
#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#include <iostream>


Laptop::Laptop() : mouse(nullptr), camera(nullptr), flashDrive(nullptr) {}

Laptop::~Laptop() {}

void Laptop::setMouse(Mouse* m) { mouse = m; }

void Laptop::setCamera(Camera* c) { camera = c; }

void Laptop::setFlashDrive(FlashDrive* f) { flashDrive = f; }

void Laptop::print_info() const
{
    std::cout << "CPU:" << std::endl;
    std::cout << "Name: " << cpu.get_CPU_name() << ", Price: " << cpu.get_price() << ", GHz: " << cpu.get_GHz() << std::endl;

    std::cout << "GPU:" << std::endl;
    std::cout << "Name: " << gpu.get_GPU_name() << ", Price: " << gpu.get_price() << std::endl;

    std::cout << "RAM:" << std::endl;
    std::cout << "Name: " << ram.get_RAM_name() << ", Price: " << ram.get_price() << ", Size (GB): " << ram.get_sizeGB() << std::endl;

    std::cout << "SSD:" << std::endl;
    std::cout << "Name: " << ssd.get_SSD_name() << ", Price: " << ssd.get_price() << ", Capacity (GB): " << ssd.get_capacityGB() << std::endl;

    std::cout << "Keyboard:" << std::endl;
    std::cout << "Type: " << keyboard.get_keyboard_type() << std::endl;

    std::cout << "Touchpad:" << std::endl;
    std::cout << "Type: " << touchpad.get_touchpad_type() << std::endl;


// ПРОВЕРКА, ибо можно и без мышки и тп, песли да - то инфа

    if (mouse) 
    {
        std::cout << "Mouse:" << std::endl;
        std::cout << "Type: " << mouse->get_mouse_n() << std::endl;
    }

    if (camera) 
    {
        std::cout << "Camera:" << std::endl;
        std::cout << "Type: " << camera->get_camera_n() << std::endl;
    }

    if (flashDrive) 
    {
        std::cout << "Flash Drive:" << std::endl;
        std::cout << "Type: " << flashDrive->get_flashdrive_n() << std::endl;
    }
}
