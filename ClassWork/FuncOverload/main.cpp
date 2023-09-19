#include "point.h"
//#include <ctime>
#include <iostream>

int main()
{
    //srand(unsigned(time(0)));

    Point obj1;
    obj1.Output();

    Point obj2(10, 20);
    obj2.Output();

    Point result = obj1 + 5;
    result.Output();
    std::cout << std::endl;

    Point obj3 = ++obj2;
    obj3.Output();
    std::cout << std::endl;

    obj3 = obj2++;
    obj3.Output();
    std::cout << std::endl;

    return 0;
}
