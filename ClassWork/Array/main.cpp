#include<iostream>
#include "Array.cpp"

int main()
{
	Array ar(10);
	for (int i = 0; i < 10; i++)
	{
		std::cout << ar[i] << "\t";
	}
	std::cout << std::endl;

	ar[8];


}