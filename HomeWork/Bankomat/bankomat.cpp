#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

#include "bankomat.h"

#include <iostream>

Bankomat::Bankomat(std::string id, int minWithdrawal, int maxWithdrawal, int totalMoney, int maxAttempts) 
{
    this->id = id;
    this->minWithdrawal = minWithdrawal;
    this->maxWithdrawal = maxWithdrawal;
    this->totalMoney = totalMoney;
    this->powerOn = false;
    this->failedAttempts = 0;
    this->maxAttempts = maxAttempts;

    denominations[0] = {10, 0};
    denominations[1] = {50, 0};
    denominations[2] = {100, 0};
    denominations[3] = {500, 0};
    denominations[4] = {1000, 0};
}

bool Bankomat::checkDenominations(int count10, int count50, int count100, int count500, int count1000) 
{
    return (count10 >= 0 && count50 >= 0 && count100 >= 0 && count500 >= 0 && count1000 >= 0);
}

bool Bankomat::checkWithdrawal(int amount) 
{ 
    return (amount >= minWithdrawal && amount <= maxWithdrawal && amount <= totalMoney); 
}

void Bankomat::loadMoney(int count10, int count50, int count100, int count500, int count1000) 
{
    if (!powerOn) 
    {
        std::cout << "Bankomat is off." << std::endl;
        return;
    }

    if (!checkDenominations(count10, count50, count100, count500, count1000)) 
    {
        std::cout << "Invalid denominations provided." << std::endl;
        return;
    }

    denominations[0].count += count10;
    denominations[1].count += count50;
    denominations[2].count += count100;
    denominations[3].count += count500;
    denominations[4].count += count1000;

    totalMoney += (count10 * 10 + count50 * 50 + count100 * 100 + count500 * 500 + count1000 * 1000);

    std::cout << "Money loaded successfully!" << std::endl;
    std::cout << std::endl;
}

bool Bankomat::power(bool on) 
{
    if (on) 
    {
        if (powerOn) 
        {
            std::cout << "Bankomat is already on" << std::endl;
            return false;
        }
        powerOn = true;
        std::cout << "Bankomat powered on" << std::endl;
        return true;
    } 
    else 
    {
        if (!powerOn) 
        {
            std::cout << "Bankomat is already off!" << std::endl;
            return false;
        }
        powerOn = false;
        std::cout << "Bankomat powered off!" << std::endl;
        return true;
    }
}

bool Bankomat::withdraw(int amount) 
{
    if (!powerOn) 
    {
        std::cout << "Bankomat is off!" << std::endl;
        return false;
    }

    if (failedAttempts >= maxAttempts) 
    {
        std::cout << "Too many failed attempts. Bankomat is locked!" << std::endl;
        return false;
    }

    if (!checkWithdrawal(amount)) 
    {
        std::cout << "Invalid withdrawal amount!" << std::endl;
        failedAttempts++;
        return false;
    }

    int amountLeft = amount;

    for (int i = 4; i >= 0; i--) 
    {
        int count = amountLeft / denominations[i].value;
        if (count > denominations[i].count) { count = denominations[i].count; }

        amountLeft -= count * denominations[i].value;
        denominations[i].count -= count;
    }

    totalMoney -= amount;

    std::cout << "Withdrawal successful!" << std::endl;
    failedAttempts = 0;

    return true;
}

bool Bankomat::checkStatus() { return powerOn; }

void Bankomat::printStatus() 
{
    if (powerOn) 
    {
        std::cout << "Bankomat is powered on!" << std::endl;
    } 
    else { std::cout << "Bankomat is powered off!" << std::endl;}
}

std::string Bankomat::toString() 
{
    return "Money in ATM: " + std::to_string(denominations[0].count * 10 + denominations[1].count * 50 + denominations[2].count * 100 + denominations[3].count * 500 + denominations[4].count * 1000);
}

bool Bankomat::changeLimits(int newMin, int newMax)
{
    if (!powerOn) 
    {
        std::cout << "Bankomat is off!" << std::endl;
        return false;
    }

    if (newMin >= newMax) 
    {
        std::cout << "New limits are not valid!" << std::endl;
        return false;
    }

    minWithdrawal = newMin;
    maxWithdrawal = newMax;

    std::cout << "Withdrawal limits changed successfully!" << std::endl;
    return true;
}
