#pragma once

#include <iostream>

class Foo
{
private:

    char m_character;
    int m_data;

public:

    Foo();
    Foo(const int data, const char character);

    //friend std::ostream& operator<<(std::ostream& os, const Foo& obj);
    //friend std::istream& operator>>(std::istream& is, Foo& obj);
    

    char GetChar() const
    {
        return m_character;
    }
    int GetInt() const
    {
        return m_data;
    }

    void SetChar(char t) 
    {
        m_character = t;
    }
    void SetInt(int a) 
    {
        m_data = a;
    }


};
