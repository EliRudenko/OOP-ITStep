#include <iostream>
#include <string>
using namespace std;

/*
Создайте класс Animal с полями name (имя) и age (возраст). Реализуйте:

Конструктор по умолчанию и параметризованный конструктор.
Метод printInfo() для вывода информации о животном (используйте this).
Деструктор с выводом сообщения о удалении животного.
Дополнительно:
Создайте класс-наследник Dog с полем breed (порода) и переопределённым методом printInfo().

В main() создайте объекты классов Animal и Dog, выведите их информацию, и проверьте вызов деструкторов.

*/



// Базовый класс Animal
class Animal 
{
protected:
    string name;
    int age;

public:
    // Конструктор по умолчанию
    Animal() : name("Unknown"), age(0) 
    {
        cout << "Animal created: " << name << ", " << age << " years old" << endl;
    }

    // Параметризованный конструктор
    Animal(string name, int age) : name(name), age(age) 
    {
        cout << "Animal created: " << name << ", " << age << " years old" << endl;
    } 

    // Метод для вывода информации
    void printInfo() const 
    {
        cout << "Animal: " << name << ", Age: " << age << endl;
    }

    // Деструктор
    ~Animal() { cout << "Animal " << name << " is removed from memory." << endl; }
};

// Класс-наследник Dog
class Dog : public Animal 
{
private:
    string breed;

public:
    // Конструктор Dog
    Dog(string name, int age, string breed) : Animal(name, age), breed(breed) 
    {
        cout << "Dog created: " << name << ", " << age << " years old, Breed: " << breed << endl;
    }

    // Метод для вывода информации (с использованием перегрузки имени метода)
    void printInfo() const 
    {
        cout << "Dog: " << name << ", Age: " << age << ", Breed: " << breed << endl;
    }

    // Деструктор
    ~Dog() { cout << "Dog " << name << " of breed " << breed << " is removed from memory." << endl; }
};

int main() 
{
    // Создание объектов
    Animal a1; // Объект с конструктором по умолчанию
    Animal a2("Tiger", 3); // Объект с параметризованным конструктором
    Dog d1("Max", 5, "Labrador"); // Объект класса Dog

    // Вывод информации о животных
    a1.printInfo();
    a2.printInfo();
    d1.printInfo();

    return 0;
}






/*
Создайте классы для ноутбука:

Класс Processor:
Поля: brand (бренд), cores (количество ядер).
Методы: конструктор, setProce    ssor() для изменения данных, printInfo() для вывода информации.

Класс Battery:
Поле: capacity (ёмкость в мАч).
Методы: конструктор, setCapacity() для изменения ёмкости, printInfo() для вывода информации.

Класс Laptop:
Поля: model (модель), объект Processor, указатель на Battery.
Методы: конструктор, setModel() для изменения модели, printInfo() для вывода информации о ноутбуке, процессоре и батарее.

В функции main:
Создайте ноутбук с процессором и батареей.
Измените параметры процессора, батареи и модели.
Выведите информацию о ноутбуках.
*/






// Класс Processor (композиция)
class Processor 
{
private:
    string brand;
    int cores;

public:
    Processor(string brand, int cores) : brand(brand), cores(cores) {}

    // Установка данных через this
    void setProcessor(string brand, int cores) 
    {
        this->brand = brand;
        this->cores = cores;
    }

    void printInfo() const { cout << "Processor: " << this->brand << ", Cores: " << this->cores << endl; }
};

// Класс Battery (агрегация!!!!)
class Battery 
{
private:
    int capacity;

public:
    Battery(int capacity) : capacity(capacity) {}

    // Установка данных через this
    void setCapacity(int capacity)
    {
        this->capacity = capacity;
    }

    void printInfo() const { cout << "Battery: " << this->capacity << " mAh" << endl; }
};


class Laptop 
{
private:
    string model;
    
