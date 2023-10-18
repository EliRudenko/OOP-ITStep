#pragma once

class GPU 
{
private:

    char* GPU_name;
    double price;
    int memory;
    double GHz;

public:

    GPU();
    GPU(const char* inputGPUName);
    GPU(const char* inputGPUName, double inputGPUPrice);
    GPU(const char* inputGPUName, double inputGPUPrice, int inputGPUMemory);
    GPU(const char* inputGPUName, double inputGPUPrice, int inputGPUMemory, double inputGPUGHz);
    
    GPU(const GPU& copyGPU);

    void set_GPU_name(const char* inputGPUName);
    void set_GPU_price(double inputGPUPrice);
    void set_GPU_memory(int inputGPUMemory);
    void set_GPU_GHz(double inputGPUGHz);

    void print_GPU();

    char* get_GPU_name();
    double get_GPU_price();
    int get_GPU_memory();
    double get_GPU_GHz();

    ~GPU();
};
