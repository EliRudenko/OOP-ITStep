#pragma once

#include "Circle.h"
#include "Square.h"

class CircleInSquare : public Circle, public Square 
{
public:
    CircleInSquare(double r);
    bool fitsInside();
};
