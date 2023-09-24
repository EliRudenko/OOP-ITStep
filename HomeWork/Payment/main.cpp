#include "payment.cpp"
#include <iostream>

int main() {
    // Просим пользователя ввести данные
    char name[100];
    double salary, bonusPercentage, incomeTax;
    int startYear, workedDays, totalDays;

    std::cout << "Введите ФИО: ";
    std::cin.getline(name, 100);

    std::cout << "Введите оклад: ";
    std::cin >> salary;

    std::cout << "Введите год поступления на работу: ";
    std::cin >> startYear;

    std::cout << "Введите процент надбавки: ";
    std::cin >> bonusPercentage;

    std::cout << "Введите подоходный налог (%): ";
    std::cin >> incomeTax;

    std::cout << "Введите количество отработанных дней в месяце: ";
    std::cin >> workedDays;

    std::cout << "Введите количество рабочих дней в месяце: ";
    std::cin >> totalDays;

    // Создаем объект класса Payment
    Payment employee(name, salary, startYear, bonusPercentage, incomeTax, workedDays, totalDays);

    // Выполняем все необходимые расчеты
    employee.calculateAccruedAmount();
    employee.calculateWithheldAmount();
    employee.calculateNetAmount();

    // Выводим информацию о зарплате
    employee.display();

    // Примеры использования перегруженных операторов
    Payment additionalPayment("Дополнительная зарплата", 10000, 2022, 5, 10, 20, 30);
    employee += additionalPayment; // Увеличиваем зарплату с помощью оператора +=
    employee.display(); // Выводим обновленную информацию

    return 0;
}