    Processor processor; // Композиция: процессор является частью ноутбука
    Battery* battery;    // Агрегация: батарея может быть общей

public:
    Laptop(string model, Processor processor, Battery* battery = nullptr): model(model), processor(processor), battery(battery) {}

    // Установка модели ноутбука через this
    void setModel(string model) 
    {
        this->model = model;
    }


    void printInfo() const 
    {
        cout << "Laptop Model: " << this->model << endl;
        this->processor.printInfo();

        if (this->battery) 
            this->battery->printInfo();
        else 
            cout << "Battery: None" << endl;
    }
};

int main() 
{
    // Создание батареи
    Battery battery1(5000);
    battery1.setCapacity(5500); // Изменение ёмкости батареи через метод с this

    // Создание процессора
    Processor processor1("Intel", 8);
    processor1.setProcessor("AMD", 12); // Изменение данных процессора через метод с this


    // Создание ноутбуков
    Laptop laptop1("Dell XPS 13", processor1, &battery1); // С батареей

    laptop1.setModel("Dell XPS 15"); // Изменение модели ноутбука через метод с this

    Laptop laptop2("MacBook Air", Processor("Apple M1", 4)); // Без батареи


    cout << "Laptop 1:" << endl;
    laptop1.printInfo();

    cout << "\nLaptop 2:" << endl;
    laptop2.printInfo();

    return 0;
}























/*
Статические поля и методы принадлежат всему классу
Они общие для всех объектов этого класса

Поле: Все объекты будут видеть и использовать одну и ту же переменную
Метод: Функцию можно вызвать без создания объекта

*/


//Статические поля — общие переменные для всего класса, не зависят от объектов

//1
class Car 
{
public:
    static int totalCars; // Статическое поле — общее для всех объектов

    Car() 
    {
        totalCars++; // Увеличиваем общее количество машин при создании
    }
};

int Car::totalCars = 0; // Обязательно инициализируем статическое поле вне класса



int main() 
{
   
    std::cout << "Total cars: " << Car::totalCars << std::endl; // Доступ через класс
    return 0;
}






//Статические методы — функции, которые можно вызывать через класс, без создания объекта

//2
class Car 
{
public:
    static int totalCars; // Общее количество машин

    static void showTotalCars() 
    { // Статический метод
        std::cout << "Total cars: " << totalCars << std::endl;
    }
};

int Car::totalCars = 0; // Инициализация статической переменной

int main() 
{
    Car::showTotalCars(); // Вызываем метод через класс — "Total cars: 0"

    Car car1;
    Car::totalCars++;
    Car::showTotalCars(); // "Total cars: 1"

    Car car2;
    Car::totalCars++;
    Car::showTotalCars(); // "Total cars: 1"

    return 0;
}













/*
Задание 1: Статическое поле
Создать класс BankAccount, который будет моделировать банковский счет. У каждого клиента будет свой баланс. 
Также будет одно статическое поле для хранения общего количества созданных счетов.

В классе:
Статическое поле totalAccounts, которое хранит общее количество счетов.
Нестатическое поле balance, которое хранит баланс каждого клиента.
Конструктор, который увеличивает totalAccounts при создании нового счета.
Метод deposit(), который добавляет деньги на счет.
Метод withdraw(), который снимает деньги со счета.
Метод getBalance(), который возвращает текущий баланс клиента, используя this.

В функции main:
Создать несколько объектов класса BankAccount.
В каждом объекте вызвать методы deposit() и withdraw().
Вывести общий баланс каждого счета и общее количество счетов.
*/





/*
Задание 2: Статический метод

Создать класс MathUtils, который будет содержать статический метод add(), 
который принимает два числа и возвращает их сумму. 
Внесем изменения, добавив нестатический метод multiply(), который будет использовать this.

В классе MathUtils:
Статический метод add(), который принимает два числа и возвращает их сумму.
Нестатический метод multiply(), который принимает два числа и возвращает их произведение, 
используя this для обращения к своим данным.
*/







