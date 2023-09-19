#include "Foo.h"
#include <iostream>

using namespace std;

Foo::Foo(const int size)
{
    cout << "Constructor" << endl;

    m_pointer = new int[size];
    m_size = size;
}

Foo::Foo(const Foo& source)
{
    m_pointer = new int[source.m_size];
    m_size = source.m_size;

    for (int i = 0; i < m_size; ++i)
    {
        m_pointer[i] = source.m_pointer[i];
    }
}

Foo::~Foo()
{
    cout << "Destructor" << endl;

    delete[] m_pointer;
}

Foo& Foo::operator=(const Foo& right)
{
    if (this != &right) //a=a
    {
        delete[] m_pointer; 

        m_pointer = new int[right.m_size];
        m_size = right.m_size;

        for (int i = 0; i < m_size; ++i)
        {
            m_pointer[i] = right.m_pointer[i];
        }
    }

    return *this;
}

void Foo::Initialize()
{
    for (int i = 0; i < m_size; ++i)
    {
        m_pointer[i] = rand() % 50;
    }
}

void Foo::Show() const
{
    for (int i = 0; i < m_size; ++i)
    {
        cout << m_pointer[i] << "  ";
    }

    cout << endl;
}