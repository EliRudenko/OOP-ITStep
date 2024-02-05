#include <iostream>
using namespace std;

void main()
{
	char buffer[] = "mbstowcs converts ANSI-string to Unicode-string";
	// ��������� ������ ������, ����������� ��� �������� Unicode-������
	int length = mbstowcs(NULL, buffer, 0);
	wchar_t *ptr = new wchar_t[length]; 
	//  ������������ ANSI-������ � Unicode-������
	mbstowcs(ptr, buffer, length);
	wcout << ptr;
	cout << "\nLength of Unicode-string: " << length << endl;
	cout << "Size of allocated memory: " << _msize(ptr) << " bytes" << endl;
	delete[] ptr;
}

