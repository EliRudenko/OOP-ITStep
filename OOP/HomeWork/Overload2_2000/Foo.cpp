#include "Foo.h"
#include <iostream>

Foo::Foo(const int data) : m_data(data) {}

void Foo::Show() { std::cout << m_data << std::endl; }

int Foo::GetData() const { return 0; }

void Foo::SetData(int d) { m_data = d; }
