#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

#include "string.h"

template <typename T>// конструктор по умолчанию
String<T>::String(const T* value) 
{
    if (value)
    {
        int len = 0;
        while (value[len] != '\0') { len++; } // длина строки

        data = new T[len + 1];// выделяется память 
        for (int i = 0; i <= len; i++) { data[i] = value[i]; }// копи
    } 
    else { data = nullptr; }
}

template <typename T> // копи
String<T>::String(const String& add) 
{
    if (add.data) 
    {
        int len = 0;
        while (add.data[len] != '\0') { len++; }

        data = new T[len + 1];
        for (int i = 0; i <= len; i++) { data[i] = add.data[i]; }
    } 
    else { data = nullptr; }
}

template <typename T>
String<T>::~String() { delete[] data; }



template <typename T> // ПРИСВАИВАНИЕ
String<T>& String<T>::operator=(const String& add) 
{
    if (this == &add) {return *this; } //самоприсваивание

    delete[] data; // обнуление текущих данных

    if (add.data) 
    {
        int len = 0;
        while (add.data[len] != '\0') { len++; } // днила

        data = new T[len + 1]; // панять
        for (int i = 0; i <= len; i++) { data[i] = add.data[i];} // копи
    } 
    else { data = nullptr; }

    return *this; //на текуший обьект
}

template <typename T>
String<T> String<T>::operator+(const String& add) const 
{
    if (!data && !add.data)  //не пустая ли строка
    {
        return String();
    } 
    else if (!data) 
    {
        return add;
    } 
    else if (!add.data) 
    {
        return *this;
    }

    int len1 = 0;
    while (data[len1] != '\0') { len1++; }// длина 1

    int len2 = 0;
    while (add.data[len2] != '\0') { len2++; } // длина 2

    T* resultData = new T[len1 + len2 + 1]; // память

    for (int i = 0; i < len1; i++) { resultData[i] = data[i]; } // копи 1 строки

    for (int i = 0; i <= len2; i++) { resultData[len1 + i] = add.data[i]; } // копи 2 строки

    return String(resultData); // НОВАЯ СТРОКА
}

template <typename T>
String<T> String<T>::operator*(const String& add) const 
{
    if (!data || !add.data) { return String(); }

    int len1 = 0;
    while (data[len1] != '\0') {
        len1++;
    }

    int len2 = 0;
    while (add.data[len2] != '\0') { len2++; }

    T* resultData = new T[len1 + len2 + 1];

    int resultIndex = 0;
    for (int i = 0; i < len1; i++) 
    {
        for (int j = 0; j < len2; j++) 
        {
            if (data[i] == add.data[j]) 
            {
                resultData[resultIndex++] = data[i]; //совподающие символы
                break;
            }
        }
    }

    resultData[resultIndex] = '\0';

    return String(resultData); // НОВАЯ СТРОКА
}

template <typename T>
String<T> String<T>::operator/(const String& add) const 
{
    if (!data || !add.data) { return *this; }

    int len1 = 0;
    while (data[len1] != '\0') { len1++; }

    int len2 = 0;
    while (add.data[len2] != '\0') { len2++; }

    T* resultData = new T[len1 + 1];

    int resultIndex = 0;
    for (int i = 0; i < len1; i++) 
    {
        bool found = false;
        for (int j = 0; j < len2; j++) 
        {
            if (data[i] == add.data[j]) 
            {
                found = true; //найден во второй строке
                break;
            }
        }
        if (!found) { resultData[resultIndex++] = data[i]; } // не найден
    }

    resultData[resultIndex] = '\0';

    return String(resultData); // НОВАЯ СТРОКА
}

template <typename T> // вывод
void String<T>::Show() const 
{
    if (data) { std::cout << data; }
}

template <typename T> // ПРЕОБРПЗОВАНИЕ к типу Т
String<T>::operator const T*() const { return data; }
