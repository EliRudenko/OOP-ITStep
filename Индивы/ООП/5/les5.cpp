
/*
class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

Point p1(2, 3), p2(4, 5);
// Что произойдет при попытке сложить два объекта?
Point p3 = p1 + p2; // Ошибка: компилятор не знает, как складывать Point.



int a = 5, b = 10;
int c = a + b; // Сложение целых чисел.




Point p1(2, 3), p2(4, 5);
Point p3 = p1 + p2; // Ошибка!
*/








#include <iostream>
using namespace std;

class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Перегрузка оператора + как метода-члена
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
};

int main() {
    Point p1(2, 3), p2(4, 5);
    Point p3 = p1 + p2; // Теперь работает!
    cout << "p3: (" << p3.x << ", " << p3.y << ")" << endl;
    return 0;
}






class Counter {
public:
    int value;
    Counter(int val = 0) : value(val) {}

    // Префиксный инкремент
    Counter& operator++() {
        ++value;
        return *this;
    }

    // Постфиксный инкремент
    Counter operator++(int) {
        Counter temp = *this;
        ++value;
        return temp;
    }
};

int main() {
    Counter c(5);
    cout << (++c).value << endl; // Префикс: увеличиваем, потом возвращаем (6)
    cout << (c++).value << endl; // Постфикс: возвращаем, потом увеличиваем (6)
    cout << c.value << endl;     // Теперь значение 7
    return 0;
}








class String {
private:
    char* data;
    size_t size;

public:
    String(const char* str = "") {
        size = strlen(str);
        data = new char[size + 1];
        strcpy(data, str);
    }

    // Перегрузка оператора присваивания
    String& operator=(const String& other) {
        if (this == &other) return *this; // Защита от самоприсваивания

        delete[] data; // Освобождаем старую память
        size = other.size;
        data = new char[size + 1];
        strcpy(data, other.data);
        return *this;
    }

    void print() const {
        cout << data << endl;
    }

    ~String() {
        delete[] data;
    }
};

int main() {
    String s1("Hello"), s2;
    s2 = s1; // Используем перегруженный оператор
    s2.print(); // Вывод: Hello
    return 0;
}















//1
#include <iostream>
using namespace std;

// Класс для работы с простыми числами
class Number 
{
private:
    int value;

public:
    // Конструктор
    Number(int v = 0) : value(v) {}

    // Перегрузка оператора сложения
    Number operator+(const Number& other) const 
    {
        return Number(value + other.value);
    }

    // Перегрузка оператора вычитания
    Number operator-(const Number& other) const 
    {
        return Number(value - other.value);
    }

    // Перегрузка оператора умножения
    Number operator*(const Number& other) const 
    {
        return Number(value * other.value);
    }

    // Перегрузка оператора сравнения ==
    bool operator==(const Number& other) const 
    {
        return value == other.value;
    }

    // Перегрузка оператора инкремента (префиксная форма)
    Number& operator++() 
    {
        ++value;
        return *this;
    }

    // Перегрузка оператора инкремента (постфиксная форма)
    Number operator++(int) 
    {
        Number temp = *this;
        value++;
        return temp;
    }

    // Перегрузка оператора вывода в поток
    friend ostream& operator<<(ostream& out, const Number& num) 
    {
        out << num.value;
        return out;
    }

    // Перегрузка оператора ввода из потока
    friend istream& operator>>(istream& in, Number& num) 
    {
        in >> num.value;
        return in;
    }
};



int main() 
{
    Number a(5), b(10), c;

    // Ввод значения
    cout << "Введите число: ";
    cin >> c;

    // Примеры операций
    Number sum = a + b;       // Сложение
    Number diff = a - b;      // Вычитание
    Number prod = a * b;      // Умножение
    bool isEqual = a == b;    // Сравнение

    // Вывод результатов
    cout << "Сумма: " << sum << endl;
    cout << "Разность: " << diff << endl;
    cout << "Произведение: " << prod << endl;
    cout << "Числа равны? " << (isEqual ? "Да" : "Нет") << endl;

    // Инкремент
    cout << "До инкремента: " << a << endl;
    cout << "Префиксный инкремент: " << ++a << endl;
    cout << "Постфиксный инкремент: " << a++ << endl;
    cout << "После постфиксного инкремента: " << a << endl;

    return 0;
}










