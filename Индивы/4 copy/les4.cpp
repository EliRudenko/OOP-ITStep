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

