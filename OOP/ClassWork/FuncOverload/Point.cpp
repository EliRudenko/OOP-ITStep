#include "Point.h"
#include <time.h>
#include <iostream>

Point::Point()
{
    std::cout << "Construct" << std::endl;
    x = y = 0;
}

Point::Point(int x1, int y1)
{
    std::cout << "Construct by 2 param" << std::endl;
    x = x1;
    y = y1;
}

void Point::Init()
{
    x = rand() % 10;
    y = rand() % 10;
}

void Point::Init(int x1, int y1)
{
    x = x1;
    y = y1;
}

void Point::Output()
{
    std::cout << "X: " << x << std::endl; 
    std::cout << "Y: " << y << std::endl;
}

Point Point::operator+(int value)
{
    Point result;
    result.x = x + value;
    result.y = y + value;
    return result;
}

Point Point::operator++()
{
    x++;
    y++;
    return *this;
}

Point Point::operator++(int)
{
    Point temp(*this);
    operator++(); // οπετ
    return temp;
}
