#include<iostream>
#include "Array.cpp"
#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

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