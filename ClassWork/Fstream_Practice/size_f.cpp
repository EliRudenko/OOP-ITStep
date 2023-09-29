#include <fstream>
#include <iostream>

using namespace std;


//РАЗМЕР ФАЙЛА


int main()
{
    ifstream in("Portal 2.jpg", ios::binary | ios::in);

    if (in)
    {
        in.seekg(0, ios::end); //С СМЕЩАЕМ УКАЗАТЕЛЬ В КОНЕЦ

        cout << "Size of file: " << in.tellg() << " bytes" << endl; //СЧИТАЕТ СКОЛЬКО БАЙТ

        in.close();
    }
    else
    {
        cout << "Could not open the file" << endl;
    }

    return 0;
}