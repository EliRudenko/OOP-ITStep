#include <iostream>



int main()
{
    short value = 8;
    short *ptr = &value;
 
    std::cout << ptr << '\n';
    std::cout << ptr + 1 << '\n';
    std::cout << ptr + 2 << '\n';
    std::cout << ptr + 3 << '\n';
 
    return 0;
}