#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

#include "string.h"

template <typename T>// ШАБЛОН var
class var 
{
private:
    T value;

public:
    // КОНСТРУКТОРЫ
    var(T value);
    var(const String<T>& value);
    var(const var& add);

    var& operator=(const var& add); // присваивание

    //операторы
    var operator+(const var& add) const;
    var operator-(const var& add) const;
    var operator*(const var& add) const;
    var operator/(const var& add) const;

    var& operator+=(const var& add);
    var& operator-=(const var& add);
    var& operator*=(const var& add);
    var& operator/=(const var& add);

    //сравнения
    bool operator<(const var& add) const;
    bool operator>(const var& add) const;
    bool operator<=(const var& add) const;
    bool operator>=(const var& add) const;
    bool operator==(const var& add) const;
    bool operator!=(const var& add) const;

    //ПРЕОБРАЗОВАНИЯ!!!
    operator int() const;
    operator double() const;
    operator const String<T>&() const;

    void Show() const; //вывод
};