#include <iostream>
using namespace std;

class Box 
{
    int* weight; // Указатель на вес коробки
public:
    // Конструктор
    Box(int w) : weight(new int(w)) 
    {
        cout << "Box создана с весом " << *weight << endl;
    }

    // Конструктор копирования
    Box(const Box& other) : weight(new int(*other. )) 
    {
        cout << "Box скопирована с весом " << *weight << endl;
    }

    // Деструктор 
    ~Box() {
        cout << "Box с весом " << *weight << " удалена" << endl;
        delete weight;
    }

    int getWeight() const { return *weight; }
};

int main() {
    Box box1(10);        // Создаём первую коробку
    Box box2 = box1;     // Копируем коробку
    cout << "Вес box2: " << box2.getWeight() << endl;
    return 0;
}







/*
#include <iostream>
using namespace std;

class Box {
    int* weight;
public:
    // Конструктор
    Box(int w) : weight(new int(w)) {
        cout << "Box создана с весом " << *weight << endl;
    }

    // Конструктор переноса
    Box(Box&& other) noexcept : weight(other.weight) {
        other.weight = nullptr; // Забираем ресурс, "обнуляем" старую коробку
        cout << "Box перенесена!" << endl;
    }

    // Деструктор
    ~Box() {
        if (weight) {
            cout << "Box с весом " << *weight << " удалена" << endl;
            delete weight;
        } else {
            cout << "Box без веса удалена" << endl;
        }
    }

    int getWeight() const { return weight ? *weight : 0; }
};

int main() {
    Box box1(20);        // Создаём коробку
    Box box2 = std::move(box1); // Переносим ресурсы
    cout << "Вес box2: " << box2.getWeight() << endl;
    cout << "Вес box1: " << box1.getWeight() << endl;
    return 0;
}
*/







/*
#include <iostream>
using namespace std;

class Box {
    int* weight;
public:
    // Конструктор
    Box(int w) : weight(new int(w)) {
        cout << "Box создана с весом " << *weight << endl;
    }

    // Оператор присваивания с копированием
    Box& operator=(const Box& other) {
        if (this == &other) return *this; // Проверка на самоприсваивание
        delete weight;                   // Удаляем старые данные
        weight = new int(*other.weight); // Копируем данные
        cout << "Box присвоена с копированием, вес: " << *weight << endl;
        return *this;
    }

    // Деструктор
    ~Box() {
        cout << "Box с весом " << *weight << " удалена" << endl;
        delete weight;
    }
};

int main() {
    Box box1(30);
    Box box2(15);
    box2 = box1;         // Копируем вес box1 в box2
    return 0;
}
*/







/*
#include <iostream>
using namespace std;

class Box {
    int* weight;
public:
    // Конструктор
    Box(int w) : weight(new int(w)) {
        cout << "Box создана с весом " << *weight << endl;
    }

    // Оператор присваивания с переносом
    Box& operator=(Box&& other) noexcept {
        if (this == &other) return *this; // Проверка на самоприсваивание
        delete weight;                   // Удаляем старые данные
        weight = other.weight;           // Забираем указатель
        other.weight = nullptr;          // "Обнуляем" старую коробку
        cout << "Box присвоена с переносом!" << endl;
        return *this;
    }

    // Деструктор
    ~Box() {
        if (weight) {
            cout << "Box с весом " << *weight << " удалена" << endl;
            delete weight;
        } else {
            cout << "Box без веса удалена" << endl;
        }
    }
};

int main() {
    Box box1(40);
    Box box2(10);
    box2 = std::move(box1); // Переносим ресурсы из box1 в box2
    return 0;
}
*/







/*
try 
{
    // Код, который может вызвать исключение

    throw используется для сигнализирования о возникновении исключения или ошибки

} catch (ТипИсключения переменная) 
{
    // Код обработки исключения
}
*/




#include <iostream>
using namespace std;

int main() 
{
    try 
    {
        int a = 10, b = 0;
        if (b == 0) 
        {
            throw "Ошибка: деление на ноль!";
        }
        cout << a / b << endl;
    } catch (const char* msg) 
    {
        cout << "Исключение перехвачено: " << msg << endl;
    }

    cout << "Программа продолжает работу!" << endl;
    return 0;
}






#include <iostream>
using namespace std;

void checkNumber(int n) 
{
    if (n < 0) 
    {
        throw n; 
    }
    cout << "Число корректное: " << n << endl;
}

