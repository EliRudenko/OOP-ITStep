
#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#include <iostream>

#include "Transport.cpp"
#include "Tram.cpp"
#include "Ship.cpp"
#include "Plane.cpp"
#include "Motorcycle.cpp"
#include "Car.cpp"


int main() 
{
    Transport* ptr = nullptr;

    int ch;
    std::cout << "1. Car" << std::endl;
    std::cout << "2. Ship" << std::endl;
    std::cout << "3. Airplane" << std::endl;
    std::cout << "4. Tram" << std::endl;
    std::cout << "5. Motorcycle" << std::endl;
    std::cin >> ch;

    switch (ch) 
    {
        case 1: 
            ptr = new Car();
            ptr->Input();
            break;
        case 2: 
            ptr = new Ship();
            ptr->Input();
            break;
        case 3: 
            ptr = new Plane();
            ptr->Input();
            break;
        case 4: 
            ptr = new Tram();
            ptr->Input();
            break;
        case 5: 
            ptr = new Motorcycle();
            ptr->Input();
            break;
        default:
            break;
    }

    if (ptr) 
    {
        ptr->display();
        delete ptr;
    }

    return 0;
}