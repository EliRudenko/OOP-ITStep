#include <iostream>

#include "Foo.h"

using namespace std;

int main()
{
    Foo obj1(10, 'a');
    Foo obj2(20, '!');

    cout << obj1;
    cout << obj2 << obj1;

    cin >> obj1;
    cout << obj1;

    return 0;
}