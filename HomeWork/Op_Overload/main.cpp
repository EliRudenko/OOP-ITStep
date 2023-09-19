#include <iostream>
#include "Point.h"

int main()
{
	Point a(10, 20);
	Point b(30, 40);

	//a.Print();
	//b.Print();

	/*
	Point rez = a.Sum(b); //обьект + обьект a+b
	rez.Print();

	rez = a.Sum(10); // обьект  + число, первый параметр  не явно передается
	rez.Print();
	*/


	//Point rez = a + b; //обьект + обьект a+b
	//одно и то же

	
	Point rez = a.operator + (b); //обьект + обьект a+b
	std::cout << "a+b: ";
	rez.Print();

	rez = a + 10; // обьект  + число, первый параметр  не явно передается
	std::cout << "a+10: ";
	rez.Print();


	Point rez2 = a.operator - (b); //обьект + обьект a+b
	std::cout << "a-b: ";
	rez2.Print();

	rez2 = a - 10; // обьект  + число, первый параметр  не явно передается
	std::cout << "a+10: ";
	rez2.Print();
	

	int rez_prod = a * (b); //обьект + обьект a+b
	std::cout << "a*b: ";
	std::cout << rez_prod << std::endl;

	rez_prod = a * 10; // обьект  + число, первый параметр  не явно передается
	std::cout << "a*b: ";
	std::cout << rez_prod << std::endl;


	Point rez_incr = ++a; 
	rez_incr.Print();


	Point rez_dicr = --a;
	rez_dicr.Print();


	if (a > b)
	{

	}

}