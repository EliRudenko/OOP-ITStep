#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

template <typename T> // ШАБЛОН String
class String 
{
private:
    T* data;

public:
    //КОНСТРУКТОРЫ
    String(const T* value = nullptr); // по умолчанию
    String(const String& add);// констр копи
    ~String();

    String& operator=(const String& add);//присваивание

    String operator+(const String& add) const;
    String operator*(const String& add) const;
    String operator/(const String& add) const;

    void Show() const;
    
    // преобразование
    operator const T*() const;
};
