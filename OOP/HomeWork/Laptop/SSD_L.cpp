#include "SSD_L.h"
#include <iostream>
#include <cstring>

SSD::SSD() 
{
    this->SSD_name = nullptr;
    this->memory = 0;
    this->price = 0.0;
    this->transfer_speed = 0.0;
}

SSD::SSD(const char* inputSSDName) 
{
    this->SSD_name = new char[strlen(inputSSDName) + 1];
    strcpy_s(this->SSD_name, strlen(inputSSDName) + 1, inputSSDName);

    this->memory = 0;
    this->price = 0.0;
    this->transfer_speed = 0.0;
}

SSD::SSD(const char* inputSSDName, int inputSSDMemory) 
{
    this->SSD_name = new char[strlen(inputSSDName) + 1];
    strcpy_s(this->SSD_name, strlen(inputSSDName) + 1, inputSSDName);

    this->memory = inputSSDMemory;
    this->price = 0.0;
    this->transfer_speed = 0.0;
}

SSD::SSD(const char* inputSSDName, int inputSSDMemory, double inputSSDprice)
{
    this->SSD_name = new char[strlen(inputSSDName) + 1];
    strcpy_s(this->SSD_name, strlen(inputSSDName) + 1, inputSSDName);

    this->memory = inputSSDMemory;
    this->price = inputSSDprice;
    this->transfer_speed = 0.0;
}

SSD::SSD(const char* inputSSDName, int inputSSDMemory, double inputSSDprice, double inputSSDtransfer_speed)
{
    this->SSD_name = new char[strlen(inputSSDName) + 1];
    strcpy_s(this->SSD_name, strlen(inputSSDName) + 1, inputSSDName);

    this->memory = inputSSDMemory;
    this->price = inputSSDprice;
    this->transfer_speed = inputSSDtransfer_speed;
}

SSD::SSD(const SSD& copySSD) 
{
    this->SSD_name = new char[strlen(copySSD.SSD_name) + 1];
    strcpy_s(this->SSD_name, strlen(copySSD.SSD_name) + 1, copySSD.SSD_name);

    this->memory = copySSD.memory;
    this->price = copySSD.price;
    this->transfer_speed = copySSD.transfer_speed;
}

void SSD::set_SSD_name(const char* inputSSDName) 
{
    if (this->SSD_name != nullptr) 
    {
        delete[] this->SSD_name;
        this->SSD_name = nullptr;
    }
    this->SSD_name = new char[strlen(inputSSDName) + 1];
    strcpy_s(this->SSD_name, strlen(inputSSDName) + 1, inputSSDName);
}

void SSD::set_SSD_memory(int inputSSDMemory) { this->memory = inputSSDMemory; }

void SSD::set_SSD_price(double inputSSDprice) { this->price = inputSSDprice; }

void SSD::set_SSD_transfer_speed(double inputSSDtransfer_speed) { this->transfer_speed = inputSSDtransfer_speed; }

void SSD::print_SSD() 
{
    std::cout << "Name: " << this->SSD_name << std::endl;
    std::cout << "Memory: " << this->memory << std::endl;
    std::cout << "Price: " << this->price << std::endl;
    std::cout << "Transfer Speed: " << this->transfer_speed << std::endl;
}

char* SSD::get_SSD_name() { return this->SSD_name; }

int SSD::get_SSD_memory() { return this->memory; }

double SSD::get_SSD_price() { return this->price; }

double SSD::get_SSD_transfer_speed() { return this->transfer_speed; }

SSD::~SSD() { delete[] this->SSD_name; }