//1
class BankAccount 
{
public:
    static int totalAccounts;  // Статическое поле для подсчета количества счетов
    double balance;            // Баланс каждого клиента

    BankAccount() 
    {
        totalAccounts++;  // Увеличиваем количество счетов
        balance = 0;      // Изначально баланс 0
    }

    // Метод для пополнения счета
    void deposit(double amount) 
    {
        this->balance += amount;  
    }

    // Метод для снятия денег со счета
    void withdraw(double amount) 
    {
        if (amount <= this->balance) 
            this->balance -= amount;
        else 
            cout << "Недостаточно средств для снятия." << endl;
    }

    // Метод для получения текущего баланса
    double getBalance() const { return this->balance;  }
};

// Инициализация статического поля вне класса
int BankAccount::totalAccounts = 0;

int main() 
{
    BankAccount account1;
    account1.deposit(1000);
    account1.withdraw(200);
    
    BankAccount account2;
    account2.deposit(1500);
    
    cout << "Баланс счета 1: " << account1.getBalance() << endl;
    cout << "Баланс счета 2: " << account2.getBalance() << endl;
    
    cout << "Общее количество счетов: " << BankAccount::totalAccounts << endl;
    
    return 0;
}






//2
class MathUtils 
{
public:
    // Статический метод для сложения двух чисел
    static int add(int a, int b) { return a + b; }

    // Нестатический метод для умножения двух чисел
    int multiply(int a, int b) { return a * b; }
};

int main() 
{
    // Вызов статического метода через имя класса
    int resultAdd = MathUtils::add(10, 20);
    cout << "Результат сложения: " << resultAdd << endl;

    // Создание объекта для вызова нестатического метода
    MathUtils math;
    int resultMultiply = math.multiply(10, 20);  // Используем объект для вызова multiply
    cout << "Результат умножения: " << resultMultiply << endl;

    return 0;
}









// Делегирование конструкторов



/*
Делегирование конструкторов — это процесс, когда один конструктор вызывает другой конструктор того же класса. 
Это позволяет избежать повторения кода в разных конструкторах.
*/



class Cars 
{
public:
    int wheels;
    string color;

    // Конструктор с параметрами
    Cars(int w, string c) 
    {
        wheels = w;
        color = c;
        cout << "Создан автомобиль с " << wheels << " колесами и цветом " << color << endl;
    }

    // Конструктор без параметров (делегирует вызов конструктора с параметрами)
    Cars() : Cars(4, "black") 
    {  // Делегирование: вызывает конструктор с параметрами (4, "black")
        cout << "Создан стандартный автомобиль" << endl;
    }
};

int main() 
{
    Cars myCar(6, "red");  // Используется конструктор с параметрами
    Cars defaultCar;       // Используется конструктор без параметров, который делегирует вызов другому конструктору
    return 0;
}








class Rectangle 
{
public:
    int length;
    int width;

    // Конструктор с параметрами (длина и ширина)
    Rectangle(int l, int w) 
    {
        length = l;
        width = w;
    }

    // Конструктор, который делегирует вызов другому конструктору
    Rectangle(int side) : Rectangle(side, side) 
    {
        cout << "Создан квадрат" << endl;
    }

    // Конструктор без параметров
    Rectangle() : Rectangle(1, 1) 
    {  // Делегируем на создание квадрата со стороной 1
        cout << "Создан стандартный прямоугольник (1x1)" << endl;
    }

    // Метод для вычисления площади
    int area() { return length * width; }
};

int main() 
{
    Rectangle rect1(10, 5);  // Конструктор с длиной и шириной
    Rectangle square(4);      // Конструктор с одной стороной (делегирует на квадрат)
    Rectangle defaultRect;    // Конструктор без параметров (делегирует на прямоугольник 1x1)

    cout << "Площадь первого прямоугольника: " << rect1.area() << endl;
    cout << "Площадь квадрата: " << square.area() << endl;
    cout << "Площадь стандартного прямоугольника: " << defaultRect.area() << endl;

    return 0;
}