//ЗАДАНИЕ
#include <iostream>
using namespace std;

// Класс двумерного вектора
class Vector2D 
{
private:
    double x, y;

public:
    // Конструктор
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    // Перегрузка оператора сложения
    Vector2D operator+(const Vector2D& other) const 
    {
        return Vector2D(x + other.x, y + other.y);
    }

    // Перегрузка оператора вычитания
    Vector2D operator-(const Vector2D& other) const 
    {
        return Vector2D(x - other.x, y - other.y);
    }

    // Перегрузка оператора умножения на скаляр
    Vector2D operator*(double scalar) const 
    {
        return Vector2D(x * scalar, y * scalar);
    }

    // Перегрузка оператора сравнения
    bool operator==(const Vector2D& other) const 
    {
        return x == other.x && y == other.y;
    }

    // Перегрузка оператора вывода в поток
    friend ostream& operator<<(ostream& out, const Vector2D& vec) 
    {
        out << "(" << vec.x << ", " << vec.y << ")";
        return out;
    }

    // Перегрузка оператора ввода из потока
    friend istream& operator>>(istream& in, Vector2D& vec) 
    {
        cout << "Введите x: ";
        in >> vec.x;
        cout << "Введите y: ";
        in >> vec.y;
        return in;
    }
};

int main() 
{
    // Создаем векторы
    Vector2D v1, v2;
    cout << "Введите координаты первого вектора:" << endl;
    cin >> v1;
    cout << "Введите координаты второго вектора:" << endl;
    cin >> v2;

    // Сложение
    Vector2D sum = v1 + v2;
    cout << "Сумма векторов: " << sum << endl;

    // Вычитание
    Vector2D diff = v1 - v2;
    cout << "Разность векторов: " << diff << endl;

    // Умножение на скаляр
    double scalar;
    cout << "Введите скаляр для умножения: ";
    cin >> scalar;
    Vector2D scaled = v1 * scalar;
    cout << "Вектор после умножения на скаляр: " << scaled << endl;

    // Сравнение
    cout << "Векторы равны? " << (v1 == v2 ? "Да" : "Нет") << endl;

    return 0;
}









//2
#include <iostream>
using namespace std;

// Шаблон класса
template <typename T>
class Box {
private:
    T value;

public:
    // Конструктор
    Box(T v) : value(v) {}

    // Метод для получения значения
    T getValue() const {
        return value;
    }

    // Метод для установки значения
    void setValue(T v) {
        value = v;
    }

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& out, const Box<T>& box) {
        out << "Box содержит: " << box.value;
        return out;
    }
};

// Шаблон функции
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    // Работа с шаблоном класса
    Box<int> intBox(10);          // Box с типом int
    Box<double> doubleBox(3.14);  // Box с типом double
    Box<string> stringBox("Привет, шаблоны!"); // Box с типом string

    cout << intBox << endl;
    cout << doubleBox << endl;
    cout << stringBox << endl;

    // Изменяем значение в Box
    intBox.setValue(20);
    cout << "Новое значение: " << intBox.getValue() << endl;

    // Работа с шаблонной функцией
    cout << "Сумма int: " << add(5, 10) << endl;
    cout << "Сумма double: " << add(2.5, 3.5) << endl;

    return 0;
}






//Задание
#include <iostream>
using namespace std;

// Шаблонный класс Pair
template <typename T>
class Pair {
private:
    T first, second;

public:
    // Конструктор
    Pair(T f, T s) : first(f), second(s) {}

    // Методы для установки значений
    void setFirst(T f) { first = f; }
    void setSecond(T s) { second = s; }

    // Методы для получения значений
    T getFirst() const { return first; }
    T getSecond() const { return second; }

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& out, const Pair<T>& pair) {
        out << "(" << pair.first << ", " << pair.second << ")";
        return out;
    }
};

// Шаблонная функция для обмена значений
template <typename T>
void swapValues(Pair<T>& pair) {
    T temp = pair.getFirst();
    pair.setFirst(pair.getSecond());
    pair.setSecond(temp);
}

