#pragma once

bool is_valid_date(int day, int month);

class Date 
{
private:
    int day;
    int month;
    int year;

public:

    Date(); // ����� �� ���������
    Date(int d, int m, int y); 

    void set_day(int d);
    void set_month(int m);
    void set_year(int y);

    //bool is_valid_date(int day, int month);

    int get_day() const;
    int get_month() const;
    int get_year() const;

    void print() const;

    // ���������� ����������
    Date& operator++(); // ++����
    Date& operator--(); // --����
    Date operator++(int); // ����++
    Date operator--(int); // ����--


    Date operator+(int days) const; // ���� + ��� �� ����
    Date operator-(int days) const; // ���� - ���������� ����


    int operator-(const Date& add_inf) const; // ������� ����

    Date& operator+=(int days); // ���� += ���������� ����
    Date& operator-=(int days); // ���� -= ���������� ����

    bool operator<(const Date& add_inf) const;
    bool operator>(const Date& add_inf) const;
    bool operator<=(const Date& add_inf) const;
    bool operator>=(const Date& add_inf) const;
    bool operator==(const Date& add_inf) const;
    bool operator!=(const Date& add_inf) const;


};