/*
Задание 1: Создание класса Book
Создайте класс Book, который будет описывать книгу. У класса должны быть следующие поля:

title (название книги) — строка;
author (автор книги) — строка;
year (год издания) — целое число.
Реализуйте три конструктора:

Один конструктор должен принимать все параметры (название, автор и год издания).

Второй конструктор должен принимать только название и автора, устанавливая год издания по умолчанию на 2000.

Третий конструктор должен устанавливать только название книги, 
оставляя автора и год издания значениями по умолчанию: "Неизвестен" и 2000 соответственно.

Используйте делегирование конструкторов для реализации 
второго и третьего конструкторов, чтобы избежать дублирования кода.

*/


// Класс Book
class Book 
{
public:
    string title;   // Название книги
    string author;  // Автор книги
    int year;       // Год издания

    // Конструктор с параметрами: название, автор, год
    Book(string t, string a, int y) 
    {
        title = t;
        author = a;
        year = y;
        cout << "Книга: \"" << title << "\", автор: \"" << author << "\", год: " << year << endl;
    }

    // Конструктор с параметрами: название, автор, год по умолчанию
    Book(string t, string a) : Book(t, a, 2000) 
    {
        cout << "Книга: \"" << title << "\", автор: \"" << author << "\", год: " << year << endl;
    }

    // Конструктор с параметрами: только название, автор по умолчанию, год по умолчанию
    Book(string t) : Book(t, "Неизвестен", 2000)
    {
        cout << "Книга: \"" << title << "\", автор: \"" << author << "\", год: " << year << endl;
    }
};

int main() 
{
    Book book1("Патерни об'єктно-орієнтованого проектування", "Джон Влиссидес, Эрих Гамма, Ричард Хелм, Р. Джонсон", 2020);

    Book book2("Полный справочник по C++", "Герберт Шилдт");

    Book book3("Без названия");

    return 0;
}






//Константы требуют, чтобы значение было задано при создании объекта, так как их значения не могут изменяться после инициализации.
class Cars2 
{
public:
    const string brand;  // Константная переменная
    const int year;      // Константная переменная

    // Конструктор, который инициализирует константы через список инициализации
    Cars2(string b, int y) : brand(b), year(y) 
    {
        // Здесь константы уже проинициализированы, их нельзя изменить
    }
};

int main() 
{
    Cars2 car("Tesla", 2022);
    cout << "Марка: " << car.brand << ", Год: " << car.year << endl;
    return 0;
}




//Ссылка должна быть инициализирована при объявлении, и после этого она будет всегда ссылаться на тот же объект.
class Rectangle2 
{
public:
    int width, height;
    int &refWidth;  // Ссылка на ширину

    // Конструктор, который инициализирует ссылку через список инициализации
    Rectangle2(int w, int h) : width(w), height(h), refWidth(width) 
    {
        // Ссылка refWidth теперь ссылается на переменную width
    }

    void display() 
    {
        cout << "Ширина: " << width << ", Высота: " << height << endl;
        cout << "Ссылка на ширину: " << refWidth << endl;
    }
};

int main() 
{
    Rectangle2 rect(10, 20);
    rect.display();  // Выводим ширину и высоту через ссылку
    return 0;
}






/*
Задание: Работа с константами и ссылками
Создать класс Book, который имеет:

Константные поля: const string title и const string author.
Обычное поле int year.
В классе:

Создать конструктор для инициализации всех полей.
Написать метод display(), который выводит информацию о книге.
Добавить ссылку:

В класс добавить ссылку const string &refTitle, которая будет ссылаться на title.
В методе display() вывести информацию через ссылку.
В функции main():

Создать объект Book и вывести информацию.
Попробовать изменить значение через ссылку и показать, что ссылка не может изменять константное значение.
*/