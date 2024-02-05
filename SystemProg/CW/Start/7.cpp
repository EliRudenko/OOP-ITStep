#include <iostream>
using namespace std;

void main()
{
	wchar_t buffer[] = L"wcstombs converts Unicode-string to ANSI-string";
	// ��������� ������ ������, ����������� ��� �������� ��������������� ANSI-������
	int length = wcstombs(NULL, buffer, 0);
	char *ptr = new char[length + 1]; 
	// ������������ Unicode-������ � ANSI-������ 
	wcstombs(ptr, buffer, length + 1);
	cout << ptr;
	cout << "\nLength of ANSI-string: " << strlen(ptr) << endl;
	cout << "Size of allocated memory: " << _msize(ptr) << " bytes" << endl;
	delete[] ptr;
}
