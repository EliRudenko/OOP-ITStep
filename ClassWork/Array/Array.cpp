#include "Array.h"
#include <iostream>

Array::Array(const unsigned int size)
{
	m_array = new int[size];
	m_size = size;

	for (unsigned int i = 0; i < m_size; ++i)
	{
		m_array[i] = rand() % 100 + 1;;
	}
}

Array::~Array()
{
	delete[] m_array;
}

int& Array::operator[](const unsigned int index)
{
	if (index >= m_size)
	{
		return m_array[index];
	}
	return m_array[0];
}

void Array::operator() ()
{
	for (unsigned int i = 0; i < m_size; ++i)
	{
		std::cout << m_array[i] << std::endl;
	}
}