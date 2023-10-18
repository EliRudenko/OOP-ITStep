

#include "d:\IT-STEP\IT-Step-Repo\Framework.h"

#include "Figure.cpp"
#include "Circle.cpp"
#include "Rectangle.cpp"
#include "Triangle.cpp"

//ТЕМА
//ПРОБЛЕМА
//ЗАРАНЕЕ НЕ ЗНАЕМ С КАКИМ ПОТОМКОМ НАДО РАБОТАТЬ


int main()
{
//РАБОТА С ПОТОМКАМИ
/*
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;


//СТРОГИЕ ТИПЫ (circle , rectangle , triangle) 

    circle.SetDimension(10.0);
    circle.ShowArea();
    
    rectangle.SetDimension(5.5, 10.0);
    rectangle.ShowArea();

    triangle.SetDimension(5.5, 10.0);
    triangle.ShowArea();
*/


  
/*
    Figure* ptr = new Circle(); 
    ptr->SetDimension(9);

    ptr->ShowArea(); //проблема, из за раннего связования
*/


//РЕШЕНИЕ
 
    Figure* ptr = nullptr;  

    std::cout << "1. C" << std::endl;
    std::cout << "2. R" << std::endl;
    std::cout << "3. T" << std::endl;
    int v = 0;
    std::cin >> v;

    switch (v)
    {
    case 1:
        ptr = new Circle();
        ptr->SetDimension(12,3);
        break;
    case 2:
        ptr = new Circle();
        ptr->SetDimension(12,3);
        break;
    case 3:
        ptr = new Circle();    
        ptr->SetDimension(12,3);
        break;
    
    default:
        std::cout << "Error!" << std::endl;
        break;
    }


    ptr->ShowArea(); //проблема, из за раннего связования

    delete ptr;

    return 0;
}



/*
using namespace std;

int main()
{
    Figure* figure = nullptr;

    int choice = 0;

    cout << "1. Square circle" << endl;
    cout << "2. Square rectangle" << endl;
    cout << "3. Square triangle" << endl;
    cout << "Make your choice: ";

    cin >> choice;

    switch (choice)
    {
        case 1:
            figure = new Circle;
            figure->SetDimension(10.0);
            break;
        case 2:
            figure = new Rectangle;
            figure->SetDimension(5.5, 10.0);
            break;
        case 3: 
            figure = new Triangle;
            figure->SetDimension(5.5, 10.0);
            break;
    }

    figure->ShowArea();

    return 0;
}
*/