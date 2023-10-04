#include <iostream>

#include "Circle.h"

using namespace std;

void Circle::ShowArea() const
{
    cout << "Area of circle: " << 3.14159 * m_value1 * m_value2 << endl;
}