#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

#include "var.h"

template <typename T> // конструктор итпа Т
var<T>::var(T value) : value(value) {}

template <typename T> // конструктор типа String
var<T>::var(const String<T>& value) : value(value) {}


template <typename T> // конструктор копи
var<T>::var(const var& add) : value(add.value) {}



template <typename T> // ПРИСВАИВАНИЕ
var<T>& var<T>::operator=(const var& add) 
{
    if (this == &add) { return *this; } //самоприсваивание
    value = add.value; // присваивается значение из другого обьекта

    return *this;
}

template <typename T> //=
var<T> var<T>::operator+(const var& add) const 
{
    var<T> result = value + add.value; // новый объект, записываем результат сложения
    return result;
}

template <typename T> //-
var<T> var<T>::operator-(const var& add) const 
{
    var<T> result = value - add.value;
    return result;
}

template <typename T> // *
var<T> var<T>::operator*(const var& add) const 
{
    var<T> result = value * add.value;
    return result;
}

template <typename T> // /
var<T> var<T>::operator/(const var& add) const 
{
    var<T> result = value / add.value;
    return result;
}

template <typename T> 
var<T>& var<T>::operator+=(const var& add) 
{
    value += add.value;
    return *this;
}

template <typename T>
var<T>& var<T>::operator-=(const var& add)
{
    value -= add.value;
    return *this;
}

template <typename T>
var<T>& var<T>::operator*=(const var& add) 
{
    value *= add.value;
    return *this;
}

template <typename T>
var<T>& var<T>::operator/=(const var& add) 
{
    value /= add.value;
    return *this;
}

//СРАВНЕНИЯ
template <typename T> // опер. меньше
bool var<T>::operator<(const var& add) const { return value < add.value; }

template <typename T> // опер. больше
bool var<T>::operator>(const var& add) const { return value > add.value; }

template <typename T>
bool var<T>::operator<=(const var& add) const { return value <= add.value; }

template <typename T>
bool var<T>::operator>=(const var& add) const { return value >= add.value; }

template <typename T>
bool var<T>::operator==(const var& add) const { return value == add.value; }

template <typename T>
bool var<T>::operator!=(const var& add) const { return value != add.value; }


//ПРЕОБРАЗОВАНИЕ

template <typename T>//К int
var<T>::operator int() const { return static_cast<int>(value); }

template <typename T> // К double
var<T>::operator double() const { return static_cast<double>(value); }

template <typename T> // К String
var<T>::operator const String<T>&() const {return value; }

template <typename T> // вывод
void var<T>::Show() const { std::cout << value; }
