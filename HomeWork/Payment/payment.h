#pragma once

class Payment {
private:
    char* fullName;
    double salary;
    int startYear;
    double bonusPercentage;
    double incomeTax;
    int workedDays;
    int totalDays;
    double accruedAmount;
    double withheldAmount;

    static const double PENSION_FUND_PERCENTAGE;
    static const double INCOME_TAX_PERCENTAGE;

public:
    Payment(const char* name, double salary, int startYear, double bonusPercentage, double incomeTax, int workedDays, int totalDays);
    ~Payment();
    void calculateAccruedAmount(); // Метод для расчета начисленной суммы
    void calculateWithheldAmount(); // Метод для расчета удержанной суммы
    void calculateNetAmount(); // Метод для расчета суммы, выдаваемой на руки
    int calculateExperience(); // Метод для расчета стажа
    void display(); // Метод для вывода информации о зарплате
    
    // Перегрузка операторов
    Payment& operator+=(const Payment& other);
    Payment& operator-=(const Payment& other);
    Payment& operator*=(double multiplier);
    Payment& operator/=(double divisor);
};


