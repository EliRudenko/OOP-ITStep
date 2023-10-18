#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

#include "payment.h"

const double Payment::PENSION_FUND_PERCENTAGE = 0.01;
const double Payment::INCOME_TAX_PERCENTAGE = 0.13;

Payment::Payment(const char* Name, double salary, int startYear, double bonusPercentage, double incomeTax, int workedDays, int totalDays) 
{
    name = new char[strlen(Name) + 1]; //память под ФИО, копи
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
{//НАЧИСЛЕННАЯ СУММА
    accrued_amount = (salary / total_days) * worked_days;//оклад* отношение отработанных дней и всего дней
    accrued_amount += (bonus_percent / 100) * accrued_amount; // НАДБАВКА
}

void Payment::calcul_withheld_am() 
{//УДЕРЖАННАЯ СУММА
    double pensionFund = PENSION_FUND_PERCENTAGE * accrued_amount; //1% от начисленной
    double tax = INCOME_TAX_PERCENTAGE * accrued_amount; // 13% от начисленной
    withheld_amount = pensionFund + tax; // результат
}

void Payment::calcul_net_am () 
{//ЧИСТАЯ СУММА
    double netAmount = accrued_amount - withheld_amount; //начисленная - удержанная
}

int Payment::calcul_experience() 
{//стаж/опыт
    int currentYear = 2023;//текущий год
    int experience = currentYear - start_year; // текуший год - поступление
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

//ПЕРЕГРУЗНА ОПЕР.
Payment& Payment::operator+=(const Payment& other) //=
{
    this->accrued_amount += other.accrued_amount; //НАЧИСЛ
    this->withheld_amount += other.withheld_amount; // УДЕРЖ

    return *this;
}

Payment& Payment::operator-=(const Payment& other) //-
{
    this->accrued_amount -= other.accrued_amount; // НАЧИСЛ
    this->withheld_amount -= other.withheld_amount; // УДЕРЖ

    return *this;
}

Payment& Payment::operator*=(double multiplier) // *
{
    this->accrued_amount *= multiplier; // НАЧИСЛ
    this->withheld_amount *= multiplier; // УДЕРЖ

    return *this;
}

Payment& Payment::operator/=(double divisor)  // /
{
    this->accrued_amount /= divisor; // НАЧИСЛ
    this->withheld_amount /= divisor; // УДЕРЖ

    return *this;
}
