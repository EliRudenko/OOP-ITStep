#include <iostream>


/*
Индексация массивов через указатели

Напишите программу, ко торая создает массив из 5 целых чисел. Затем выведите:
Адрес второго элемента массива с использованием & и индекса.
Адрес второго элемента с использованием  + 1.
Значение второго элемента с использованием индексации массива.
Значение второго элемента с использованием арифметики указателя ссылки на первый элемент + 1.
*/




char name[30]; // Надеемся, что имя игрока будет короче 30 символов


int main() 
{
    int* number = new int; // Выделяем память для целого числа
    *number = 10; // Сохраняем значение 10 в выделенной памяти


    delete number; // Возвращаем память операционной системе
    number = nullptr; // Делаем указатель пустым


//неудача выделения памяти
    int* number = new (std::nothrow) int; // Если памяти нет, number будет nullptr
    if (!number) {
        std::cout << "Не удалось выделить память!";
    }

}







void boo() 
{
    boo(); // функция вызывает себя снова и снова
}

int main() 
{
    boo();
    return 0;
}











class Notebook 
{
    private:
        int batteryCharge; // заряд батареи в %
        bool screenOn;     // экран включён или выключен

    public:
        Notebook() : batteryCharge(100), screenOn(false) {}

        // функция для включения экрана
        void turnOnScreen() 
        {
            screenOn = true;
        }

        // функция для выключения экрана
        void turnOffScreen() 
        {
            screenOn = false;
        }

        // получаем состояние батареи
        int getBatteryCharge() const 
        {
            return batteryCharge;
        }
};





class Notebook 
{
private:
    int batteryCharge;

public:
    Notebook() : batteryCharge(100) {}

    // геттер для уровня заряда
    int getBatteryCharge() const 
    {
        return batteryCharge;
    }

    // сеттер для обновления уровня заряда
    void setBatteryCharge(int newCharge) 
    {
        if (newCharge >= 0 && newCharge <= 100) 
        {
            batteryCharge = newCharge;
        }
    }
};

int main()
{
    Notebook myNotebook;
    std::cout << "Текущий заряд батареи: " << myNotebook.getBatteryCharge() << "%\n";
}









class Example 
{
    private:
        int number;

    public:
        Example(int num) 
        {
            setNumber(num);
        }

        void setNumber(int num) 
        { 
            number = num; // Здесь `number` — это `number` текущего объекта
        }

        int getNumber()
        { 
            return number;
        }
};

int main() 
{
    Example example(5);
    example.setNumber(10);
    std::cout << example.getNumber() << '\n'; // Выведет 10
    return 0;
}







int main() 
{
    Example obj1(3); // `*this` указывает на `obj1` внутри конструктора
    Example obj2(7); // `*this` указывает на `obj2` внутри конструктора

    obj1.setNumber(8); // `*this` указывает на `obj1`
    obj2.setNumber(10); // `*this` указывает на `obj2`

    std::cout << obj1.getNumber() << '\n'; // Выведет 8
    std::cout << obj2.getNumber() << '\n'; // Выведет 10

    return 0;
}







class Person 
{
private:
    int age;

public:
    Person(int age) 
    { 
        
        this->age = age; // `this->age` - это поле класса, а `age` - параметр конструктора
    }
};





/*
Конструктор с параметром

Напишите класс Rectangle, у которого есть поля width и height. 
Создайте конструктор, который принимает параметры с такими же именами (width и height) 
и инициализирует поля класса значениями параметров. 
Используйте указатель this, чтобы избежать конфликта имён.
*/




/*
Проверка на равенство объектов

Создайте класс Point с полями x и y, представляющими координаты точки. 
Напишите метод equals(const Point& other), который сравнивает текущий объект с другим объектом типа Point и возвращает true, если они равны. 
Используйте this, чтобы явно указать на текущий объект.
*/



/*
Метод для сравнения объектов

Напишите класс Employee с полями name и id. 
Создайте метод compareId(const Employee& other), который возвращает true, если id текущего объекта больше, чем у другого объекта. 
Используйте this для обращения к полю id текущего объекта.
*/







//1
class Rectangle 
{
    private:
        int width;
        int height;

    public:
        // Конструктор с параметрами
        Rectangle(int width, int height) 
        {
            // Используем указатель this, чтобы избежать конфликта имен
            this->width = width;
            this->height = height;
        }

        // Метод для вывода размеров
        void printDimensions() const 
        {
            std::cout << "Width: " << this->width << ", Height: " << this->height << std::endl;
        }
};

int main() 
{
    Rectangle rect(10, 5);
    rect.printDimensions(); // Width: 10, Height: 5
    return 0;
}





//2
#include <iostream>

class Point 
{
    private:
        int x, y;

    public:
        Point(int x, int y) : x(x), y(y) {}

        // Метод для сравнения с другим объектом
        bool equals(const Point& other) const  //по ссылке, чтобы избежать копирования.
        {
            return this->x == other.x && this->y == other.y;  // Сравниваем координаты
        }
};

int main() 
{
    Point p1(3, 4);
    Point p2(3, 4);
    Point p3(5, 6);

    std::cout << "p1 == p2: " << p1.equals(p2) << std::endl; // true
    std::cout << "p1 == p3: " << p1.equals(p3) << std::endl; // false
    return 0;
}




//3
#include <iostream>
#include <string>

class Employee 
{
    private:
        std::string name;
        int id;

    public:
        Employee(std::string name, int id) : name(name), id(id) {}

        // Метод для сравнения id
        bool compareId(const Employee& other) const 
        {
            return this->id > other.id;  // Сравниваем id
        }
};

int main() 
{
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);

    std::cout << "emp1 has higher id than emp2: " << emp1.compareId(emp2) << std::endl;  // false
    return 0;
}
