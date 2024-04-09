#include <iostream>

#include <fstream>
#include <string>

#include <vector>
#include <algorithm>

class CPU;
class Disk;
class RAM;

class IVisitor 
{
public:
    virtual void VisitCPU(CPU* cpu) = 0;
    virtual void VisitDisk(Disk* disk) = 0;
    virtual void VisitRAM(RAM* ram) = 0;
};

class Device 
{
    std::string Brand;
public:
    virtual void Accept(IVisitor* visitor) = 0;
    std::string GetBrand() { return Brand; }

    void SetBrand(std::string brand) { this->Brand = brand; }
};

class CPU: public Device 
{
    std::string ClockSpeed;
    std::string CoreCount;
public:
    std::string GetClockSpeed() { return ClockSpeed; }

    void SetClockSpeed(std::string clockSpeed) { this->ClockSpeed = clockSpeed; }

    std::string GetCoreCount() { return CoreCount; }

    void SetCoreCount(std::string coreCount) { this->CoreCount = coreCount; }

    void Accept(IVisitor* visitor) override;
};

class Disk: public Device 
{
    std::string Capacity;
    std::string Type;
public:
    std::string GetCapacity() { return Capacity; }

    void SetCapacity(std::string capacity) { this->Capacity = capacity;}

    std::string GetType() { return Type; }

    void SetType(std::string type) { this->Type = type; }

    void Accept(IVisitor* visitor) override;
};

class RAM : public Device 
{
    int TotalCapacity;
    int AvailableCapacity;
public:
    int GetTotalCapacity() { return TotalCapacity; }

    void SetTotalCapacity(int totalCapacity) { this->TotalCapacity = totalCapacity; }

    int GetAvailableCapacity() { return AvailableCapacity; }

    void SetAvailableCapacity(int availableCapacity) { this->AvailableCapacity = availableCapacity; }

    void Accept(IVisitor* visitor) override;
};

class HTMLVisitor : public IVisitor 
{
public:
    void VisitCPU(CPU* cpu) override;
    void VisitDisk(Disk* disk) override;
    void VisitRAM(RAM* ram) override;
};

class XMLVisitor: public IVisitor 
{
public:
    void VisitCPU(CPU* cpu) override;
    void VisitDisk(Disk* disk) override;
    void VisitRAM(RAM* ram) override;
};

class ConsoleVisitor : public IVisitor 
{
public:
    void VisitCPU(CPU* cpu) override;
    void VisitDisk(Disk* disk) override;
    void VisitRAM(RAM* ram) override;
};

class Computer 
{
    std::vector<Device*> devices;
public:
    void Add(Device* device) { devices.push_back(device); }

    void Remove(Device* device) 
    {
        auto iter = std::find(devices.begin(), devices.end(), device);
        if(iter != devices.end())
            devices.erase(iter);
    }
    void Accept(IVisitor* visitor) 
    {
        for(Device* device : devices)
            device->Accept(visitor);
    }
};

void CPU::Accept(IVisitor* visitor) { visitor->VisitCPU(this); }

void Disk::Accept(IVisitor* visitor) { visitor->VisitDisk(this); }

void RAM::Accept(IVisitor* visitor) { visitor->VisitRAM(this); }

void HTMLVisitor::VisitCPU(CPU* cpu) 
{
    std::ofstream out("CPU.html", std::ios::binary | std::ios::trunc | std::ios::out);
    std::string result = "<html><head></head><body>";
   
    result += "<table><tr><td>Property<td><td>Value</td></tr>";
    result += "<tr><td>Brand<td><td>" + cpu->GetBrand() + "</td></tr>";
    result += "<tr><td>ClockSpeed<td><td>" + cpu->GetClockSpeed() + "</td></tr>";
    result += "<tr><td>CoreCount<td><td>" + cpu->GetCoreCount() + "</td></tr></table>";
    result += "</body></html>";
   
    out.write(result.c_str(), result.size());
    out.close();
}

void HTMLVisitor::VisitDisk(Disk* disk) 
{
    std::ofstream out("Disk.html", std::ios::binary | std::ios::trunc | std::ios::out);
    std::string result = "<html><head></head><body>";
    
    result += "<table><tr><td>Property<td><td>Value</td></tr>";
    result += "<tr><td>Brand<td><td>" + disk->GetBrand() + "</td></tr>";
    result += "<tr><td>Type<td><td>" + disk->GetType() + "</td></tr>";
    result += "<tr><td>Capacity<td><td>" + disk->GetCapacity() + "</td></tr></table>";
    result += "</body></html>";
   
    out.write(result.c_str(), result.size());
    out.close();
}

