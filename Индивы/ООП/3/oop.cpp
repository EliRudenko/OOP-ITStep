#include <iostream>
using namespace std;

class Car 
{
    public:  // Доступ к переменным открыт
        string brand;
        int speed;

    // Метод для вывода информации об автомобиле
    void showInfo() 
    {
        cout << "Марка: " << brand << ", Скорость: " << speed << " км/ч" << endl;
    }
};

int main() 
{
    Car myCar;  // Создаём объект класса Car
    myCar.brand = "Toyota";  
    myCar.speed = 180;  

    myCar.showInfo();  // Вызываем метод

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