int main() {
    // Pair с типом int
    Pair<int> intPair(1, 2);
    cout << "Исходная пара (int): " << intPair << endl;
    swapValues(intPair);
    cout << "После обмена: " << intPair << endl;

    // Pair с типом double
    Pair<double> doublePair(3.14, 2.71);
    cout << "Исходная пара (double): " << doublePair << endl;
    swapValues(doublePair);
    cout << "После обмена: " << doublePair << endl;

    // Pair с типом string
    Pair<string> stringPair("Hello", "World");
    cout << "Исходная пара (string): " << stringPair << endl;
    swapValues(stringPair);
    cout << "После обмена: " << stringPair << endl;

    return 0;
}










//3
/*
#include <iostream>
#include <string>
using namespace std;


// Абстрактный класс с чисто виртуальными методами
class Animal 
{
public:
    virtual void speak() const = 0; // Чисто виртуальный метод
    virtual ~Animal() 
    { // Виртуальный деструктор
        cout << "Animal удалён" << endl;
    }
};

// Производный класс Dog
class Dog : public Animal 
{
public:
    void speak() const override 
    { // Переопределение метода
        cout << "Собака говорит: Гав-гав!" << endl;
    }

    ~Dog() override 
    {
        cout << "Dog удалён" << endl;
    }
};

// Производный класс Cat
class Cat : public Animal 
{
public:
    void speak() const override 
    { // Переопределение метода
        cout << "Кошка говорит: Мяу!" << endl;
    }

    ~Cat() override 
    {
        cout << "Cat удалён" << endl;
    }
};

// Производный класс Bird (ещё один пример полиморфизма)
class Bird : public Animal 
{
public:
    void speak() const override 
    {
        cout << "Птица говорит: Чирик-чирик!" << endl;
    }

    ~Bird() override 
    {
        cout << "Bird удалён" << endl;
    }
};



int main() 
{
    // Демонстрация статического связывания
    Dog staticDog;
    staticDog.speak();

    // Демонстрация динамического связывания
    Animal* animals[] = { new Dog(), new Cat(), new Bird() };

    for (Animal* animal : animals) 
    {
        animal->speak(); // Динамическое связывание
    }

    // Освобождение памяти
    for (Animal* animal : animals) 
    {
        delete animal; // Вызов виртуального деструктора
    }

    return 0;
}
*/








//задание
#include <iostream>
#include <cmath>
using namespace std;






/*
// Абстрактный класс Shape
class Shape 
{
public:
    virtual double getArea() const = 0;       // Чисто виртуальный метод
    virtual double getPerimeter() const = 0; // Чисто виртуальный метод
    virtual ~Shape() 
    { // Виртуальный деструктор
        cout << "Shape удалён" << endl;
    }
};

// Производный класс Circle
class Circle : public Shape 
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getArea() const override 
    {
        return 3.14 * radius * radius;
    }
    double getPerimeter() const override 
    {
        return 2 * 3.14 * radius;
    }
    ~Circle() override 
    {
        cout << "Circle удалён" << endl;
    }
};

// Производный класс Rectangle
class Rectangle : public Shape 
{
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
    double getPerimeter() const override {
        return 2 * (width + height);
    }
    ~Rectangle() override {
        cout << "Rectangle удалён" << endl;
    }
};

int main() {
    // Массив указателей на Shape
    Shape* shapes[] = {
        new Circle(5.0),  // Круг с радиусом 5
        new Rectangle(4.0, 6.0) // Прямоугольник 4x6
    };

    // Вывод площади и периметра для каждой фигуры
    for (Shape* shape : shapes) {
        cout << "Площадь: " << shape->getArea() << endl;
        cout << "Периметр: " << shape->getPerimeter() << endl;
    }

    // Удаление фигур
    for (Shape* shape : shapes) {
        delete shape; // Вызов виртуального деструктора
    }

    return 0;
}
*/







//4
#include <iostream>
#include <string>
using namespace std;

// Базовый класс Animal
class Animal {
public:
    void eat() {
        cout << "Animal ест" << endl;
    }
};

// Класс, который реализует полёт
class Flyable {
public:
    virtual void fly() = 0; // Чисто виртуальный метод (интерфейс)
};

