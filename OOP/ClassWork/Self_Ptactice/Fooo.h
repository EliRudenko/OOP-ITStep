#pragma once

class Foo {

private:

    int x;
    int y;
    int* s;
    int s_size;
    char* t;
    int t_size;
    static int count;

public:

    Foo();
    Foo(int inX);
    Foo(int inX, int inY);
    Foo(int inX, int inY, int inS_Size);
    Foo(int inX, int inY, int inS_Size, int inT_Size);

    Foo(const Foo& inObj);

    void printObj() const;     

    static void printCount();

    ~Foo();

};