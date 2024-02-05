#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
using namespace std;

void main()
{
	char buffer[] = "MultiByteToWideChar converts ANSI-string to Unicode-string";//59
	// ��������� ������ ������, ����������� ��� �������� Unicode-������
	int length = MultiByteToWideChar(CP_ACP /*ANSI code page*/, 0, buffer, -1, NULL, 0);
	cout << "Length = " << length << endl;
	
	wchar_t *ptr = new wchar_t [length]; 
	// ������������ ANSI-������ � Unicode-������
	MultiByteToWideChar(CP_ACP, 0, buffer, -1, ptr, length);
	wcout << ptr << endl;
	cout << "Length of Unicode-string: " << wcslen(ptr) << endl;
	cout << "Size of allocated memory: " << _msize(ptr) << endl;//118
	delete [] ptr;

	system("pause");
}