// Класс Bird наследует от Animal и реализует Flyable
class Bird : public Animal, public Flyable {
public:
    void fly() override {
        cout << "Птица летит" << endl;
    }
};

// Проблема ромба
class Mammal : public Animal {
public:
    void walk() {
        cout << "Млекопитающее ходит" << endl;
    }
};

class Bat : public Mammal, public Flyable {
public:
    void fly() override {
        cout << "Летучая мышь летит" << endl;
    }
};

int main() {
    // Использование Bird
    Bird bird;
    bird.eat(); // Наследование от Animal
    bird.fly(); // Реализация интерфейса Flyable

    // Использование Bat
    Bat bat;
    bat.walk(); // Наследование от Mammal
    bat.fly();  // Реализация интерфейса Flyable

    return 0;
}




























/*
#include <iostream>
using namespace std;

class Animal 
{
public:
    virtual void makeSound() = 0; // Чисто виртуальный метод
};

class Dog : public Animal 
{
public:
    void makeSound() override 
    {
        cout << "Woof!" << endl;
    }
};

int main() 
{
    // Animal a;  // Ошибка! Нельзя создать объект абстрактного класса
    Dog d;
    d.makeSound(); // Выведет: Woof!
}
*/







// Чисто виртуальный деструктор
class Base 
{
public:
    virtual ~Base() = 0; // Чисто виртуальный деструктор
};

Base::~Base() 
{ 
    cout << "Base destructor\n"; 
}

class Derived : public Base 
{
public:
    ~Derived() 
    {
        cout << "Derived destructor\n";
    }
};

int main() 
{
    Base* obj = new Derived();
    delete obj;
}
    



// Обычный виртуальный деструктор
class Base 
{
public:
    ~Base() { cout << "Base destructor\n"; } // ❌ НЕ виртуальный!
};

class Derived : public Base 
{
public:
    ~Derived() { cout << "Derived destructor\n"; }
};

int main() 
{
    Base* obj = new Derived();
    delete obj; // ❌ Вызовет только ~Base(), но не ~Derived()!
}
    





//Зачем нужен виртуальный деструктор?
class Base 
{
public:
    ~Base() { cout << "Base destructor\n"; } // ❌ НЕ виртуальный!
};

class Derived : public Base 
{
public:
    ~Derived() { cout << "Derived destructor\n"; }
};

int main() 
{
    Base* obj = new Derived();
    delete obj; // ❌ Вызовет только ~Base(), но не ~Derived()!
}
    

















#include <iostream>
using namespace std;

// Интерфейс (абстрактный класс)
class IShape 
{
public:
    virtual double area() const = 0;        // Чисто виртуальный метод
    virtual double perimeter() const = 0;   // Чисто виртуальный метод
    virtual ~IShape() {}  // Виртуальный деструктор (для корректного удаления)
};

// Класс "Круг", реализующий интерфейс IShape
class Circle : public IShape 
{
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override 
    {
        return 3.14 * radius * radius;
    }

    double perimeter() const override 
    {
        return 2 * 3.14 * radius;
    }
};


// Класс "Прямоугольник", реализующий интерфейс IShape
class Rectangle : public IShape 
{
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override 
    {
        return width * height;
    }

    double perimeter() const override 
    {
        return 2 * (width + height);
    }
};


int main() 
{
    IShape* c = new Circle(5);
    IShape* r = new Rectangle(4, 6);

    cout << "Площадь круга: " << c->area() << endl;
    cout << "Периметр круга: " << c->perimeter() << endl;

    cout << "Площадь прямоугольника: " << r->area() << endl;
    cout << "Периметр прямоугольника: " << r->perimeter() << endl;

    delete c;
    delete r;
    return 0;
}


















#include <iostream>
using namespace std;

class IAnimal 
{
public:
    virtual void makeSound() const = 0;  // Чисто виртуальный метод
    virtual ~IAnimal() {} // Виртуальный деструктор
};

class Dog : public IAnimal 
{
public:
    void makeSound() const override 
    {
        cout << "Собака лает: Гав-гав!" << endl;
    }
};

