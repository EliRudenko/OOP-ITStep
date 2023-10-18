
#include "circle_in_square.h"

CircleInSquare::CircleInSquare(double r) : Circle(r), Square(2*r) {}

// ибо если радиус окружности в два раза мень чем сторона квадрата => можно вписать
bool CircleInSquare::fitsInside() { return getRadius() == (getSide() / 2); }