#include "DynamicArray.h"
#include <iostream>

DynamicArray::DynamicArray() :ptr(nullptr), size(0)
{}
DynamicArray::DynamicArray(int S)
{
	std::cout << "*Construct by 1 param" << std::endl;
	size = S;
	ptr = new int[S];
}

DynamicArray::DynamicArray(const DynamicArray& a)// copy constructor
{
	std::cout << "*Copy construct" << std::endl;
	size = a.size;
	ptr = new int[size];
	for (int i = 0; i < size; i++) { ptr[i] = a.ptr[i]; }
}

DynamicArray::~DynamicArray()
{
	std::cout << "*Destruct" << std::endl;
	delete[] ptr;
	//Sleep(1000);
}


void DynamicArray::Input()
{
	for (int i = 0; i < size; i++) { ptr[i] = rand() % 20; }
}
void DynamicArray::Output()
{
	//std::cout << std::endl;
	std::cout << std::endl << "------------------------------------------------" << std::endl;
	for (int i = 0; i < size; i++) { std::cout << ptr[i] << "\t"; }
	std::cout << std::endl << "------------------------------------------------" << std::endl;
}
int* DynamicArray::GetPointer() { return ptr; }
int DynamicArray::GetSize() { return size; }


//HW


void DynamicArray::ReSize(int newSize)
{
	if (newSize == size) { return; } // размер не поменялся менять не надо

	int* new_ptr = new int[newSize]; // память под новый массив
	int copy_size; // размер для копированния 

	// проверка, новый размер меньше 
	if (newSize < size) 
	{
		copy_size = newSize;
	}
	else { copy_size = size; } // копирование кол эллементов
	
	for (int i = 0; i < copy_size; i++) { new_ptr[i] = ptr[i]; } // копируется эллементы из старого 

	for (int i = copy_size; i < newSize; i++) { new_ptr[i] = 0; } //новые эллементы = 0

	delete[] ptr;
	ptr = new_ptr;
	size = newSize;
}
void DynamicArray::Sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (ptr[j] > ptr[j + 1])
			{
				int temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
			}
		}
	}
}
int DynamicArray::Search(int a)
{

	for (int i = 0; i < size; i++)
	{
		if (ptr[i] == a) { return i; } 
	}
	return -1;
}
void DynamicArray::Reverse()
{
	int left_border = 0;
	int right_border = size - 1;

	while (left_border < right_border)
	{
		int temp = ptr[left_border];
		ptr[left_border] = ptr[right_border];
		ptr[right_border] = temp;

		left_border++;
		right_border--;
	}
}


 
//HW 2


DynamicArray DynamicArray::operator+(int new_size)
{
	DynamicArray temp(size + new_size);

	for (int i = 0; i < size; i++) { temp.ptr[i] = ptr[i]; }

	for (int i = size; i < temp.size; i++) { temp.ptr[i] = 0; }

	return temp;
}


DynamicArray DynamicArray::operator*(int mult)
{
	DynamicArray temp;
	temp.size = this->size;
	temp.ptr = new int[temp.size];

	for (int i = 0; i < size; i++) { temp.ptr[i] = ptr[i]; }


	for (int i = 0; i < temp.size; i++) { temp.ptr[i] *= mult; }


	return temp;
}

DynamicArray DynamicArray::operator-(int count_for_del)
{
	int newSize;
	if (count_for_del >= size)
	{
		newSize = 0;
	}
	else { newSize = size - count_for_del; }

	DynamicArray temp(newSize);

	for (int i = 0; i < newSize; i++) { temp.ptr[i] = ptr[i]; }

	return temp;
}


DynamicArray DynamicArray::operator-(const DynamicArray& new_arr_dicr)
{
	if (size != new_arr_dicr.size) { return *this; } // Проверка, ибо операция не выполнится, вернет копию

	DynamicArray temp(size);

	for (int i = 0; i < size; i++) { temp.ptr[i] = ptr[i] - new_arr_dicr.ptr[i]; }

	return temp;
}

DynamicArray DynamicArray::operator+(DynamicArray new_arr_incr)
{
	DynamicArray temp(size + new_arr_incr.size);


	for (int i = 0; i < size; i++) { temp.ptr[i] = ptr[i]; }

	for (int i = size; i < temp.size; i++) { temp.ptr[i] = new_arr_incr.ptr[new_arr_incr.size - i - 1]; }

	return temp;
}

DynamicArray& DynamicArray::operator++()
{
	++this->size;
	ptr[this->size - 1] = 0;

	return *this;
}


DynamicArray& DynamicArray::operator--()
{
	int temp_size = --size;

	int* temp = new int[temp_size];

	for (int i = 0; i < temp_size; ++i)
	{

		temp[i] = this->ptr[i];
	}
	
	delete[] this->ptr;
	this->ptr = temp;
	this->size = temp_size;

	return *this;

}


























