#pragma once

class RAM 
{
private:
    char* RAM_name;
    double price;
    int memory;

public:
    RAM();
    RAM(const char* inputRAMName, double inputPrice, int inputMemory);
    
    RAM(const RAM& copyRAM);

    void set_RAM_name(const char* inputRAMName);
    void set_price(double inputPrice);
    void set_memory(int inputMemory);

    void print_RAM();

    char* get_RAM_name();
    double get_price();
    int get_memory();

    ~RAM();
};

