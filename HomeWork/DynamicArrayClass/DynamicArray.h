#pragma once

class DynamicArray
{
	int* ptr; // указатель на динам. массив
	int size;  // размер массива 
public:
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&); // copy constructor
	~DynamicArray();
	void Input();// rand
	void Output();// вывод на консоль
	int* GetPointer();
	int GetSize();


	void ReSize(int size);
	void Sort();
	int Search(int a);
	void Reverse();


	DynamicArray operator+(int new_size); // DynamicArray rez = a + 10;  увеличиваем кол-во элементов на 10
	DynamicArray operator-(int count_for_del); //ez = a - 2;  удаляем последние 2 элемента, если размер >2
	DynamicArray operator*(int mult); //rez = a * 2; значение каждого элемента массива умножаем на 2, возвращаем новый массив!
	
	
	DynamicArray operator-(const DynamicArray& new_arr_dicr); // разность массивов
	DynamicArray operator+(DynamicArray new_arr_incr); // конкатенация массивов
	DynamicArray& operator++(); // увеличиваем количество элементов на 1(значение 0).
	DynamicArray& operator--(); // увеличиваем количество элементов на 1(значение 0).




};


// реилизовать следующие методы:
	//void ReSize(int size);// изменение размера массива
	//void Sort();// сортировка(любой алгоритм сортировки)
	//int Search(int a); // поиск элемента в массиве, возвращает индекс наиденного эл., либо -1.
	//void Reverse(); // перезаписывает последовательность элементов в обратном порядке, напрмер 12345 -> 54321
