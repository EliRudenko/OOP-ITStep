#include "Point.h"
#include <iostream>

Point::Point(int a, int b)
{
	x = a;
	y = b;
}

void Point::Init(int a, int b)
{
	x = a;
	y = b;
}

void Point::Print()
{
	std::cout << x << "/" << y << std::endl;

}

/*
Point Point::Sum(Point b)
{
	Point rez;
	rez.x = this->x + b.x;
	rez.y = this->y + b.y;
	return rez;

	//return Point(this->x+b.x, this->y+b.y);
}+

Point Point::Sum(int b)
{
	return Point(this->x + b, this->y + b);
}
*/

Point Point::operator +(Point b)
{
	Point rez;
	rez.x = this->x + b.x;
	rez.y = this->y + b.y;
	return rez;

	//return Point(this->x+b.x, this->y+b.y);
}

Point Point::operator +(int b)
{
	return Point(this->x + b, this->y + b);
}




Point Point::operator -(Point b)
{
	Point rez;
	rez.x = this->x - b.x;
	rez.y = this->y - b.y;
	return rez;
}

Point Point::operator -(int b)
{
	return Point(this->x - b, this->y - b);
}



int Point::operator*(Point b)
{
	int rez;
	rez = (this->x * b.x) * (this->y * b.y);
	return rez; 
}

int Point::operator*(int b)
{
	int rez;
	rez = (this->x * b, this->y * b);
	return rez; 
}



Point& Point::operator++()
{
	x += 10;
	y += 10;
	return *this;
}
Point& Point::operator--()
{
	x -= 10;
	y -= 10;
	return *this;
}

Point& Point::operator++(int a)
{
	Point temp(x, y);

	x += 10;
	y += 10;

	return temp;
	
}
Point& Point::operator--(int a)
{

	Point temp(x, y);

	x -= 10;
	y -= 10;

	return temp;
}


Point& Point::operator+=(int a)
{
	x += a;
	y += a;

	return *this;
}
Point& Point::operator-=(int a)
{
	x -= a;
	y -= a;

	return *this;
}
Point& Point::operator*=(int a)
{
	x *= a;
	y *= a;

	return *this;
}
Point& Point::operator/=(int a)
{
	x /= a;
	y /= a;

	return *this;
}


bool Point::operator>(Point& b)
{
	if (x > b.x && y > b.y) { return true;}

	return false;
}
bool Point::operator>=(Point& b)
{
	if (x >= b.x && y >= b.y) { return true; }

	return false;
}
bool Point::operator<(Point& b)
{
	if (x < b.x && y < b.y) { return true; }

	return false;
}
bool Point::operator<(Point& b)
{
	if (x <= b.x && y <= b.y) { return true; }

	return false;
}
