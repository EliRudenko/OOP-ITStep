#pragma once

class Foo
{
private:

    int* m_pointer;
    int m_size;

public:

    Foo(const int size);
    Foo(const Foo& source);

    ~Foo();

    Foo& operator=(const Foo& right);

    void Initialize();
    void Show() const;
};