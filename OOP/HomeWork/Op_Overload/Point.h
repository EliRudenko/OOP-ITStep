#pragma once

class Point
{
	int x;
	int y;

public:

	Point() = default;
	Point(int a, int b);

	void Init(int a, int b);
	void Print();


	//Point Sum(Point b);
	//Point Sum(int b);


	Point operator +(Point b);
	Point operator +(int b);

	Point operator -(Point b);
	Point operator -(int b);

	int operator *(Point b);
	int operator *(int b);

	//int operator /(Point b);
	//int operator /(int b);

	Point& operator++();
	Point& operator--();


	Point& operator++(int a);
	Point& operator--(int a);


	Point& operator+=(int a);
	Point& operator-=(int a);
	Point& operator*=(int a);
	Point& operator/=(int a);



	bool operator>(Point& b);
	bool operator>=(Point& b);
	bool operator<(Point& b);
	bool operator<=(Point& b);

};

