#include <iostream>
#include <string>
using namespace std;

class Device 
{
public:
    virtual void ShowDetails() = 0;
    virtual ~Device() {}
};

class VideoCard : public Device 
{
public:
    void ShowDetails() override { cout << "Video Card: NVIDIA GeForce GTX 1660 Ti" << endl; }
};
class Processor : public Device 
{
public:
    void ShowDetails() override { cout << "Processor: Intel Core i7-10750H" << endl; }
};
class HardDrive : public Device 
{
public:
    void ShowDetails() override { cout << "Hard Drive: 512GB PCIe SSD" << endl; }
};
class RAM : public Device 
{
public:
    void ShowDetails() override { cout << "RAM: 16GB DDR4 2933MHz" << endl; }
};


class DeviceReport 
{
protected:
    Device* device;
public:
    DeviceReport(Device* dev) : device(dev) {}
    virtual void DisplayInfo() = 0;
    virtual ~DeviceReport() { delete device; }
};

class BasicDeviceReport : public DeviceReport 
{
public:
    BasicDeviceReport(Device* dev) : DeviceReport(dev) {}
    void DisplayInfo() override { device->ShowDetails(); }
};

int main() 
{
    cout << endl;
    Device* gpu = new VideoCard();
    DeviceReport* gpuReport = new BasicDeviceReport(gpu);
    gpuReport->DisplayInfo();
    delete gpuReport;

    Device* cpu = new Processor();
    DeviceReport* cpuReport = new BasicDeviceReport(cpu);
    cpuReport->DisplayInfo();
    delete cpuReport;

    Device* hdd = new HardDrive();
    DeviceReport* hddReport = new BasicDeviceReport(hdd);
    hddReport->DisplayInfo();
    delete hddReport;

    cout << endl;
    Device* ram = new RAM();
    DeviceReport* ramReport = new BasicDeviceReport(ram);
    ramReport->DisplayInfo();
    delete ramReport;

    cout << endl;
    return 0;
}
