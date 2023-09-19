#include "My_String.h"
#include <iostream>

int MyString::objectCount = 0;

//КОНСТРУКТОРЫ  ДЕСТРУКТОР

MyString::MyString() : str(new char[81]), length(80) 
{
    ++this->objectCount;
    this->str[0] = '\0';
}

MyString::MyString(int size) : str(new char[size + 1]), length(size) 
{
    ++this->objectCount;
    this->str[0] = '\0';
}

MyString::MyString(const char* input) : str(nullptr), length(0) 
{
    ++this->objectCount;
    int inputLength = 0;

    while (input[inputLength] != '\0') { ++inputLength; }

    this->str = new char[inputLength + 1];
    this->length = inputLength;

    for (int i = 0; i <= this->length; ++i) { this->str[i] = input[i]; }
}

MyString::MyString(const MyString& other) : str(nullptr), length(other.length) 
{
    ++this->objectCount;
    this->str = new char[this->length + 1];

    for (int i = 0; i <= this->length; ++i) { this->str[i] = other.str[i]; }
}

MyString::~MyString() 
{
    --this->objectCount;
    delete[] this->str;
}

//NEW
MyString& MyString::operator=(const MyString& right)
{//конструктор присваивания
    if (this != &right) //a=a
    {
        delete[] str;

        str = new char[right.length];
        length = right.length;

        for (int i = 0; i < length; ++i)
        {
            str[i] = right.str[i];
        }
    }
    return *this;
}


// ВВОД ВЫВОД
void MyString::Input() 
{
    std::cout << "Enter the string: ";
    std::cin.getline(this->str, this->length + 1);
    this->length = 0;

    while (this->str[this->length] != '\0') { ++this->length; }
}

void MyString::Print() const { std::cout << "String: " << this->str << std::endl; }



//МЕТОДЫ соответственно тз
void MyString::MyStrcpy(const MyString& obj) 
{//копирование строк
    this->length = obj.length;

    for (int i = 0; i <= this->length; ++i) { this->str[i] = obj.str[i]; }
}

bool MyString::MyStrStr(const char* s) const 
{//поиск подстроки в строке
    int sLength = 0;

    while (s[sLength] != '\0') { ++sLength; }

    for (int i = 0; i <= this->length - sLength; ++i) 
    {
        bool match = true;

        for (int j = 0; j < sLength; ++j) 
        {
            if (this->str[i + j] != s[j]) 
            {
                match = false;
                break;
            }
        }
        if (match) { return true; }
    }
    return false;
}

int MyString::MyChr(char c) const 
{//поиск символа в строке(индекс найденного символа, либо -1)
    for (int i = 0; i < this->length; ++i) 
    {
        if (this->str[i] == c) { return i; }
    }
    return -1;
}

int MyString::MyStrLen() const { return this->length; } //возвращает длину строки

void MyString::MyStrCat(const MyString& b) 
{// объединение строк
    char* newStr = new char[this->length + b.length + 1];

    for (int i = 0; i < this->length; ++i) { newStr[i] = this->str[i]; }

    for (int i = 0; i <= b.length; ++i) { newStr[this->length + i] = b.str[i]; }
    
    delete[] this->str;
    this->str = newStr;
    this->length += b.length;
}

void MyString::MyDelChr(char ch) 
{// удаляет указанный символ 
    int count = 0;

    for (int i = 0; i < this->length; ++i) 
    {
        if (this->str[i] != ch) 
        {
            this->str[count] = this->str[i];
            ++count;
        }
    }
    this->str[count] = '\0';
    this->length = count;
}

int MyString::MyStrCmp(const MyString& b) const 
{// сравнение строк 
    //-1 – первая строка меньше чем вторая
    //1 – первая больше чем вторая
    //0 – строки равны!

    for (int i = 0; i <= this->length && i <= b.length; ++i) 
    {
        if (this->str[i] < b.str[i]) 
        {
            return -1;
        }
        else if (this->str[i] > b.str[i]) { return 1; }
    }
    if (this->length < b.length) 
    {
        return -1;
    }
    else if (this->length > b.length) { return 1; }

    return 0;
}



