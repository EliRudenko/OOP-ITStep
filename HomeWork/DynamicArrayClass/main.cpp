#include "DynamicArray.h"
#include <iostream>


DynamicArray GetObj() 
{
	DynamicArray obj(3);
	obj.Input();

	return obj;
}

int main()
{
	DynamicArray a(8); // constructor 1 param
	a.Input();
	a.Output();


	DynamicArray b (3); // copy constructor
	b.Input();

	//DynamicArray rezult = GetObj();
	//DynamicArray result = a + 10;

	DynamicArray Add10 = a + 10;
	std::cout << "Add10" << std::endl;
	Add10.Output();

	
	DynamicArray Minus = a - 2;
	std::cout << "Minus" << std::endl;
	Minus.Output();
	
	DynamicArray Mult = a * 2;
	std::cout << "Mult" << std::endl;
	Mult.Output();

	
	DynamicArray Subtr_arr = a - b;
	std::cout << "Subtr_arr";
	Subtr_arr.Output();
	

	DynamicArray Sum_arr = a + b;
	std::cout << "Sum_arr" ;
	Sum_arr.Output();

	
	DynamicArray Incr(5);
	Incr.Input();
	++Incr;
	std::cout << "Incr";
	Incr.Output();
	

	
	DynamicArray Dicr(5);
	Dicr.Input();
	--Dicr;
	std::cout << "Dicr";
	Dicr.Output();

	return 0;
}



