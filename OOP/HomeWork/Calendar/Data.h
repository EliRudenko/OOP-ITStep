#pragma once

bool is_valid_date(int day, int month);

class Date 
{
private:
    int day;
    int month;
    int year;

public:

    Date(); // Конст по умолчанию
    Date(int d, int m, int y); 

    void set_day(int d);
    void set_month(int m);
    void set_year(int y);

    //bool is_valid_date(int day, int month);

    int get_day() const;
    int get_month() const;
    int get_year() const;

    void print() const;

    // Перегрузка операторов
    Date& operator++(); // ++дата
    Date& operator--(); // --дата
    Date operator++(int); // дата++
    Date operator--(int); // дата--


    Date operator+(int days) const; // дата + кол во дней
    Date operator-(int days) const; // дата - количество дней


    int operator-(const Date& add_inf) const; // разница дней

    Date& operator+=(int days); // дата += количество дней
    Date& operator-=(int days); // дата -= количество дней

    bool operator<(const Date& add_inf) const;
    bool operator>(const Date& add_inf) const;
    bool operator<=(const Date& add_inf) const;
    bool operator>=(const Date& add_inf) const;
    bool operator==(const Date& add_inf) const;
    bool operator!=(const Date& add_inf) const;


};


