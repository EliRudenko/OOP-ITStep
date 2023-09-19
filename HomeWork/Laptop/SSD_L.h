#pragma once

class SSD 
{
private:
    char* SSD_name;
    int memory;
    double price;
    double transfer_speed;

public:
    SSD();
    SSD(const char* inputSSDName);
    SSD(const char* inputSSDName, int inputSSDMemory);
    SSD(const char* inputSSDName, int inputSSDMemory, double inputSSDprice);
    SSD(const char* inputSSDName, int inputSSDMemory, double inputSSDprice, double inputSSDtransfer_speed);
    
    SSD(const SSD& copySSD);

    void set_SSD_name(const char* inputSSDName);
    void set_SSD_memory(int inputSSDMemory);
    void set_SSD_price(double inputSSDprice);
    void set_SSD_transfer_speed(double inputSSDtransfer_speed);

    void print_SSD();

    char* get_SSD_name();
    int get_SSD_memory();
    double get_SSD_price();
    double get_SSD_transfer_speed();

    ~SSD();
};


