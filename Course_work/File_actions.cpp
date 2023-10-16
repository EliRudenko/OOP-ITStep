#include "File_actions.h"

/*
File_actions::File_actions(TestInterface* iTests) { testInt = iTests; }

void File_actions::outCats(int catC, int subCatC)
{
    out.open("Test.txt", std::ios::out);

    out << "Categories :" << std::endl;

    for (int i = 0; i < testInt->getCats().size(); i ++) { out << testInt->getCats()[i] << "    "; }

    out << std::endl;

    out << "Sub Categories :" << std::endl;

    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < testInt->getSubCats().size(); j++) {  out << testInt->getSubCats()[i][j] << "    "; }
    }

    out << "Questions :" << std::endl;

    testInt->loadTests();

    for (const Question& question : testInt->getTest()[catC][subCatC]) {  out << question.text << std::endl; }

    out.close();
}
*/