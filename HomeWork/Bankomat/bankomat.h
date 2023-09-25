#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

#include <string>

// Номиналы: 10, 50, 100, 500, 1000

struct Denomination 
{
    int value;
    int count;
};

class Bankomat 
{
private:
    std::string id; // номер банкомата
    Denomination denominations[5]; // Номиналы: 10, 50, 100, 500, 1000
    int totalMoney; // сумма денег в банкомате
    int minWithdrawal; // мин сумма снятия
    int maxWithdrawal; // макс сумма сняти
    bool powerOn; // вкл/выкс
    int failedAttempts; // неудачные попытки снятия
    int maxAttempts; // макс код во попыток

public:
    Bankomat(std::string id, int minWithdrawal, int maxWithdrawal, int totalMoney, int maxAttempts); // конструктор

    void loadMoney(int count10, int count50, int count100, int count500, int count1000); // загрузка денег в банкомат
    bool power(bool on); // выкл вкл
    bool withdraw(int amount); // снятие
    bool checkStatus(); // статус банкомата
    void printStatus(); // статус денег в банкомате
    std::string toString(); // строка статуса
    bool changeLimits(int newMin, int newMax); // меняет мин и макс

//доп методы
    bool checkDenominations(int count10, int count50, int count100, int count500, int count1000);
    bool checkWithdrawal(int amount);
};
