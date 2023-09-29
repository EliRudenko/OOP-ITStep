#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#include <fstream>
#include <iostream>

using namespace std;



//БАЗА


int main()
{
    cout << "1. Write" << endl;
    cout << "2. Read" << endl;

    int choice = 0;
    cin >> choice;

    switch (choice)
    {
        case 1:
            {
                // Создание выходного файлового потока и связывание с ним файла, который открывается на запись в 
                // текстовом режиме.
                ofstream out("Text.txt");

                // Если файл удалось открыть.
                if (out.is_open())
                {
                    // Сохранение данных в файл.
                    out << 10 << ' ' << 123.5;
                    out << "This is text file";

                    // Закрытие файлового потока.
                    out.close();
                }
                else { std::cout << "Could not open the file" << endl; }
            }
            break;
        case 2:
            {
                int integerValue = 0;
                double doubleValue = 0.0;
                char string[10] = {};

                // Создание выходного файлового потока и связывание с ним файла, который открывается на чтение в 
                // текстовом режиме.
                ifstream in("Text.txt");

                // Если файл удалось открыть.
                if (in.is_open())
                {
                    // Считывание данных из файла в переменные.
                    in >> integerValue >> doubleValue;

                    std::cout << integerValue << endl;
                    std::cout << doubleValue << endl;

                    // Цикл продолжается до тех пор, пока не наступит конец файла.
                    while (!in.eof())
                    {
                        // Считывание строки из файла по одному слову за одну итерацию цикла.
                        in >> string;
                        std::cout << string << ' ';
                    }

                    // Закрытие файлового потока.
                    in.close();
                }
                else { std::cout << "Could not open the file" << endl; }
            }
            break;
        default:
            cout << "Invalid action" << endl;
            break;
    }

    return 0;
}