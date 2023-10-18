#include "Data.h"
#include <iostream>


int main() 
{
    int day, month, year;

    std::cout << "Enter day, month and year " << std::endl;
    std::cout << "Day: ";
    std::cin >> day;
    std::cout << "Month: ";
    std::cin >> month;
    std::cout << "Year: ";
    std::cin>> year;

    if (!is_valid_date(day, month)) 
    {
        std::cerr << "Invalid date!" << std::endl;
        return 1; // Возврат из программы с ошибкой
    }


    Date inf_orig(day, month, year);

    std::cout << "Orig: ";
    inf_orig.print();



    Date date_incr_dicr = inf_orig;
    date_incr_dicr++;
    std::cout << "Incr: ";
    date_incr_dicr.print();

    date_incr_dicr--;
    std::cout << "Dicr: ";
    date_incr_dicr.print();

    int days_add;
    std::cout << "Count days to add: ";
    std::cin >> days_add;
    date_incr_dicr += days_add;
    std::cout << "Data after add days: ";
    date_incr_dicr.print();

    int days_subtr;
    std::cout << "Count days to subtr: ";
    std::cin >> days_subtr;
    date_incr_dicr -= days_subtr;
    std::cout << "Data after subtr days: ";
    date_incr_dicr.print();

    std::cout << std::endl;
    Date date_add10 = inf_orig + 10;
    std::cout << "Data after add 10 days: ";
    date_add10.print();

    Date date_subtr5 = inf_orig - 5;
    std::cout << "Data after subtr 5 days: ";
    date_subtr5.print();

    std::cout << "Difference in days between the first and second date: " << (inf_orig - date_incr_dicr) << std::endl;

    /*
    * Проверка работы)
    std::cout << "Difference:" << std::endl;
    std::cout << (inf_orig < date_incr_dicr) << std::endl;
    std::cout << (inf_orig > date_incr_dicr) << std::endl;
    std::cout << (inf_orig <= date_incr_dicr) << std::endl;
    std::cout << (inf_orig >= date_incr_dicr) << std::endl;
    std::cout << (inf_orig == date_incr_dicr) << std::endl;
    std::cout << (inf_orig != date_incr_dicr) << std::endl;
    */

    return 0;
}
