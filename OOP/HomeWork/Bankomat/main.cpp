#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

#include <iostream>
#include "bankomat.cpp"

int main() 
{
    std::string id;
    int minWithdrawal, maxWithdrawal, totalMoney, maxAttempts;

    std::cout << "Enter ATM ID: ";
    std::cin >> id;

    std::cout << "Enter minimum withdrawal amount: ";
    std::cin >> minWithdrawal;

    std::cout << "Enter maximum withdrawal amount: ";
    std::cin >> maxWithdrawal;

    std::cout << "Enter total amount of money in ATM: ";
    std::cin >> totalMoney;

    std::cout << "Enter maximum number of failed attempts: ";
    std::cin >> maxAttempts;

    Bankomat atm(id, minWithdrawal, maxWithdrawal, totalMoney, maxAttempts);

    atm.power(true);

    int count10, count50, count100, count500, count1000;

    std::cout << "Enter the number of 10 denominations to load: ";
    std::cin >> count10;

    std::cout << "Enter the number of 50 denominations to load: ";
    std::cin >> count50;

    std::cout << "Enter the number of 100 denominations to load: ";
    std::cin >> count100;

    std::cout << "Enter the number of 500 denominations to load: ";
    std::cin >> count500;

    std::cout << "Enter the number of 1000 denominations to load: ";
    std::cin >> count1000;

    atm.loadMoney(count10, count50, count100, count500, count1000);

    atm.printStatus();

    std::cout << "ATM state: " << atm.toString() << std::endl;

    int amount;

    std::cout << "Enter the amount you want to withdraw: ";
    std::cin >> amount;

    atm.withdraw(amount);

    std::cout << atm.toString() << std::endl;

    return 0;
}
