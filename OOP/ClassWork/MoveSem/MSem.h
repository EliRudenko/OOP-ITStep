#pragma once

class MyArray {

private:

    int* _ptr;
    unsigned int _size;

public:

    MyArray();
    ~MyArray();

    MyArray(const unsigned int inputSize);

    MyArray(const MyArray& inputArr);

    MyArray& operator=(const MyArray& inputArr);





    MyArray(MyArray&& obj);

    MyArray& operator=(MyArray&& obj);
};
