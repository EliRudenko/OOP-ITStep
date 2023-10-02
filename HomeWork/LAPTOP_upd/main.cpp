#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#pragma once

#include "SSD_L.cpp"
#include "CPU_L.cpp"
#include "RAM_L.cpp"
#include "GPU_L.cpp"
#include "Keyboard.cpp"
#include "Touchpad.cpp"

#include "Mouse.cpp"
#include "Camera.cpp"
#include "FlashDrive.cpp"
#include "Laptop.cpp"


int main() 
{

    //мега быстроя проверка))

    CPU cpu("Intel i7", 500.0, 2.8);
    GPU gpu("N 3080", 1200.0);
    RAM ram("CV", 150.0, 16);
    SSD ssd("Samsung 970", 200.0, 500);
    Keyboard keyboard("K");
    Touchpad touchpad("T");

    Mouse mouse("M");
    Camera camera("HD");
    FlashDrive flashDrive("USB 3.0");

    Laptop laptop;

//АГРЕГАЦИЯ
    laptop.setMouse(&mouse);
    laptop.setCamera(&camera);
    laptop.setFlashDrive(&flashDrive);

    laptop.print_info();

    return 0;





//детально
/*

    std::string inputStr;
    double inputDouble;
    int inputInt;

//CPU
    std::cout << "Enter CPU name: ";
    std::getline(std::cin, inputStr);
    CPU cpu(inputStr, 0.0, 0.0);

    std::cout << "Enter CPU price: ";
    std::cin >> inputDouble;
    cpu.set_price(inputDouble);

    std::cout << "Enter CPU GHz: ";
    std::cin >> inputDouble;
    cpu.set_GHz(inputDouble);

    std::cin.ignore(); 

//GPU
    GPU gpu;
    std::cout << "Enter GPU name: ";
    std::getline(std::cin, inputStr);
    gpu.set_GPU_name(inputStr);

    std::cout << "Enter GPU price: ";
    std::cin >> inputDouble;
    gpu.set_price(inputDouble);

    std::cin.ignore();

    
//RAM
    RAM ram;
    std::cout << "Enter RAM name: ";
    std::getline(std::cin, inputStr);
    ram.set_RAM_name(inputStr);

    std::cout << "Enter RAM price: ";
    std::cin >> inputDouble;
    ram.set_price(inputDouble);

    std::cout << "Enter RAM size (GB): ";
    std::cin >> inputInt;
    ram.set_sizeGB(inputInt);

    std::cin.ignore();

//SSD
    SSD ssd;
    std::cout << "Enter SSD name: ";
    std::getline(std::cin, inputStr);
    ssd.set_SSD_name(inputStr);

    std::cout << "Enter SSD price: ";
    std::cin >> inputDouble;
    ssd.set_price(inputDouble);

    std::cout << "Enter SSD capacity (GB): ";
    std::cin >> inputInt;
    ssd.set_capacityGB(inputInt);

    std::cin.ignore();

//Keyboard
    Keyboard keyboard;
    std::cout << "Enter keyboard type: ";
    std::getline(std::cin, inputStr);
    keyboard.set_keyboard_type(inputStr);

//Touchpad
    Touchpad touchpad;
    std::cout << "Enter touchpad type: ";
    std::getline(std::cin, inputStr);
    touchpad.set_touchpad_type(inputStr);

    Laptop laptop;

//АГРЕГАЦИЯ
    Mouse mouse;
    std::cout << "Enter mouse type: ";
    std::getline(std::cin, inputStr);
    mouse.set_mouse_n(inputStr);

    Camera camera;
    std::cout << "Enter camera type: ";
    std::getline(std::cin, inputStr);
    camera.set_camera_n(inputStr);

    FlashDrive flashDrive;
    std::cout << "Enter flash drive type: ";
    std::getline(std::cin, inputStr);
    flashDrive.set_flashdrive_n(inputStr);

    laptop.setMouse(&mouse);
    laptop.setCamera(&camera);
    laptop.setFlashDrive(&flashDrive);

    
    laptop.set_CPU(cpu);
    laptop.set_GPU(gpu);
    laptop.set_RAM(ram);
    laptop.set_SSD(ssd);
    laptop.set_Keyboard(keyboard);
    laptop.set_Touchpad(touchpad);
    

    laptop.print_info();

    return 0;
*/
}

