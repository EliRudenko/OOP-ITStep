#include "payment.h"
#include <iostream>
#include <cstring>

const double Payment::PENSION_FUND_PERCENTAGE = 0.01;
const double Payment::INCOME_TAX_PERCENTAGE = 0.13;

Payment::Payment(const char* Name, double salary, int startYear, double bonusPercentage, double incomeTax, int workedDays, int totalDays) {
    // Выделяем память под fullName и копируем переданное имя
    name = new char[strlen(Name) + 1];
    strcpy(name, Name);

    this->salary = salary;
    this->start_year = startYear;
    this->bonus_percent = bonusPercentage;
    this->income_tax = incomeTax;
    this->worked_days = workedDays;
    this->total_days = totalDays;
}

Payment::~Payment() { delete[] name; }

void Payment::calcul_accrued_am() 
{
    // Рассчитываем начисленную сумму как произведение оклада на отношение отработанных дней к общему числу дней в месяце
    accrued_amount = (salary / total_days) * worked_days;

    // Добавляем надбавку
    accrued_amount += (bonus_percent / 100) * accrued_amount;
}

void Payment::calcul_withheld_am() 
{
    // Вычисляем сумму, подлежащую удержанию в пенсионный фонд (1% от начисленной суммы)
    double pensionFund = PENSION_FUND_PERCENTAGE * accrued_amount;

    // Вычисляем сумму подоходного налога (13% от начисленной суммы)
    double tax = INCOME_TAX_PERCENTAGE * accrued_amount;

    // Общая удержанная сумма
    withheld_amount = pensionFund + tax;
}

void Payment::calcul_net_am () //чистая сумма
{

    // Начисленная сумма минус удержанная сумма
    double netAmount = accrued_amount - withheld_amount;
}

int Payment::calcul_experience() 
{
    // Текущий год
    int currentYear = 2023;

    // Вычисляем стаж как разницу между текущим годом и годом поступления на работу
    int experience = currentYear - start_year;

    return experience;
}


void Payment::print()
{
     std::cout << "Name: " << name << std::endl;
     std::cout << "Experience: " << calcul_experience() << " years" << std::endl;
     std::cout << "Accrued amount: " << accrued_amount << " UAH" << std::endl;
     std::cout << "Amount withheld: " << withheld_amount << " UAH" << std::endl;
     std::cout << "Amount issued in hand: " << (accrued_amount - withheld_amount) << " UAH" << std::endl;
}

// Перегрузка операторов
Payment& Payment::operator+=(const Payment& other) 
{
    // Сложение начисленных сумм
    this->accrued_amount += other.accrued_amount;

    // Сложение удержанных сумм
    this->withheld_amount += other.withheld_amount;

    return *this;
}

Payment& Payment::operator-=(const Payment& other) 
{
    // Вычитание начисленных сумм
    this->accrued_amount -= other.accrued_amount;

    // Вычитание удержанных сумм
    this->withheld_amount -= other.withheld_amount;

    return *this;
}

Payment& Payment::operator*=(double multiplier) 
{
    // Умножение начисленных и удержанных сумм на множитель
    this->accrued_amount *= multiplier;
    this->withheld_amount *= multiplier;

    return *this;
}

Payment& Payment::operator/=(double divisor) 
{
    // Деление начисленных и удержанных сумм на делитель
    this->accrued_amount /= divisor;
    this->withheld_amount /= divisor;

    return *this;
}
