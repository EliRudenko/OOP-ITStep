
#include "Square.h"

Square::Square(double s) : side(s) {}

double Square::getSide() { return side; }

double Square::getArea() { return side * side; }
