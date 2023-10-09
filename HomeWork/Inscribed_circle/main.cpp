
#include <iostream>
#include "circle_in_square.cpp"

int main() {
    CircleInSquare obj(5);
    
    if (obj.fitsInside()) 
    {
        std::cout << "The circle fits inside the square." << std::endl;
    } else { std::cout << "The circle does not fit inside the square." << std::endl; }
    
    return 0;
}
