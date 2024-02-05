#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//typedef int возврат
//typedef unsigned short int wchar_t


void main()
{

	//// ANSI-кодировка
	char szBuf1[15] = "Hello,";
	strcat(szBuf1, " world!");
	cout << sizeof(szBuf1) << " bytes\n"; // 15 байт

	// UNICODE-кодировка
	//для преобразования из анси в юни используют L
	wchar_t szBuf2[15] = L"Hello,";
	wcscat(szBuf2, L" world!");
	cout << sizeof(szBuf2) << " bytes\n"; // 30 байт






	system("pause");
}

