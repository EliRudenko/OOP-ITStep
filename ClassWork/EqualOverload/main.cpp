#include <cstdlib>
#include <ctime>

#include "Foo.h"

int main()
{
    srand((unsigned int)time(nullptr));

    Foo obj1(10);
    obj1.Initialize();
    obj1.Show();

    Foo obj2(20);
    obj2.Initialize();
    obj2.Show();

    Foo obj3 = obj1;
    obj3.Show();

    obj3 = obj2; // obj3.operator=(obj2);
    obj3.Show();

    return 0;
}