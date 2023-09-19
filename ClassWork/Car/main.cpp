#include<iostream>
#include "Car.h"

using namespace std;

int main()
{
    Car* car_product[10]; 
    int num_car = 0;
    int choice = 0;
    int choice_oly = 0;


    while (choice != 6)
    {

        cout << "Select menu item:" << endl;
        cout << "1. Add product" << endl;
        cout << "2. Show all products" << endl;
        cout << "3. Display of a specific product" << endl;
        cout << "4. Display specific information" << endl;
        cout << "5. Exit" << endl;

        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            do
            {
                car_product[num_car] = new Car();
                cout << "Enter car details:" << endl;
                car_product[num_car]->Input();

                int choice_add;
                cout << "Want to add another car? (1 - yes / 0 - no): ";
                cin >> choice_add;
                cout << endl;
                num_car++;

                if (choice_add == 0 || num_car >= 10)
                {
                    break;
                }

            } while (true);
            break;

        case 2:
            if (num_car == 0)
            {
                cout << "The list is empty!" << endl;
            }
            else
            {
                cout << "List of all cars:" << endl;
                for (int i = 0; i < num_car; i++)
                {
                    car_product[i]->Print();
                }
            }
            break;

        case 3:
            int car_index;
            cout << "Enter the index of the car you want to display: ";
            cin >> car_index;
            car_index--;
            if (car_index >= 0 && car_index < num_car)
            {
                car_product[car_index]->Print();
            }
            else
            {
                cout << "Invalid index!" << endl;
            }
            break;

        case 4:

            cout << "   1. Display only models" << endl;
            cout << "   2. Display only colors" << endl;
            cout << "   3. Display only prices" << endl;
            cout << "   4. Display only years" << endl;
            cout << "   5. Exit" << endl;

            do
            {
                cout << "Your choice: ";
                cin >> choice_oly;

                switch (choice_oly)
                {
                case 1:
                    cout << "List of car models:" << endl;
                    for (int i = 0; i < num_car; i++)
                    {
                        cout << i + 1 << ". " << car_product[i]->GetModel() << endl;
                    }
                    break;

                case 2:
                    cout << "List of car colors:" << endl;
                    for (int i = 0; i < num_car; i++)
                    {
                        cout << i + 1 << ". " << car_product[i]->GetColor() << endl;
                    }
                    break;

                case 3:
                    cout << "List of car prices:" << endl;
                    for (int i = 0; i < num_car; i++)
                    {
                        cout << i + 1 << ". " << car_product[i]->GetPrice() << endl;
                    }
                    break;

                case 4:
                    cout << "List of car years:" << endl;
                    for (int i = 0; i < num_car; i++)
                    {
                        cout << i + 1 << ". " << car_product[i]->GetYear() << endl;
                    }
                    break;
                case 5:
                    cout << endl;
                    break;

                default:
                    cout << "Invalid choice!" << endl;
                    break;
                }

            } while (choice_oly != 5);
            break;
        case 5:
            return 0;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
    for (int i = 0; i < num_car; i++) { delete car_product[i]; }

    return 0;
}
