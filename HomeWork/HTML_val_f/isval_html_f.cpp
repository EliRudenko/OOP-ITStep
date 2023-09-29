#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#include <fstream>
#include <iostream>

using namespace std;

bool valid_HTML(const char* path);

int main() 
{
    const char* path = "index.html";

    if (valid_HTML(path)) 
    {
        std::cout << "The file is valid" << std::endl;
    } 
    else { std::cout << "The file is not valid.." << std::endl; }

    return 0;
}


bool valid_HTML(const char* path) 
{
    std::ifstream in_f(path); //открытие для ЧТЕНИЯ

    if (!in_f.is_open()) //ПРОВЕРКА
    {
        std::cout << "Error opening file!" << std::endl;
        return false;
    }

    int open_tag_count = 0; // <
    int close_tag_count = 0; // >
    char brackets; //симфол с файла, которые должны быть < >, для проверки
    bool both_brackets = false; // для проверки что кажной < есть пара >

    while (in_f.get(brackets)) //ПОСИМФОЛЬНО
    {
        if (brackets == '<') 
        {
            both_brackets = true; // (изначально) НАЧАЛО ТЕГА, то есть <...
            open_tag_count++; // счетчик, ибо нашли нужную скобку для проверки
        } 
        else if (brackets == '>') 
        { 
            if (both_brackets) //если до этого была найдена <
            {
                close_tag_count++; // счетчик 
                both_brackets = false; // обнуляем, что бы опять при нахождении < поставить на true, для проверки нахождения
            }
        }
    }

    in_f.close();
    return open_tag_count == close_tag_count; // колв во должно быть равно
}