int main() 
{
    try 
    {
        checkNumber(10);
        checkNumber(-5); 
    } catch (int num) 
    {
        cout << "Ошибка! Получено отрицательное число: " << num << endl;
    }

    cout << "Программа завершена!" << endl;
    return 0;
}












#include <iostream>
using namespace std;

void process(int a) 
{
    if (a == 0) throw "Ошибка: передан 0!";
    if (a < 0) throw a;
}

int main() 
{
    try
    {
        process(5);
        process(0);

    } catch (const char* msg) {
        cout << "Строковое исключение: " << msg << endl;

    } catch (int num) {
        cout << "Числовое исключение: " << num << endl;
    }

    return 0;
}





/*
Стандартные исключения std::exception
Типы исключений:

std::invalid_argument – некорректные аргументы
std::runtime_error – ошибки выполнения
std::out_of_range – выход за границы


what() — это метод класса std::exception, который возвращает описание ошибки в виде строки 
*/





#include <iostream>
#include <stdexcept>
using namespace std;

class Person 
{
private:
    int age;
public:
    Person(int age) 
    {
        if (age < 0) 
        {
            throw invalid_argument("Возраст не может быть отрицательным!");
        }
        this->age = age;
    }

    void show() 
    {
        cout << "Возраст: " << age << endl;
    }
};

int main() 
{
    try 
    {
        Person p1(25);
        p1.show();
        
        Person p2(-5); // что будет ??

    } catch (const invalid_argument& e) {
        cout << "Исключение: " << e.what() << endl;
    }

    return 0;
}






#include <iostream>
#include <stdexcept>
using namespace std;

class BankAccount 
{
private:
    double balance;
public:
    BankAccount(double initialBalance) 
    {
        if (initialBalance < 0) 
        {
            throw invalid_argument("Начальный баланс не может быть отрицательным!");
        }
        balance = initialBalance;
    }

    void withdraw(double amount) 
    {
        if (amount > balance) 
        {
            throw runtime_error("Недостаточно средств на счете!");
        }
        balance -= amount;
        cout << "Снято: " << amount << ", Остаток: " << balance << endl;
    }
};

int main() 
{
    try 
    {
        BankAccount acc(1000);
        acc.withdraw(500);  // что будет ?
        acc.withdraw(600);  // что будет ?

    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}











template <typename T>
T add(T a, T b) 
{
    return a + b;
}








#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) 
{
    return a + b;
}

int main() 
{
    
    cout << add(3, 5) << endl;           // Сложение целых чисел
    cout << add(3.5, 2.1) << endl;       // Сложение с плавающими точками
    cout << add('A', 1) << endl;         // Сложение символов

    return 0;
}








#include <iostream>
using namespace std;

template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b) 
{
    return a + b;
}

int main() 
{
    cout << add(3, 5.5) << endl;   // Целое и вещественное число
    cout << add("Hello, ", "world!") << endl;   // Строки

    return 0;
}












template <typename T>
class Box 
{
private:
    T value;
public:
    Box(T val) : value(val) {}
    T getValue() 
    {
        return value;
    }
};













#include <iostream>
using namespace std;

template <typename T>
class Box 
{
private:
    T value;
public:
    Box(T val) : value(val) {}
    T getValue() {
        return value;
    }
};

int main() 
{
    Box<int> intBox(10);  // Шаблон с типом int
    Box<double> doubleBox(3.14);  // Шаблон с типом double

    cout << "intBox value: " << intBox.getValue() << endl;
    cout << "doubleBox value: " << doubleBox.getValue() << endl;

    return 0;
}













#include <iostream>
using namespace std;

template <typename T, typename U>
class Pair 
{
private:
    T first;
    U second;
public:
    Pair(T f, U s) : first(f), second(s) {}
    T getFirst() {
        return first;
    }
    U getSecond() {
        return second;
    }
};

int main() 
{
    Pair<int, double> pair(5, 3.14);
    cout << "First: " << pair.getFirst() << ", Second: " << pair.getSecond() << endl;

    return 0;
}








//Операторы (+, -, *, /, ==, =, [] ...)
//специальные символы, которые выполняют операции над значениями


//НО КЛАСС ЭТО НЕ ЗНАЧЕНИЯ, это наш тип, новый, который мы создали


// !!! Перегрузка операторов позволяет нам определить, 
// как операторы будут работать с объектами нашего класса. !!!

