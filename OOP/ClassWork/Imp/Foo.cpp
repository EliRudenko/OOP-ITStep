#include "Foo.h"

using namespace std;

Foo::Foo() :
    m_character(0),
    m_data(0)
{
}

Foo::Foo(const int data, const char character) :
    m_character(character),
    m_data(data)
{
}

ostream& operator<<(ostream& os, const Foo& obj)
{
    os << "ostream& operator<<(ostream& os, const Foo& obj)" << endl;

    os << obj.GetChar() << endl;
    os << obj.GetInt() << endl;

    return os;
}

istream& operator>>(istream& is, Foo& obj)
{
    cout << "istream& operator>>(istream& is, Foo& obj)" << endl;

    char a;
    int b;

    is >> b;
    obj.SetInt(b);

    is >> a;
    obj.SetChar(a);

    return is;
}