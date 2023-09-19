#include "Data.h"
#include <iostream>


Date::Date() : day(1), month(1), year(2000) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

void Date::set_day(int d) 
{
    if (d >= 1 && d <= 31)
    {
        day = d;
    }
    else { std::cerr << "Invalid input!" << std::endl; }
}

void Date::set_month(int m) 
{
    if (m >= 1 && m <= 12) 
    {
        month = m;
        if (day > 31) { day = 31;}
    }
    else { std::cerr << "Invalid input!" << std::endl; }
}

void Date::set_year(int y) 
{
    if (y >= 0) 
    {
        year = y;
    }
    else { std::cerr << "Invalid input!" << std::endl; }
}


bool is_valid_date(int day, int month) 
{
    if (day < 1 || day > 31 || month < 1 || month > 12) 
    {
        return false;
    }
    else
    {
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        { 
            return false;
        }
        return true;
    }
}

int Date::get_day() const { return day; }

int Date::get_month() const { return month; }

int Date::get_year() const { return year; }

void Date::print() const { std::cout << day << "." << month << "." << year << std::endl; }

Date& Date::operator++() 
{
    if (day < 31) 
    {
        ++day;
    }
    else 
    {
        day = 1;
        if (month < 12) 
        {
            ++month;
        }
        else 
        {
            month = 1;
            ++year;
        }
    }

    return *this;
}

Date Date::operator++(int) 
{
    Date temp = *this;
    ++(*this);
    return temp;
}

Date& Date::operator--() 
{
    if (day > 1) 
    {
        --day;
    }
    else 
    {
        if (month > 1) 
        {
            --month;
            day = 31;
        }
        else 
        {
            --year;
            month = 12;
            day = 31;
        }
    }

    return *this;
}

Date Date::operator--(int) 
{
    Date temp = *this;
    --(*this);
    return temp;
}

Date Date::operator+(int days) const 
{
    Date result = *this;
    while (days > 0) 
    {
        if (result.day + days <= 31) 
        {
            result.day += days;
            days = 0;
        }
        else 
        {
            days -= 31 - result.day + 1;
            result.day = 1;
            if (result.month < 12) 
            {
                ++result.month;
            }
            else 
            {
                result.month = 1;
                ++result.year;
            }
        }
    }

    return result;
}

Date Date::operator-(int days) const 
{
    Date result = *this;
    while (days > 0) 
    {
        if (result.day - days >= 1) 
        {
            result.day -= days;
            days = 0;
        }
        else 
        {
            days -= result.day;
            if (result.month > 1) 
            {
                --result.month;
                result.day = 31;
            }
            else 
            {
                --result.year;
                result.month = 12;
                result.day = 31;
            }
        }
    }
    return result;
}

int Date::operator-(const Date& add_inf) const 
{
    int days = 0;
    Date temp = *this;
    if (*this < add_inf)
    {
        while (temp != add_inf)
        {
            ++temp;
            ++days;
        }
    }
    else 
    {
        while (temp != add_inf)
        {
            --temp;
            --days;
        }
    }
    return days;
}

Date& Date::operator+=(int days) 
{
    *this = *this + days;
    return *this;
}

Date& Date::operator-=(int days) 
{
    *this = *this - days;
    return *this;
}

bool Date::operator<(const Date& add_inf) const
{
    if (year < add_inf.year)
    {
        return true;
    }
    else if (year > add_inf.year) { return false; }

    if (month < add_inf.month)
    {
        return true;
    }
    else if (month > add_inf.month) { return false; }

    return day < add_inf.day;
}

bool Date::operator>(const Date& add_inf) const { return add_inf < *this; }

bool Date::operator<=(const Date& add_inf) const { return !(add_inf < *this); }

bool Date::operator>=(const Date& add_inf) const {  return !(*this < add_inf); }

bool Date::operator==(const Date& add_inf) const
{
    return year == add_inf.year && month == add_inf.month && day == add_inf.day;
}

bool Date::operator!=(const Date& add_inf) const { return !(*this == add_inf); }





