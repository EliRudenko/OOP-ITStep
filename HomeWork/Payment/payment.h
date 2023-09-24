#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

class Payment 
{
private:
    char* name;
    double salary;
    int start_year;
    double bonus_percent;
    double income_tax;
    int worked_days;
    int total_days;
    double accrued_amount;
    double withheld_amount;

    static const double PENSION_FUND_PERCENTAGE;
    static const double INCOME_TAX_PERCENTAGE;

public:
    Payment(const char* name, double salary, int start_year, double bonus_percent, double income_tax, int worked_days, int total_days);
    ~Payment();
    void calcul_accrued_am(); // Метод для расчета начисленной суммы
    void calcul_withheld_am(); // Метод для расчета удержанной суммы
    void calcul_net_am(); // Метод для расчета суммы, выдаваемой на руки
    int calcul_experience(); // Метод для расчета стажа
    void print(); // Метод для вывода информации о зарплате
    
    // Перегрузка операторов
    Payment& operator+=(const Payment& other);
    Payment& operator-=(const Payment& other);
    Payment& operator*=(double multiplier);
    Payment& operator/=(double divisor);
};