void HTMLVisitor::VisitRAM(RAM* ram) 
{
    std::ofstream out("RAM.html", std::ios::binary | std::ios::trunc | std::ios::out);
    std::string result = "<html><head></head><body>";
    
    result += "<table><tr><td>Property<td><td>Value</td></tr>";
    result += "<tr><td>Brand<td><td>" + ram->GetBrand() + "</td></tr>";
    result += "<tr><td>TotalCapacity<td><td>" + std::to_string(ram->GetTotalCapacity()) + " GB</td></tr>";
    result += "<tr><td>AvailableCapacity<td><td>" + std::to_string(ram->GetAvailableCapacity()) + " GB</td></tr></table>";
    result += "</body></html>";
   
    out.write(result.c_str(), result.size());
    out.close();
}

void XMLVisitor::VisitCPU(CPU* cpu) 
{
    std::ofstream out("CPU.xml", std::ios::binary | std::ios::trunc | std::ios::out);
    std::string result = "<?xml version='1.0' encoding='UTF-8'?>";
    
    result += "<CPU><Brand>" + cpu->GetBrand() + "</Brand>" + "<ClockSpeed>" + cpu->GetClockSpeed() + "</ClockSpeed>" + "<CoreCount>" + cpu->GetCoreCount() + "</CoreCount></CPU>";
    
    out.write(result.c_str(), result.size());
    out.close();
}

void XMLVisitor::VisitDisk(Disk* disk) 
{
    std::ofstream out("Disk.xml", std::ios::binary | std::ios::trunc | std::ios::out);
    std::string result = "<?xml version='1.0' encoding='UTF-8'?>";
    
    result += "<Disk><Brand>" + disk->GetBrand() + "</Brand>" + "<Type>" + disk->GetType() + "</Type>" + "<Capacity>" + disk->GetCapacity() + "</Capacity></Disk>";
    
    out.write(result.c_str(), result.size());
    out.close();
}

void XMLVisitor::VisitRAM(RAM* ram) 
{
    std::ofstream out("RAM.xml", std::ios::binary | std::ios::trunc | std::ios::out);
    std::string result = "<?xml version='1.0' encoding='UTF-8'?>";
    
    result += "<RAM><Brand>" + ram->GetBrand() + "</Brand>" + "<TotalCapacity>" + std::to_string(ram->GetTotalCapacity()) + " GB</TotalCapacity>" + "<AvailableCapacity>" + std::to_string(ram->GetAvailableCapacity()) + " GB</AvailableCapacity></RAM>";
    
    out.write(result.c_str(), result.size());
    out.close();
}

void ConsoleVisitor::VisitCPU(CPU* cpu) 
{
    std::cout << "CPU Information"<< std::endl;
    std::cout << "Brand: " << cpu->GetBrand() << std::endl;
    std::cout << "Clock Speed: " << cpu->GetClockSpeed() << std::endl;
    std::cout << "Core Count: " << cpu->GetCoreCount() << std::endl;
    std::cout << std::endl;
}

void ConsoleVisitor::VisitDisk(Disk* disk) 
{
    std::cout << "Disk Information" << std::endl;
    std::cout << "Brand: " << disk->GetBrand() << std::endl;
    std::cout << "Type: " << disk->GetType() << std::endl;
    std::cout << "Capacity: " << disk->GetCapacity() << std::endl;
    std::cout << std::endl;
}

void ConsoleVisitor::VisitRAM(RAM* ram) 
{
    std::cout << "RAM Information" << std::endl;
    std::cout << "Brand: " << ram->GetBrand() << std::endl;
    std::cout << "Total Capacity: " << ram->GetTotalCapacity() << " GB" << std::endl;
    std::cout << "Available Capacity: " << ram->GetAvailableCapacity() << " GB" << std::endl;
    std::cout << std::endl;
}

int main() 
{
    Computer* computer = new Computer();
    CPU *cpu = new CPU;
    cpu->SetBrand("Intel");
    cpu->SetClockSpeed("3.5 GHz");
    cpu->SetCoreCount("4");
    computer->Add(cpu);
    
    Disk *disk = new Disk;
    disk->SetBrand("Western Digital");
    disk->SetType("SATA III");
    disk->SetCapacity("2 TB");
    computer->Add(disk);
    
    RAM* ram = new RAM;
    ram->SetBrand("Crucial");
    ram->SetTotalCapacity(32);
    ram->SetAvailableCapacity(30);
    computer->Add(ram);
    
    HTMLVisitor *htmlVisitor = new HTMLVisitor;
    computer->Accept(htmlVisitor);
    XMLVisitor *xmlVisitor = new XMLVisitor;
    computer->Accept(xmlVisitor);
    ConsoleVisitor* consoleVisitor = new ConsoleVisitor;
    computer->Accept(consoleVisitor);
    
    delete htmlVisitor;
    delete xmlVisitor;
    delete disk;
    delete cpu;
    delete computer;
}
