#include <windows.h>
#include <iostream>
using namespace std;

void main()
{
	wchar_t buffer[] = L"WideCharToMultiByte converts Unicode-string to ANSI-string";
	// ��������� ������ ������, ����������� ��� �������� ANSI-������
	int length = WideCharToMultiByte(CP_ACP /*ANSI code page*/, 0, buffer, -1, NULL, 0, 0, 0);
	char *ptr = new char[length];
	// ������������ Unicode-������ � ANSI-������
	WideCharToMultiByte(CP_ACP, 0, buffer, -1, ptr, length, 0, 0); 
	cout << ptr << endl;
	cout << "Length of ANSI-string: " << strlen(ptr) << endl;
	cout << "Size of allocated memory: " << _msize(ptr) << endl;
	delete[] ptr;

	system("pause");
}