Vector2D a(1, 2);
Vector2D b(3, 4);
Vector2D c = a + b; // Как сложить два объекта?

//компилятор не знает как это сделать, надо написать обьяснения (перегрузки)




//Перегрузка +
class Vector2D 
{
public:
    int x, y;

    // Конструктор
    Vector2D(int x, int y) : x(x), y(y) {} 

    // Перегрузка оператора + МЕТОДОМ (внутри класса)
    Vector2D operator+(const Vector2D& other)
    {
        return Vector2D(x + other.x, y + other.y);
    }

    void print() 
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() 
{
    Vector2D a(1, 2);
    Vector2D b(3, 4);
    Vector2D c = a + b; // Теперь все ок = a.operator+(b)
    
    c.print(); // Выведет (4, 6)
    return 0;
}



//есть нюансы, как это сделать

//(глобальные) функции - снаружи класса   и    методы - внутри класса





//функция
class Vector2D 
{
public:
    int x, y;
    Vector2D(int x, int y) : x(x), y(y) {}

    void print() 
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};
    
// Глобальная функция перегрузки
Vector2D operator+(const Vector2D& a, const Vector2D& b) 
{
    return Vector2D(a.x + b.x, a.y + b.y);
}

int main() 
{
    Vector2D a(1, 2), b(3, 4);
    Vector2D c = a + b; // вызывается как обычная функция  c = operator+(a, b);
    c.print(); // (4, 6)
}
    



/*
Разница:

Метод внутри класса использует this (первый объект a).
Глобальная функция работает со всеми параметрами явно.

a + b → метод a.operator+(b)
a + b → функция operator+(a, b)

*/




class A 
{
public:
    int x;
    A(int val) : x(val) {}

    // Метод
    A operator+(const A& other) { 
        return A(x + other.x);
    }
};
//Здесь this->x + other.x, this — текущий объект.


A operator+(const A& a, const A& b) 
{
    return A(a.x + b.x);
}
//Здесь оба параметра передаются явно.












//Что можно перегрузить

+, -, *, /, %
==, !=, >, <, >=, <=	
+=, -=, *=, /=, %=, ^=
++, -- (префиксный и постфиксный)
[] (индексация)
() (вызов объекта как функции)
-> (разыменование указателя)


//НЕЛЬЗЯ
. (доступ к члену объекта)
:: (обращение к пространству имен)
sizeof (размер типа)
typeid (информация о типе)
.* (указатель на член класса)
new и delete (глобально) – можно перегрузить только для класса



//Перегрузка операторов позволяет работать с объектами, как с числами.
//Часто перегружаются +, -, ==, [], (), ++, --.




Только методом (внутри класса)	
=, (), [], ->
требуют доступ к this (объекту, для которого они вызываются).

Только функцией (вне класса)
<<, >> (потоковый ввод-вывод)
должны работать с std::cout и std::cin, поэтому перегружаются как глобальные функции.





//Унарные операторы (++, --, -, !)

class A 
{
public:
    int x;
    A(int val) : x(val) {}

    // Унарный минус
    A operator-() 
    { 
        return A(-x);
    }
};

/*
Теперь 
A a(5);
A b = -a; //делает b.x == -5.
*/

 

//Бинарные операторы (+, -, *, /, ==, !=)

A operator+(const A& a, const A& b) 
{
    return A(a.x + b.x);
}




//Перегрузка () (вызов объекта как функции)
class Multiplier 
{
public:
    int operator()(int a, int b) 
    {
        return a * b;
    }
};

int main() 
{
    Multiplier multiply;
    std::cout << multiply(3, 4); // 12
}
//Теперь multiply(3, 4) работает, как обычная функция.





//Перегрузка [] (индексация)
class Array 
{
private:
    int data[5];
public:
    Array() { for (int i = 0; i < 5; i++) data[i] = i * 10; }

    int operator[](int index) 
    { 
        return data[index]; 
    }
};

int main() 
{
    Array arr;
    std::cout << arr[2]; // 20
}
//Позволяет работать с объектом, как с массивом.





//Перегрузка ++ и -- (инкремент/декремент)

//Префиксный ++x
A& operator++() 
{ 
    x++; 
    return *this;
}


//Постфиксный x++
A operator++(int a)  // (фальшивый параметр)
{ 
    A temp = *this; 
    x++; 
    return temp;
}






//Перегрузка операторов << и >> (ввод-вывод)

std::ostream& operator<<(std::ostream& os, const A& obj) 
{
    return os << obj.x;
}

std::istream& operator>>(std::istream& is, A& obj) 
{
    return is >> obj.x;
}








class Vector3D 
{
private:
    double x, y, z;

public:
    // Конструктор по умолчанию
    Vector3D() : x(0), y(0), z(0) {}

