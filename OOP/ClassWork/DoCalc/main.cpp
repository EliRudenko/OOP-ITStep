#include <iostream>

#include "Value_calculator.cpp"
#include "Size_exception.cpp"
#include "Data_exception.cpp"


int main() 
{
    std::string array[4][4] = {{"1", "2", "3", "4"}, {"4", "3", "2", "1"}, {"8", "2", "2", "8"}, {"2", "8", "8", "2"}};

    try 
    {
        int result = Value_calculator::doCalc(array);
        std::cout << "Result: " << result << std::endl;
    } 
    catch (const Exception& error) 
    {
        std::cerr << "Error: " << error.m() << std::endl;
    }

    return 0;
}
