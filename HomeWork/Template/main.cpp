#include "templ.h"
#include <iostream>

class A {
private:
    int value;
public:
    A(int value) : value(value) {}

    int getValue() const { return value; }

    A operator+(const A& add) const { return A(value + add.value); }

    A operator-(const A& add) const { return A(value - add.value); }

    A operator*(const A& add) const { return A(value * add.value); }

    A operator/(const A& add) const { return A(value / add.value); }
};

int main() 
{ 
// Just to test all methods and template
//Size, etc. is added manually

    Matrix<int> matrix_1(2, 2);
    matrix_1.Im_Keyboard();
    matrix_1.Print();
    std::cout << std::endl;

    Matrix<int> matrix_2(3, 3);
    matrix_2.Im_Random();
    matrix_2.Print();
    std::cout << std::endl;

    Matrix<int> result = matrix_1 + matrix_2;
    result.Print();
    std::cout << std::endl;

    int maxElement = result.findMax();
    int minElement = result.findMin();

    /*
    A a1(5);
    A a2(3);
    A a3 = a1 + a2;
    */

    return 0;
}
