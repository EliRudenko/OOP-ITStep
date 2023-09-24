#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

#include "var.cpp"

int main() 
{
    /*
    //БЫСТРАЯ ПРОВЕРКА
    var<int> a = 15;
    var<String<char>> b = "Hello";
    var<double> c = 7.8;
    var<String<char>> d = "50";

    b = a + d;
    b.Show(); // Выведет 65

    if (a == b) std::cout << "Equal\n";
    else std::cout << "Not Equal\n";
    */

    std::cout << "Enter an integer: ";
    int a;
    std::cin >> a;

    std::cout << "Enter a double: ";
    double b;
    std::cin >> b;

    std::cout << "Enter a string: ";
    char str[50];
    std::cin >> str;

    var<int> test1(a);
    var<double> test2(b);
    var<char> test3(str);
    
    /*
    //ГЛУБОКАЯ ПРОВЕРКА, ПОЛЬЗОВАТЕЛЬ
    var<int> result1 = test1 + test2;
    var<double> result2 = test1 + test2;
    var<char> result3 = test3 * test3;
    result1.Show();
    std::cout << std::endl;
    result2.Show();
    std::cout << std::endl;
    result3.Show();
    std::cout << std::endl;
    */

    return 0;
}
