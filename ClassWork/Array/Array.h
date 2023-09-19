#pragma once

class Array
{
private:

    int* m_array;
    unsigned int m_size;

public:

    Array(const unsigned int size);

    ~Array();

    void operator() ();

    int& operator[](const unsigned int index);
};