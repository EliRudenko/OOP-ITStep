#include "Value_calculator.h"
#include "Size_exception.h"
#include "Data_exception.h"


int Value_calculator::doCalc(std::string array[4][4]) 
{
    int sum = 0; // сохроняемя сумму

    for (int i = 0; i < 4; ++i)  //строки
    {
        for (int j = 0; j < 4; ++j)  // столбцы
        {
            try 
            {
                int value = 0; // сохроняем числа
                for (char a : array[i][j]) //перебор ВСЕГО массива, каждый символ!
                {
                    if (a >= '0' && a <= '9') 
                    {
                        value = value * 10 + (a - '0'); // ПРЕОБРАЗОВАНИЕ В ЧИСЛО (можно было бы stoi)
                    } 
                    else 
                    {
                        //ИСКЛЮЧЕНИЕ
                        std::string error_m = "Invalid data at cell ("; // или можно было бы так : ("Invalid data at cell (" + std::string(1, c) + ")");  :)
                        error_m += a;
                        error_m += ")";
                        throw Data_exception(error_m);
                    }
                }
                sum += value;

            } 
            
            catch (...)  //УНИВЕРСАЛЬНЫЙ
            {
                std::string error_m = "Invalid data at cell ("; // тоже самое, можно было бы написать кароче как выше в коменте
                error_m += array[i][j];
                error_m += ")";
                throw Data_exception(error_m);
            }
        }
    }

    return sum; // СУММА чисел
}

