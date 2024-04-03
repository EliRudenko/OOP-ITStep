#include <iostream>
#include <string>

class PowerSupply 
{
public:
    void powerOn() { std::cout << "Power supply: Power on"<< std::endl; }

    void powerOff() { std::cout << "Power supply: Power off" << std::endl; }
};

class Sensor 
{
public:
    bool checkVoltage() 
    {
        std::cout << "Sensor: Checking voltage  -  ";
        std::cout << "OK"<< std::endl;
        return true;
    }

    bool checkTemperature(std::string device) 
    {
        std::cout << "Sensor: Checking temperature in " << device << "  -  ";
        std::cout << "OK" << std::endl;
        return true;
    }
};

class VideoCard 
{
public:
    void start() {  std::cout << "Video card: Starting"<< std::endl; }

    void connectToMonitor() { std::cout << "Video card: Connecting to monitor"<< std::endl; }

    void outputData(std::string data) { std::cout << "Video card: Outputting data about " << data << std::endl;; }

    void farewellMessage() {  std::cout << "Video card: Farewell message displayed on monitor"<< std::endl; }
};

class RAM 
{
public:
    void startDevices() { std::cout << "RAM: Starting devices"<< std::endl; }

    void analyzeMemory() { std::cout << "RAM: Analyzing memory"<< std::endl; }

    void clearMemory() { std::cout << "RAM: Clearing memory"<< std::endl; }
};

class HardDrive 
{
public:
    void start() { std::cout << "Hard drive: Starting"<< std::endl; }

    bool checkBootSector() 
    {
        std::cout << "Hard drive: Checking boot sector  -  ";
        std::cout << "OK" << std::endl;
        return true;
    }
};

class ComputerFacade 
{
    PowerSupply powerSupply;
    Sensor sensor;
    VideoCard videoCard;
    RAM ram;
    HardDrive hardDrive;

public:
    void beginWork() 
    {
        std::cout << std::endl;
        powerSupply.powerOn();

        if (sensor.checkVoltage() && sensor.checkTemperature("power supply") && sensor.checkTemperature("video card")) 
        {
            powerSupply.powerOn();
            videoCard.start();
           
            std::cout << std::endl; 
            videoCard.connectToMonitor();
            
            std::cout << std::endl; 
            sensor.checkTemperature("RAM");
            powerSupply.powerOn();
            ram.startDevices();
            
            std::cout << std::endl; 
            ram.analyzeMemory();
 
            videoCard.outputData("RAM");
            powerSupply.powerOn();
            hardDrive.start();
            if (hardDrive.checkBootSector()) { videoCard.outputData("hard drive"); }

            std::cout << std::endl; 
            sensor.checkTemperature("all systems");
        }
    }

    void endWork()
    {
        hardDrive.start();

        std::cout << std::endl; 
        ram.clearMemory();
        ram.analyzeMemory();

        std::cout << std::endl;
        videoCard.farewellMessage();
        powerSupply.powerOff();
        std::cout << std::endl; 
    }
};

int main() 
{
    std::cout << "Beginning computer boot !" << std::endl;
    ComputerFacade facade;
    facade.beginWork();
    std::cout << "Shutting down computer !" << std::endl;
    facade.endWork();
    std::cout << std::endl; 

    return 0;
}
