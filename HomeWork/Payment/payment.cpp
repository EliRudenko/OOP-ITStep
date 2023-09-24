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

Payment::~Payment() {
    // Освобождаем память, выделенную под fullName
    delete[] fullName;
}

void Payment::calculateAccruedAmount() {
    // Рассчитываем начисленную сумму как произведение оклада на отношение отработанных дней к общему числу дней в месяце
    accruedAmount = (salary / totalDays) * workedDays;

    // Добавляем надбавку
    accruedAmount += (bonusPercentage / 100) * accruedAmount;
}

void Payment::calculateWithheldAmount() {
    // Вычисляем сумму, подлежащую удержанию в пенсионный фонд (1% от начисленной суммы)
    double pensionFund = PENSION_FUND_PERCENTAGE * accruedAmount;

    // Вычисляем сумму подоходного налога (13% от начисленной суммы)
    double tax = INCOME_TAX_PERCENTAGE * accruedAmount;

    // Общая удержанная сумма
    withheldAmount = pensionFund + tax;
}

void Payment::calculateNetAmount() {
    // Начисленная сумма минус удержанная сумма
    double netAmount = accruedAmount - withheldAmount;
}

int Payment::calculateExperience() {
    // Текущий год
    int currentYear = 2023;

    // Вычисляем стаж как разницу между текущим годом и годом поступления на работу
    int experience = currentYear - startYear;

    return experience;
}

void Payment::display() {
    // Выводим информацию о зарплате
    std::cout << "ФИО: " << fullName << std::endl;
    std::cout << "Стаж: " << calculateExperience() << " лет" << std::endl;
    std::cout << "Начисленная сумма: " << accruedAmount << " рублей" << std::endl;
    std::cout << "Удержанная сумма: " << withheldAmount << " рублей" << std::endl;
    std::cout << "Сумма, выдаваемая на руки: " << (accruedAmount - withheldAmount) << " рублей" << std::endl;
}

// Перегрузка операторов
Payment& Payment::operator+=(const Payment& other) {
    // Сложение начисленных сумм
    this->accruedAmount += other.accruedAmount;

    // Сложение удержанных сумм
    this->withheldAmount += other.withheldAmount;

    return *this;
}

Payment& Payment::operator-=(const Payment& other) {
    // Вычитание начисленных сумм
    this->accruedAmount -= other.accruedAmount;

    // Вычитание удержанных сумм
    this->withheldAmount -= other.withheldAmount;

    return *this;
}

Payment& Payment::operator*=(double multiplier) {
    // Умножение начисленных и удержанных сумм на множитель
    this->accruedAmount *= multiplier;
    this->withheldAmount *= multiplier;

    return *this;
}

Payment& Payment::operator/=(double divisor) {
    // Деление начисленных и удержанных сумм на делитель
    this->accruedAmount /= divisor;
    this->withheldAmount /= divisor;

    return *this;
}
