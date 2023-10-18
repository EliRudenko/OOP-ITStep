#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#include "MSem.cpp"

void ByVal(MyArray obj){}

MyArray ReturnVal(MyArray arr)
{
    //MyArray arr(5);
    return arr;
}

int maib()
{
    MyArray a(3);
    //MyArray b = a; // 1
    ByVal (a);
    MyArray rez = ReturnVal(a);
}


