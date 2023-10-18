#include "Fooo.h"
#include <iostream>

int Foo::count = 0;

Foo::Foo() {

    this->x = 0;
    this->y = 0;
    this->s = nullptr;
    this->t = nullptr;

}

Foo::Foo(int inX):Foo() {

    this->x = inX;
    ++count;
}

Foo::Foo(int inX, int inY):Foo(inX)
{
    this->y = inY;
}

Foo::Foo(int inX, int inY, int inS_Size):Foo(inX, inY)
{
    this->s_size = inS_Size;
    this->s = new int[inS_Size] {0};
}

Foo::Foo(int inX, int inY, int inS_Size, int inT_Size):Foo(inX, inY, inS_Size)
{
    this->t_size = inT_Size;
    this->t = new char[inT_Size]{'A'};
}

void Foo::printObj() const
{
    std::cout << "X: " << this->x << std::endl;
    std::cout << "Y: " << this->y << std::endl;

    for (int i = 0; i < this->s_size; ++i) {

        std::cout << this->s[i] << " ";
    }
    std::cout << std::endl;
    std::cout << t << std::endl;
}

void Foo::printCount()
{
    std::cout << count << std::endl;
}

Foo::~Foo() {

    delete[] s;
    delete[] t;
}

Foo::Foo(const Foo& inObj) {

    this->x = inObj.x;  

    this->y = inObj.y;

    this->s_size = inObj.s_size;

    for (int i = 0; i < this->s_size; ++i) {

        this->s[i] = inObj.s[i];
    }

    this->t_size = inObj.t_size;

    for (int i = 0; i < this->t_size; ++i) {

        this->t[i] = inObj.t[i];
    }
}
