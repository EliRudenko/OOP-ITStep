#pragma once

class MyString 
{
private:
    char* str; // ��������� �� ������
    int length; // ����� 

public:
    static int objectCount; //���� ���� ��� �� ��������� ��������

    // ������������ � ����������
    MyString(); // �� ���������
    MyString(int size); // � ��������
    MyString(const char* input); // � �������������� �� �����
    MyString(const MyString& other); // ����
    MyString& operator=(const MyString& right); //������������
    ~MyString(); // ����������

    // ������ ��� ����� � ������
    void Input();
    void Print() const;


    char* GetStr() const { return str; }
    int GetLength() const { return length; }

    void SetStr(const char* s) 
    {
        delete[] str;
        int inputLength = 0;

        while (s[inputLength] != '\0') { ++inputLength; }

        str = new char[inputLength + 1];
        length = inputLength;

        for (int i = 0; i <= length; ++i) { str[i] = s[i]; }
    }
    void SetLength(int size) 
    {
        delete[] str;
        str = new char[size + 1];
        length = size;
        str[0] = '\0';
    }


    // ������ ������ �� ��������
    void MyStrcpy(const MyString& obj);
    bool MyStrStr(const char* str) const;
    int MyChr(char c) const;
    int MyStrLen() const;
    void MyStrCat(const MyString& b);
    void MyDelChr(char c);
    int MyStrCmp(const MyString& b) const;

    // ���������� ����������
    MyString operator+(const MyString& other) const; // �������� ��������
    MyString& operator+=(const MyString& other); // �������� +=
    
    //����� ��
    char& operator[](int index); // �������� []
    const char& operator[](int index) const; // �������� [] const

    // ���� ����� ��� �� ��������
    static int getObjectCount();


    // ����� ��
    void Add_Chars(); //+10 � �����
    MyString operator+(char c) const; // ������������ ��� ��������, ���������� ���� +
    MyString operator+(int n) const; // ������������ ���� int, ���������� ���� +
    MyString& operator+=(char c); // ���������� ������� � ����� ������, ���������� +=
    MyString& operator+=(int n); // ���������� int � ����� ������, ���������� +=
    MyString operator++(int); //���������� � � ����, ���������� ++
    MyString& operator++(); 

    char& operator()(int index); // ������ � ������� �� �������
    const char& operator()(int index) const; // ����� � ���� �����

    MyString(MyString&& obj);
    MyString& operator=(MyString&& obj);
    
};

MyString operator+(char c, const MyString& obj); // ������������ ������� ������, ���������� +
