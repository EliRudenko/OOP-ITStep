#pragma once

class DynamicArray
{
	int* ptr; // ��������� �� �����. ������
	int size;  // ������ ������� 
public:
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&); // copy constructor
	~DynamicArray();
	void Input();// rand
	void Output();// ����� �� �������
	int* GetPointer();
	int GetSize();


	void ReSize(int size);
	void Sort();
	int Search(int a);
	void Reverse();


	DynamicArray operator+(int new_size); // DynamicArray rez = a + 10;  ����������� ���-�� ��������� �� 10
	DynamicArray operator-(int count_for_del); //ez = a - 2;  ������� ��������� 2 ��������, ���� ������ >2
	DynamicArray operator*(int mult); //rez = a * 2; �������� ������� �������� ������� �������� �� 2, ���������� ����� ������!
	
	
	DynamicArray operator-(const DynamicArray& new_arr_dicr); // �������� ��������
	DynamicArray operator+(DynamicArray new_arr_incr); // ������������ ��������
	DynamicArray& operator++(); // ����������� ���������� ��������� �� 1(�������� 0).
	DynamicArray& operator--(); // ����������� ���������� ��������� �� 1(�������� 0).




};


// ����������� ��������� ������:
	//void ReSize(int size);// ��������� ������� �������
	//void Sort();// ����������(����� �������� ����������)
	//int Search(int a); // ����� �������� � �������, ���������� ������ ���������� ��., ���� -1.
	//void Reverse(); // �������������� ������������������ ��������� � �������� �������, ������� 12345 -> 54321
