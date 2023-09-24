#include "payment.cpp"
#include <iostream>

int main() 
{
    char name[100];
    double salary, bonus_percent, income_tax;
    int start_year, worked_days, total_days;

    std::cout << "Enter your full name: ";
    std::cin.getline(name, 100);

    std::cout << "Enter salary: ";
    std::cin >> salary;

    std::cout << "Enter the year you started working: ";
    std::cin >> start_year;

    std::cout << "Enter the bonus percentage: ";
    std::cin >> bonus_percent;

    std::cout << "Enter income tax (%): ";
    std::cin >> income_tax;

    std::cout << "Enter the number of days worked in the month: ";
    std::cin >> worked_days;

    std::cout << "Enter the number of working days in a month: ";
    std::cin >> total_days;

    //объект класса Payment
    Payment data_employee(name, salary, start_year, bonus_percent, income_tax, worked_days, total_days);

    data_employee.calcul_accrued_am();
    data_employee.calcul_withheld_am();
    data_employee.calcul_net_am();

    data_employee.print();


    /*
    //БЫСТРАЯ ПРОВЕРКА + ПЕРЕГРУЗКА
    Payment additionalPayment("Additional salary", 10000, 2023, 10, 15, 20, 25);
    data_employee += additionalPayment; // Увеличиваем зарплату с помощью оператора +=
    data_employee.display(); // Выводим обновленную информацию
    */

    return 0;
}