class Cat : public IAnimal 
{
public:
    void makeSound() const override 
    {
        cout << "Кот мяукает: Мяу-мяу!" << endl;
    }
};

int main() 
{
    IAnimal* d = new Dog();
    IAnimal* c = new Cat();

    d->makeSound();
    c->makeSound();

    delete d;
    delete c;
    return 0;
}














#include <iostream>
using namespace std;

class IVehicle 
{
public:
    virtual void drive() const = 0;  // Чисто виртуальный метод
    virtual ~IVehicle() {}
};

class Car : public IVehicle 
{
public:
    void drive() const override 
    {
        cout << "Машина едет по дороге" << endl;
    }
};

class Boat : public IVehicle 
{
public:
    void drive() const override 
    {
        cout << "Лодка плывет по воде" << endl;
    }
};

int main() 
{
    IVehicle* v1 = new Car();
    IVehicle* v2 = new Boat();

    v1->drive();
    v2->drive();

    delete v1;
    delete v2;
    return 0;
}







/*

Задание 1: Интерфейс "Музыкальный инструмент"

Создай интерфейс IMusicalInstrument с методом play(). 
Реализуй классы Guitar и Piano, которые играют разные звуки.





Задание 2: Интерфейс "Перевозка"

Создай интерфейс ITransport с методом move(). 
Реализуй Bicycle и Airplane, у которых разное поведение.

*/




















//1
#include <iostream>
using namespace std;

class IMusicalInstrument 
{
public:
    virtual void play() const = 0;
    virtual ~IMusicalInstrument() {}
};

class Guitar : public IMusicalInstrument 
{
public:
    void play() const override 
    {
        cout << "Гитара играет: Бринь-бринь" << endl;
    }
};

class Piano : public IMusicalInstrument 
{
public:
    void play() const override 
    {
        cout << "Пианино играет: Плиинь-плиинь" << endl;
    }
};

int main() 
{
    IMusicalInstrument* g = new Guitar();
    IMusicalInstrument* p = new Piano();

    g->play();
    p->play();

    delete g;
    delete p;
    return 0;
}




//2
#include <iostream>
using namespace std;

class ITransport 
{
public:
    virtual void move() const = 0;
    virtual ~ITransport() {}
};

class Bicycle : public ITransport 
{
public:
    void move() const override 
    {
        cout << "Велосипед едет по дороге" << endl;
    }
};

class Airplane : public ITransport 
{
public:
    void move() const override 
    {
        cout << "Самолет летит в небе" << endl;
    }
};

int main() 
{
    ITransport* b = new Bicycle();
    ITransport* a = new Airplane();

    b->move();
    a->move();

    delete b;
    delete a;
    return 0;
}






/*

Задание 1: 
Управление документами
Создай систему для работы с документами.
Требования:

Создай интерфейс IDocument с методами:
    void open() const = 0;
    void save() const = 0;

Создай абстрактный класс TextDocument, который реализует IDocument и добавляет метод edit().

Реализуй два класса:
    WordDocument, который открывается в Word и редактируется.
    PDFDocument, который можно только открывать и сохранять, но не редактировать.

В main() создай массив документов и вызови их методы





Задание 2: 
Оплата заказов
Разработай систему онлайн-платежей.
Требования:

Создай интерфейс IPaymentMethod с методами:
    void pay(double amount) const = 0;
    void refund(double amount) const = 0;

Создай абстрактный класс BankPayment, который реализует IPaymentMethod и добавляет метод checkBalance().

Реализуй два класса:
    CreditCardPayment, который позволяет оплатить и вернуть деньги.
    CryptoPayment, который позволяет оплатить, но не делать возвраты.

В main() создай массив платежных методов и вызови их методы.




Задание 3: 
Система логирования
Разработай систему логирования сообщений с разными уровнями логов.
Требования:

Создай интерфейс ILogger с методами:
    void logInfo(const string& message) const = 0;
    void logError(const string& message) const = 0;

Создай абстрактный класс BaseLogger, который реализует ILogger и добавляет метод setLogLevel(int level).

Реализуй два класса:
    FileLogger, который записывает логи в файл.
    ConsoleLogger, который выводит логи в консоль.

В main() протестируй работу разных логгеров.


*/











