#pragma once


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

#include "Test_Interface.h"

class File_actions 
{

private:

    std::ofstream out; // ПОТОК записи в файл
    TestInterface* testInt; // доступ к тестам

public:

    File_actions(TestInterface* iTests); // указатель на TestInterface

    void outCats(int catC, int subCatC);
};
