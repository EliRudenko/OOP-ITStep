#include "File_actions.h"


File_actions::File_actions(TestInterface* iTests) { testInt = iTests; } // указатель на обьект TestInterface

void File_actions::outCats(int catC, int subCatC)
{
    out.open("Test.txt", std::ios::out); // открытие файла

    out << "Categories :" << std::endl;

    for (int i = 0; i < testInt->getCats().size(); i ++) { out << testInt->getCats()[i] << "    "; } // запись имен категории

    out << std::endl;

    out << "Sub Categories :" << std::endl;

    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < testInt->getSubCats().size(); j++) {  out << testInt->getSubCats()[i][j] << "    "; } // заголовки
    }
/*
    out << "Questions :" << std::endl;

    testInt->loadTests();

    for (const Question& question : testInt->getTest()[catC][subCatC]) {  out << question.text << std::endl; } // вопр
*/
    out.close();
}
