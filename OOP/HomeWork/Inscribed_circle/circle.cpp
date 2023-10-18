
#include "Circle.h"
#include <cmath>

Circle::Circle(double r) : radius(r) {}

double Circle::getRadius() { return radius; }

double Circle::getArea() { return 3.14 * pow(radius, 2); }
