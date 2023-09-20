#include "MSem.h"
#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

MyArray::MyArray()
{
    this->_ptr = nullptr;
    this->_size = 0;
}

MyArray::MyArray(const unsigned int inputSize)
{
    this->_size = inputSize;
    this->_ptr = new int[this->_size] {0};
}

MyArray::MyArray(const MyArray &inputArr)
{
    this->_size = inputArr._size;
    this->_ptr = new int[this->_size];

    for (int i = 0; i < this->_size; ++i) {

        this->_ptr[i] = inputArr._ptr[i];
    }
}

MyArray &MyArray::operator=(const MyArray &inputArr)
{
    if (this == &inputArr)  {

        return *this;
    }

    delete[] this->_ptr;

    this->_size = inputArr._size;
    this->_ptr = new int[this->_size];

    for (int i = 0; i < this->_size; ++i) {

        this->_ptr[i] = inputArr._ptr[i];
    }

    return *this;
}

MyArray::~MyArray()
{
    delete[] this->_ptr;
}







MyArray::MyArray(MyArray&& obj)
{
    _size = obj._size;
    obj._size = 0;
    _ptr = obj._ptr;
    obj._ptr = nullptr;
    std::cout << "Move c";
}

MyArray &MyArray::operator=(MyArray&& obj )
{
    if(this == &obj)
    {
        return *this;
    }
    delete[]_ptr;
    
        _size = obj._size;
    obj._size = 0;
    _ptr = obj._ptr;
    obj._ptr = nullptr;
    std::cout << "Move: ";
    return *this;
}