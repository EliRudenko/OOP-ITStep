int grade1 = 4;
int grade2 = 5;
int grade3 = 3;
int grade4 = 5;
int grade5 = 4;

 


int numbers[5] = {10, 20, 30, 40, 50};



#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};

    // Выведем элементы массива
    cout << "Первый элемент: " << numbers[0] << endl;
    cout << "Второй элемент: " << numbers[1] << endl;
    cout << "Третий элемент: " << numbers[2] << endl;

    return 0;
}




#include <iostream>
using namespace std;

int main() 
{
    int numbers[5];

    for (int i = 0; i < 5; i++) 
    {
        cout << "Введите число для элемента " << i << ": ";
        cin >> numbers[i];
    }

    cout << "Ваш массив: ";
    for (int i = 0; i < 5; i++) 
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}



#include <iostream>
using namespace std;

int main()
{

    int matrix[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };


    cout << "Элементы массива matrix:" << endl;
    for (int i = 0; i < 3; i++) 
    {        
        for (int j = 0; j < 3; j++) 
        {    
            cout << matrix[i][j] << " ";  
        }
        cout << endl;                    
    }

    return 0;
}








#include <iostream>
#include <string>
using namespace std;

class Car 
{
private:
    string brand;
    string model;
    int year;
    double mileage;

public:

    Car() : brand("Unknown"), model("Unknown"), year(0), mileage(0.0) 
    {
        cout << "Конструктор по умолчанию вызван.\n";
    }

    Car(string b, string m, int y, double mil) : brand(b), model(m), year(y), mileage(mil) 
    {
        cout << "Параметризованный конструктор вызван.\n";
    }

    ~Car() 
    {
        cout << "Деструктор вызван для машины " << brand << " " << model << ".\n";
    }


    void displayInfo() const 
    {
        cout << "Марка: " << brand << ", Модель: " << model
             << ", Год: " << year << ", Пробег: " << mileage << " км\n";
    }


    void drive(double distance)
    {
        if (distance > 0) 
        {
            mileage += distance;
            cout << "Машина проехала " << distance << " км.\n";
        } 
        else 
        {
            cout << "Дистанция должна быть положительной!\n";
        }
    }
};

int main() 
{

    Car car1;
    car1.displayInfo();

    Car car2("Toyota", "Camry", 2022, 15000);
    car2.displayInfo();

    Car car3 = car2;
    car3.displayInfo();

    car2.drive(120);
    car2.displayInfo();

    return 0;
}
