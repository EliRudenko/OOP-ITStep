#include<iostream>

#include "File_connection_library.h"
#include "File_actions.cpp"

int main() 
{
    UserInterface userInterface;
    TestInterface testInterface;

    userInterface.for_main(); 

/*
    File_actions testOut(&testInterface);
    
    int categoryChoice = testInterface.getUserChoice(0, testInterface.getCats().size());
    int subcategoryChoice = testInterface.getUserChoice(0, testInterface.getSubCats()[categoryChoice - 1].size());
    testOut.outCats(categoryChoice - 1, subcategoryChoice - 1);
*/

    return 0;
}

 