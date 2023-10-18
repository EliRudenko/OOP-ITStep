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

    static const double PENSION_FUND_PERCENTAGE; //процент пенсионного фонда
    static const double INCOME_TAX_PERCENTAGE; // проценкт налога прибыли

public:
    Payment(const char* name, double salary, int start_year, double bonus_percent, double income_tax, int worked_days, int total_days);
    ~Payment();
    void calcul_accrued_am(); //НАЧИСЛЕННАЯ СУММА
    void calcul_withheld_am(); // УДЕРЖАННАЯ СУММА
    void calcul_net_am(); //ВЫДАЕТСЯ НА РУКИ
    int calcul_experience(); //СТАЖ
    void print(); 

    //ПЕРЕГРУЗКА ОПЕР.
    Payment& operator+=(const Payment& other);
    Payment& operator-=(const Payment& other);
    Payment& operator*=(double multiplier);
    Payment& operator/=(double divisor);
};