    // Конструктор с параметрами
    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    // Перегрузка оператора + (метод)
    Vector3D operator+(const Vector3D& other) const 
    {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    // Перегрузка оператора - (метод)
    Vector3D operator-(const Vector3D& other) const 
    {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    // Префиксный ++ (увеличивает все координаты на 1)
    Vector3D& operator++() 
    {
        x++; y++; z++;
        return *this;
    }

    // Постфиксный ++ (увеличивает, но возвращает старое значение)
    Vector3D operator++(int) 
    {
        Vector3D temp = *this;
        ++(*this);
        return temp;
    }

    // Перегрузка оператора () - умножение всех координат на число
    void operator()(double multiplier) 
    {
        x *= multiplier;
        y *= multiplier;
        z *= multiplier;
    }

    // Перегрузка оператора [] - доступ к координатам по индексу
    double& operator[](int index) 
    {
        if (index == 0) return x;
        if (index == 1) return y;
        if (index == 2) return z;
        throw std::out_of_range("Индекс должен быть 0, 1 или 2");
    }

    void print() const 
    {
        std::cout << "(" << x << ", " << y << ", " << z << ")\n";
    }
};

int main() {
    Vector3D A(1.0, 2.0, 3.0);
    Vector3D B(4.0, 5.0, 6.0);

    std::cout << "Vector A: "; A.print();
    std::cout << "Vector B: "; B.print();

    Vector3D C = A + B;
    std::cout << "A + B: "; C.print();

    Vector3D D = A - B;
    std::cout << "A - B: "; D.print();

    std::cout << "Prefix ++A: "; 
    ++A;
    A.print();

    std::cout << "Postfix A++: "; 
    A++;
    A.print();

    std::cout << "Multiplying A by 2 using (): \n";
    A(2);
    A.print();

    std::cout << "Accessing A[1] (y-coordinate): " << A[1] << "\n";

    return 0;
}





/*

Реализуй класс Time для работы со временем. 
Время хранится в виде часов, минут и секунд (hours, minutes, seconds).

Реализуй перегрузки операторов:

Оператор + (сложение двух объектов Time)
Если сумма минут или секунд превышает 60, время должно корректироваться 
(перенос в минуты/часы).

Оператор - (вычитание двух объектов Time)
Результат не должен быть отрицательным.

Оператор ++ (префиксный и постфиксный)
Увеличивает время на одну секунду, учитывая корректировку (если seconds == 60, то увеличивает minutes).

Оператор () (устанавливает новое время)
obj(5, 30, 15); — задаёт 5 часов, 30 минут, 15 секунд.

Оператор [] (доступ к hours, minutes, seconds по индексу)
0 — hours, 1 — minutes, 2 — seconds.

Метод print(), который выводит время в формате HH:MM:SS

*/










class Time 
{
private:
    int hours, minutes, seconds;

    // Приватный метод для корректировки времени
    void normalize() 
    {
        if (seconds >= 60) 
        {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) 
        {
            hours += minutes / 60;
            minutes %= 60;
        }
    }

public:
    // Конструктор по умолчанию
    Time() : hours(0), minutes(0), seconds(0) {}

    // Конструктор с параметрами
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) 
    {
        normalize();  // Автоматическая нормализация
    }

    // Перегрузка оператора + (метод)
    Time operator+(const Time& other) const 
    {
        return Time(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
    }

    // Перегрузка оператора - (метод, с проверкой на отрицательное значение)
    Time operator-(const Time& other) const 
    {
        int totalSec1 = hours * 3600 + minutes * 60 + seconds;
        int totalSec2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
        int diff = totalSec1 - totalSec2;

        if (diff < 0) diff = 0;  // Запрещаем отрицательное время

        return Time(diff / 3600, (diff % 3600) / 60, diff % 60);
    }

    // Префиксный ++ (увеличивает время на 1 секунду)
    Time& operator++() 
    {
        ++seconds;
        normalize();
        return *this;
    }

    // Постфиксный ++ (увеличивает, но возвращает старое значение)
    Time operator++(int) 
    {
        Time temp = *this;
        ++(*this);
        return temp;
    }

    // Перегрузка оператора () для установки нового времени
    void operator()(int h, int m, int s) 
    {
        hours = h;
        minutes = m;
        seconds = s;
        normalize();
    }

    // Перегрузка оператора [] - доступ к частям времени по индексу
    int& operator[](int index) 
    {
        static int errorValue = -1;  // Значение, если индекс некорректный
        if (index == 0) return hours;
        if (index == 1) return minutes;
        if (index == 2) return seconds;
        std::cerr << "Ошибка: Индекс должен быть 0, 1 или 2\n";
        return errorValue;
    }

    // Метод для вывода времени
    void print() const 
    {
        std::cout << (hours < 10 ? "0" : "") << hours << ":"
                  << (minutes < 10 ? "0" : "") << minutes << ":"
                  << (seconds < 10 ? "0" : "") << seconds << "\n";
    }
};

int main() 
{
    Time T1(1, 45, 50);
    Time T2(2, 30, 20);

    std::cout << "T1: ";
    T1.print();

    std::cout << "T2: ";
    T2.print();

    Time T3 = T1 + T2;
    std::cout << "T1 + T2: ";
    T3.print();

    Time T4 = T1 - T2;
    std::cout << "T1 - T2: ";
    T4.print();

    std::cout << "Prefix ++T1: ";
    ++T1;
    T1.print();

    std::cout << "Postfix T1++: ";
    T1++;
    T1.print();

    std::cout << "Setting T1 to 12:00:00 using () operator:\n";
    T1(12, 0, 0);
    T1.print();

    std::cout << "Accessing minutes using T1[1]: " << T1[1] << "\n";
    std::cout << "Accessing invalid index T1[3]: " << T1[3] << "\n";  // Должна выдать ошибку

    return 0;
}















/*

классы могут взаимодействовать друг с другом разными способами


Вложенность (Nested classes)

Агрегация (Aggregation)

Композиция (Composition)

Дружба (Friendship)

Наследование (Inheritance)


*/










//Вложенность (Nested classes)
//Условие вложенности: внутренний класс может обращаться к членам 
//внешнего класса (если они public или protected), 

class Outer 
{
public:
    class Inner 
    { // Вложенный класс
    public:
        void display() 
        {
            std::cout << "This is an inner class." << std::endl;
        }
    };
};

int main()
{
    Outer::Inner obj;
    obj.display();
    return 0;
}
    




//Агрегация (Aggregation)

// Условие агрегации: объект передается в класс, 
//но создается и уничтожается отдельно.
class Student 
{
public:
    std::string name;
    Student(std::string name) : name(name) {}
};

class University 
{
public:
    Student* student; // Университет содержит студента
    University(Student* s) : student(s) {} // Студент передается снаружи (не создается внутри)
};

int main() 
{
    Student s("Alice");
    University uni(&s); // Университет получает ссылку на студента
    return 0;
}
    



//Композиция (Composition)
// Условие композиции: вложенный объект создается внутри класса
//и уничтожается вместе с ним.
class Engine 
{
public:
    Engine() { std::cout << "Engine created!" << std::endl; }
    ~Engine() { std::cout << "Engine destroyed!" << std::endl; }
};

class Car 
{
private:
    Engine engine; // Двигатель создается внутри машины
public:
    Car() { std::cout << "Car created!" << std::endl; }
    ~Car() { std::cout << "Car destroyed!" << std::endl; }
};

int main() 
{
    Car myCar;
    return 0;
}
    



//Дружба (Friendship)
//Условие дружбы: доступ к закрытым данным возможен, 
//но дружба не наследуется и не транзитивна
class B;
class A 
{
private:
    int secret = 42;
public:
    friend class B; // Класс B - друг класса A
};

class B 
{
public:
    void revealSecret(A& a) 
    {
        std::cout << "Secret is: " << a.secret << std::endl;
    }
};

int main() 
{
    A a;
    B b;
    b.revealSecret(a);
    return 0;
}




//Наследование (Inheritance)
//Условие наследования: подкласс получает доступ к методам 
//и данным базового класса (если они public или protected).
class Animal 
{
public:
    void eat() { std::cout << "Eating..." << std::endl; }
};

class Dog : public Animal { // Dog наследует Animal
public:
    void bark() { std::cout << "Barking..." << std::endl; }
};

int main() 
{
    Dog d;
    d.eat();  // Наследованный метод
    d.bark(); // Собственный метод
    return 0;
}
    


//Одиночное наследование (Single Inheritance)


// Базовый класс (родитель)
class Animal 
{
public:
    void eat() { cout << "Eating..." << endl; }
};

// Дочерний класс (наследует Animal)
class Dog : public Animal 
{
public:
    void bark() { cout << "Barking..." << endl; }
};

int main() 
{
    Dog d;
    d.eat();  // Метод из базового класса
    d.bark(); // Метод из дочернего класса
    return 0;
}
//Итог: Dog получает все public и protected методы Animal.




//Множественное наследование (Multiple Inheritance)


class A 
{
public:
    void show() { cout << "Class A" << endl; }
};

class B 
{
public:
    void show() { cout << "Class B" << endl; }
};

// Ошибка! Какой show() использовать?
class C : public A, public B {};

int main() 
{
    C obj;
    obj.show(); // Ошибка: неоднозначность



    obj.A::show(); // Вызывает show() из A
    obj.B::show(); // Вызывает show() из B
}


//Проблема "алмазного" наследования (Diamond Problem)

class A 
{
public:
    void show() { cout << "Class A" << endl; }
};

class B : public A {}; // B наследует A
class C : public A {}; // C наследует A
class D : public B, public C {}; // D наследует и B, и C

int main() 
{
    D obj;
    obj.show(); // Ошибка: два A в D!
}
//Алмазное наследование возникает, когда два класса наследуют 
//один и тот же базовый класс, а затем ещё один класс наследует их обоих.


    



















//Связанность (Binding)





/*

Связанность – это механизм связывания вызова метода с его кодом.

Ранняя (статическая) – на этапе компиляции.

Поздняя (динамическая) – на этапе выполнения (через vtable).

Статический полиморфизм – выполняется во время компиляции (перегрузка, шаблоны).

Динамический полиморфизм – выполняется во время выполнения (virtual + vtable).

VTable (виртуальная таблица) – помогает динамически находить правильные методы.


*/


//Статический полиморфизм



#include <iostream>

class Math {
public:
    // Перегруженные методы add()
    int add(int a, int b) { 
        return a + b; 
    }

    double add(double a, double b) { 
        return a + b; 
    }
};

int main() {
    Math math;
    
    std::cout << "Sum of integers: " << math.add(5, 3) << std::endl;      // Вызывает add(int, int)
    std::cout << "Sum of doubles: " << math.add(2.5, 3.7) << std::endl;  // Вызывает add(double, double)
    
    return 0;
}













//Перегрузка функций (Function Overloading)
class Math 
{
public:
    void add(int a, int b) { cout << "Sum (int): " << a + b << endl; }
    void add(double a, double b) { cout << "Sum (double): " << a + b << endl; }
};

int main() 
{
    Math m;
    m.add(3, 4);       // Вызовет add(int, int)
    m.add(3.5, 4.2);   // Вызовет add(double, double)
    return 0;
}



//Шаблоны (Templates)
template <typename T>
class Calculator
{
public:
    T add(T a, T b) 
    {
        return a + b;
    }
};

int main() 
{
    Calculator<int> intCalc;
    Calculator<double> doubleCalc;
    
    cout << intCalc.add(2, 3) << endl;     // 5
    cout << doubleCalc.add(2.5, 3.5) << endl; // 6.0
    return 0;
}






//Динамический полиморфизм

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() { cout << "Some sound..." << endl; }
};

class Dog : public Animal {
public:
    void sound() override { cout << "Bark!" << endl; }
};

class Cat : public Animal {
public:
    void sound() override { cout << "Meow!" << endl; }
};

int main() 
{
    Animal* a;  
    Dog d;
    Cat c;

    a = &d;
    a->sound();  // Bark!

    a = &c;
    a->sound();  // Meow!

    return 0;
}






//Виртуальные методы и виртуальная таблица VTable
class Base 
{
public:
    virtual void show() { cout << "Base class" << endl; }
};

class Derived : public Base {
public:
    void show() override { cout << "Derived class" << endl; }
};

int main() {
    Base* b;
    Derived d;
    b = &d;
    
    b->show();  // Derived class (поиск через vtable)
    return 0;
}




