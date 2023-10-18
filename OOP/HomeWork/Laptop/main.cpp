#include <iostream>
#include <cstring>

#include "SSD_L.h"
#include "CPU_L.h"
#include "SSD_L.h"
#include "RAM_L.h"
#include "GPU_L.h"
#include "Laptop.h"


#include <iostream>
#include "Laptop.h"

int main() 
{
    char ssd_name[50];
    double ssd_price;
    int ssd_memory;
    double ssd_transfer_speed;

    std::cout << "Enter SSD name: ";
    std::cin.getline(ssd_name, sizeof(ssd_name));
    std::cout << "Enter SSD price: ";
    std::cin >> ssd_price;
    std::cout << "Enter SSD memory (GB): ";
    std::cin >> ssd_memory;
    std::cout << "Enter SSD transfer speed (MB/s): ";
    std::cin >> ssd_transfer_speed;
    std::cin.ignore();
    std::cout << std::endl;

    SSD SSD_inform(ssd_name, ssd_price, ssd_memory, ssd_transfer_speed);

    char cpu_name[50];
    double cpu_price;
    double cpu_clock_speed;

    std::cout << "Enter CPU name: ";
    std::cin.ignore();
    std::cin.getline(cpu_name, sizeof(cpu_name));
    std::cout << "Enter CPU price: ";
    std::cin >> cpu_price;
    std::cout << "Enter CPU clock speed (GHz): ";
    std::cin >> cpu_clock_speed;
    std::cin.ignore();
    std::cout << std::endl;

    CPU CPU_inform(cpu_name, cpu_price, cpu_clock_speed);

    char ram_name[50];
    double ram_price;
    int ram_memory;

    std::cout << "Enter RAM name: ";
    std::cin.getline(ram_name, sizeof(ram_name));
    std::cout << "Enter RAM price: ";
    std::cin >> ram_price;
    std::cout << "Enter RAM memory (GB): ";
    std::cin >> ram_memory;
    std::cin.ignore();
    std::cout << std::endl;

    RAM RAM_inform(ram_name, ram_price, ram_memory);

    char gpu_name[50];
    double gpu_price;
    int gpu_memory;
    double gpu_GHz;

    std::cout << "Enter GPU name: ";
    std::cin.getline(gpu_name, sizeof(gpu_name));
    std::cout << "Enter GPU price: ";
    std::cin >> gpu_price;
    std::cout << "Enter GPU memory (GB): ";
    std::cin >> gpu_memory;
    std::cout << "Enter GPU clock speed (GHz): ";
    std::cin >> gpu_GHz;
    std::cin.ignore();
    std::cout << std::endl;

    GPU GPU_inform(gpu_name, gpu_price, gpu_memory, gpu_GHz);

    char laptop_name[50];
    char laptop_color[50];

    std::cout << "Enter laptop name: ";
    std::cin.getline(laptop_name, sizeof(laptop_name));
    std::cout << "Enter laptop color: ";
    std::cin.getline(laptop_color, sizeof(laptop_color));
    std::cout << std::endl;

    Laptop Laptop_inform(laptop_name, laptop_color, SSD_inform, CPU_inform, RAM_inform, GPU_inform);

    Laptop_inform.print_Laptop();

    Laptop Laptop_copi(Laptop_inform);
    std::cout << std::endl;
    std::cout << "Copied Laptop Details:" << std::endl;
    Laptop_copi.print_Laptop();

    return 0;
}














/*
int main() 
{
    // Ввод данных для SSD
    char ssdName[100];
    double ssdPrice;
    int ssdMemory;
    double ssdUploadSpeed;
    double ssdDownloadSpeed;

    std::cout << "Enter SSD name: ";
    std::cin.getline(ssdName, sizeof(ssdName));
    std::cout << "Enter SSD price: ";
    std::cin >> ssdPrice;
    std::cout << "Enter SSD memory (GB): ";
    std::cin >> ssdMemory;
    std::cout << "Enter SSD upload speed (MB/s): ";
    std::cin >> ssdUploadSpeed;
    std::cout << "Enter SSD download speed (MB/s): ";
    std::cin >> ssdDownloadSpeed;
    std::cin.ignore();

    SSD mySSD(ssdName, ssdPrice, ssdMemory, ssdUploadSpeed, ssdDownloadSpeed);

    // Ввод данных для CPU
    char cpuName[100];
    double cpuPrice;
    double cpuGHz;

    std::cout << "Enter CPU name: ";
    std::cin.getline(cpuName, sizeof(cpuName));
    std::cout << "Enter CPU price: ";
    std::cin >> cpuPrice;
    std::cout << "Enter CPU GHz: ";
    std::cin >> cpuGHz;
    std::cin.ignore();

    CPU myCPU(cpuName, cpuPrice, cpuGHz);

    // Ввод данных для RAM
    char ramName[100];
    double ramPrice;
    int ramMemory;
    char ramSocket[100];

    std::cout << "Enter RAM name: ";
    std::cin.getline(ramName, sizeof(ramName));
    std::cout << "Enter RAM price: ";
    std::cin >> ramPrice;
    std::cout << "Enter RAM memory (GB): ";
    std::cin >> ramMemory;
    std::cout << "Enter RAM socket: ";
    std::cin.ignore(); // Очищаем буфер
    std::cin.getline(ramSocket, sizeof(ramSocket));

    RAM myRAM(ramName, ramPrice, ramMemory, ramSocket);

    // Ввод данных для GPU
    char gpuName[100];
    double gpuPrice;
    int gpuMemory;
    double gpuGHz;

    std::cout << "Enter GPU name: ";
    std::cin.getline(gpuName, sizeof(gpuName));
    std::cout << "Enter GPU price: ";
    std::cin >> gpuPrice;
    std::cout << "Enter GPU memory (GB): ";
    std::cin >> gpuMemory;
    std::cout << "Enter GPU GHz: ";
    std::cin >> gpuGHz;
    std::cin.ignore();

    GPU myGPU(gpuName, gpuPrice, gpuMemory, gpuGHz);

    // Ввод данных для Laptop
    char laptopName[100];
    char laptopColor[100];

    std::cout << "Enter laptop name: ";
    std::cin.getline(laptopName, sizeof(laptopName));
    std::cout << "Enter laptop color: ";
    std::cin.getline(laptopColor, sizeof(laptopColor));

    Laptop myLaptop(laptopName, laptopColor, mySSD, myCPU, myRAM, myGPU);

    myLaptop.printLaptopSpecs();

    // Копирование Laptop
    Laptop myCopiedLaptop(myLaptop);
    std::cout << "\nCopied Laptop Details:" << std::endl;
    myCopiedLaptop.printLaptopSpecs();

    return 0;
}
*/