//ПЕРЕГРУЗКИ ОПЕРАТОРОВ
MyString MyString::operator+(const MyString& other) const 
{
    MyString result(this->length + other.length);

    for (int i = 0; i < this->length; ++i) { result.str[i] = this->str[i]; }

    for (int i = 0; i <= other.length; ++i) { result.str[this->length + i] = other.str[i]; }

    return result;
}

MyString& MyString::operator+=(const MyString& addstr)
{
    char* newStr = new char[this->length + addstr.length + 1];

    for (int i = 0; i < this->length; ++i) { newStr[i] = this->str[i]; }

    for (int i = 0; i <= addstr.length; ++i) { newStr[this->length + i] = addstr.str[i]; }

    delete[] this->str;
    this->str = newStr;
    this->length += addstr.length;

    return *this;
}


//Новое дз
char& MyString::operator[](int index) { return this->str[index]; }

const char& MyString::operator[](int index) const { return this->str[index]; }


//СТАТ МЕТОД (кол во созданных обьектов)
int MyString::getObjectCount() { return objectCount; }





//Новое дз

void MyString::Add_Chars()
{
    //память под новую строку
    char* newStr = new char[this->length + 11];

    //копия строки
    for (int i = 0; i < this->length; ++i) { newStr[i] = this->str[i]; }

    //10 новых символов будут \0
    for (int i = this->length; i < this->length + 11; ++i) { newStr[i] = '\0'; }

    //чистка памяти, указательна новую строку
    delete[] this->str;
    this->str = newStr;
    this->length += 10;
}


MyString& MyString::operator+=(char c) 
{
    int old_Len = this->MyStrLen();// длина

    this->Add_Chars();// +10

    //конец строки
    this->str[old_Len] = c;
    this->str[old_Len + 1] = '\0';

    return *this;
}
MyString& MyString::operator+=(int n)
{
    int old_Len = this->MyStrLen();// длина

    for (int i = 0; i < n; ++i)
    {
        this->Add_Chars();// + 10

        this->str[old_Len + i] = 'A' + i;
        this->str[old_Len + i + 1] = '\0';
    }

    return *this;
}

MyString MyString::operator+(char c) const
{
    MyString result(*this);// копия строки
    int old_Len = result.MyStrLen(); // длина

    result.Add_Chars(); // +10

    //в конец строки
    result.str[old_Len] = c; 
    result.str[old_Len + 1] = '\0';

    return result;
}

MyString operator+(char c, const MyString& obj) 
{
    MyString result(1); //только 1 символ
    result[0] = c;
    result[1] = '\0';

    return result + obj;
}

MyString MyString::operator+(int n) const 
{
    MyString result(*this);// копия строки
    int old_Len = result.MyStrLen();// длина строки

    for (int i = 0; i < n; ++i) 
    {
        result.Add_Chars();// + 10

        result.str[old_Len + i] = 'A' + i;
        result.str[old_Len + i + 1] = '\0';
    }

    return result;
}

MyString MyString::operator++(int) 
{
    MyString result(*this);// копия строки

    this->Add_Chars();//+10 и в конец А
    this->str[this->length - 11] = 'A';

    return result;
}
MyString& MyString::operator++() 
{
    *this += 'A'; // в конец А
    return *this;
}


char& MyString::operator()(int index)
{
    if (index >= 0 && index < this->length)
    {
        return this->str[index];//ссылка на символ
    }
    else
    {
        std::cerr << "Error" << std::endl;
        return this->str[0];
    }
}
const char& MyString::operator()(int index) const
{
    if (index >= 0 && index < this->length)
    {
        return this->str[index];// конст ссылка на символ
    }
    else
    {
        std::cerr << "Error" << std::endl;
        return this->str[0];
    }
}



std::ostream& operator<<(std::ostream& os, const MyString& obj) 
{
    //os << "ostream& operator<<(ostream& os, const Foo& obj)" << std::endl;

    os << obj.GetStr();
    os << obj.GetLength() << std::endl;

    return os;
}

std::istream& operator>>(std::istream& is, MyString& obj) 
{
    //std::cout << "istream& operator>>(istream& is, Foo& obj)" << std::endl;

    char buffer[80+1];
    is.getline(buffer, 80+1);
    obj.SetStr(buffer);

    return is;
}