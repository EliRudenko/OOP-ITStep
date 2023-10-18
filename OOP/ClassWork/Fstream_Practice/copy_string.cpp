#include <fstream>
#include <iostream>

using namespace std;


//ПОСТРОЧНО


int main()
{
    // Создание выходного файлового потока и связывание с ним файла, который открывается на запись в текстовом режиме.
    ofstream out;
    //СОЗДАНИЕ ФАЙЛА КУДА ЗАПИСЫВАТЬ
    out.open("NewReadMe.txt", ios::out | ios::trunc);

    // Создание выходного файлового потока и связывание с ним файла, который открывается на чтение в текстовом режиме 
    // (файл должен существовать).
    ifstream in;
    //ОТКУДА
    in.open("ReadMe.txt", ios::in);

    // Если файл удалось открыть.
    if (in)
    {
        const int size = 300; 

        do
        {
            char buffer[size] = {};

            in.getline(buffer, size); // ВОЗВРАТ ПОЛНОЙ СТРОКИ

            cout << buffer << endl;

            out << buffer << endl; //ЗАПИСЬ В ФАЙЛ
        }
        // Цикл продолжается до тех пор, пока не наступит конец файла.
        while (in);

        // Закрытие файловых потоков.
        out.close();
        in.close();
    }
    else
    {
        cout << "Could not open the file" << endl;
    }

    return 0;
}