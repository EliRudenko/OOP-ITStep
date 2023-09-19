#include "Car.h"
#include<iostream>
using namespace std;


Car::Car(){}
Car::Car(const char* m, const char* c, int y, double pr)
{
	this->model = new char[strlen(m) + 1];
	strcpy_s(this->model, strlen(m) + 1, m);

	this->color = new char[strlen(c) + 1];
	strcpy_s(this->color, strlen(c) + 1, c);

	this->price = pr;
	this->year = y;
}
Car::~Car()
{
	delete[]this->model;
	delete[]this->color;
}

void Car::Input()
{
	char buff_m[50];
	std::cout << "Enter model: ";
	std::cin >> buff_m;
	if (this->model != nullptr)
	{
		std::cout << "Delete: " << this->model << std::endl;
		delete[]this->model;
	}
	this->model = new char[strlen(buff_m) + 1];
	strcpy_s(this->model, strlen(buff_m) + 1, buff_m);

	
	char buff_c[20];
	std::cout << "Enter color: ";
	std::cin >> buff_c;
	if (this->color != nullptr)
	{
		std::cout << "Delete: " << this->color << std::endl;
		delete[]this->color;
	}
	this->color = new char[strlen(buff_c) + 1];
	strcpy_s(this->color, strlen(buff_c) + 1, buff_c);


	std::cout << "Enter year: ";
	std::cin >> this->year;

	std::cout << "Enter price: ";
	std::cin >> this->price;

}
void Car::Print()
{
	std::cout << "--------------------------" << std::endl;
	std::cout << "Model: " << model << std::endl;
	std::cout << "Color: " << color << std::endl;
	std::cout << "Year: " << year << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "--------------------------" << std::endl;
}

char* Car::GetModel(){ return this->model; }
char* Car::GetColor(){ return this->color;}
int Car::GetYear(){ return this->year; }
double Car::GetPrice(){ return this->price; }

void Car::SetModel(const char* m)
{
	if (this->model == nullptr){ delete[] this->model;}
	this->model = new char[strlen(m) + 1];
	strcpy_s(this->model, strlen(m) + 1, m);
}
void Car::SetColor(const char* c)
{
	if (this->color == nullptr){ delete[] this->color; }
	this->color = new char[strlen(c) + 1];
	strcpy_s(this->color, strlen(c) + 1, c);
}
void Car::SetYear(int y){ this->year = y; }
void Car::SetPrice(double pr){ this->price = pr; }
