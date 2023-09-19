#include "My_String.h"
#include <iostream>

int main() 
{
    MyString str1; 
    MyString str2(100);
    MyString str3("Hello, World!");

    //ВВОД ВЫВОД
    str1.Input();
    str1.Print();

    str2.Input();
    str2.Print();

    str3.Print();

    // копирование строк
    str1.MyStrCat(str2);
    str1.Print();

    // удаляет указанный символ 
    str1.MyDelChr('e');
    str1.Print();
    
    // возвращает длину строки
    std::cout << "Length of str1: " << str1.MyStrLen() << std::endl;


    // поиск символа в строке(индекс найденного символа, либо -1)
    int index = str1.MyChr('H');
    if (index != -1) 
    {
        std::cout << "'H' found at index: " << index << std::endl;
    }
    else { std::cout << "'H' not found" << std::endl;}

    // поиск подстроки в строке
    bool contains = str1.MyStrStr("World");
    if (contains) 
    {
        std::cout << "'World' found in str1" << std::endl;
    }
    else { std::cout << "'World' not found in str1" << std::endl; }

    
    //ПЕРЕГРУЗКА ОПЕРАТОРОВ
    MyString str4 = str1 + str3;
    str4.Print();
    
    str4 += str3;
    str4.Print();
    
    //_________________________________________

    /*
    str4.Add_Chars();
    str4.Print();

    MyString str5 = str4 + 'X'; // operator+(char c)
    str5.Print();

    str5 += 'Y'; // operator+=(char c)
    str5.Print();

    char& charAtIndex = str5(2); // operator()(int index)
    std::cout << "Character at index 6: " << charAtIndex << std::endl;

    // const operator()(int index)
    const MyString constStr = "Program"; // для проверки
    char constChar = constStr(2);
    std::cout << "Character at index 2 in constant string: " << constChar << std::endl;

    MyString str6 = str5 + 6; // operator+(int n)
    str6.Print();

    str6 += 2; // operator+=(int n)
    str6.Print();

    MyString str7 = str6++; //operator++(int)
    str7.Print();
    str6.Print();

    MyString str8 = ++str6; //operator++()
    str8.Print();
    str6.Print();

    MyString str9 = 'Q' + str6; //operator+(char, const MyString&)
    str9.Print();
    */

    //СТАТ
    std::cout << "Number of objects created: " << MyString::getObjectCount() << std::endl;

    return 0;
}