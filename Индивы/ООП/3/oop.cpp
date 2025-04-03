#include <iostream>
using namespace std;

class Car 
{
private:
        string brand;
        int speed;
public:
    // Метод для вывода информации об автомобиле
    void showInfo() 
    {
        cout << "Марка: " << brand << ", Скорость: " << speed << " км/ч" << endl;
    }
};

int main() 
{
    Car myCar;  // Создаём объект класса Car
    //myCar.brand = "Toyota";  
    //myCar.speed = 180;  

    myCar.showInfo();  // Вызываем метод

    return 0;
}





#include <iostream>


using namespace std;

enum Gender { Male, Female };


struct Student {
    string name;
    int age;
    double avg;
    Gender gender;
};

//poisk
const Student& fbs(const Student students[], int size) {
    int bg = 0;
    for (int i = 1; i < size; i++) {
        if (students[i].avg > students[bg].avg) {
            bg = i;
        }
    }
    return students[bg];
}

int main() {
    const int numStud = 3;
    Student students[numStud];

    // dannie
    for (int i = 0; i < numStud; i++) {
        cout << "enter name :  " << i + 1 << ": ";
        cin >> students[i].name;

        cout << "enter age : ";
        cin >> students[i].age;

        cout << "enter avg: ";
        cin >> students[i].avg;

        int gender2;
        cout << "enter gender (0 - Male  1 - Female): ";
        cin >> gender2;
        students[i].gender = static_cast<Gender>(gender2);
    }

    // выискивает лучшего студентика 
    const Student& best = fbs(students, numStud);

    // выводит красавчика студента
    cout << "best student:" << endl;
    cout << "name: " << best.name << endl;
    cout << "age: " << best.age << endl;
    cout << "avg: " << best.avg << endl;
    cout << "gender: " << (best.gender == Male ? "Male" : "Female") << endl;

    return 0;
}






#include <iostream>
using namespace std;

class BankAccount 
{
private:  // Прямой доступ запрещён
    double balance;

public:
    BankAccount() 
    { 
        balance = 0; 
    } 

    void deposit(double amount) 
    {
        if (amount > 0) { balance += amount; }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) balance -= amount;
    }

    void showBalance() {
        cout << "Баланс: " << balance << " грн" << endl;
    }
};

int main() 
{
    int amount = 1000;
    BankAccount account;
    account.deposit(amount);
    account.withdraw(300);
    account.showBalance();

    return 0;
}


/*

Создать Класс Ноутбук с полями (3 -4) и методом вывода информации про этот ноутбук. Поля заполняются в конструкторе с передачей параметров
Создать несколько ноутов по этому классу

помнить теорию


*/