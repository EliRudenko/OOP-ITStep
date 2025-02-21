

//ПЕРЕМЕННЫЕ, типы, константы, вывод, ввод 
/*
int main() 
{
    string acc = "";
    acc = acc + "Hello, ";
    acc = acc + "World!";
    std::cout << acc;


    int age(18);
    int age = 18;
    int age;
    age = 18


    int width { 5 }; 
    int height = { 6 };

}




int main() 
{
    // 1. Переменные 
    int age = 25;              
    double height = 1.75;      
    char grade = 'A';          
    bool isStudent = true;     
    string name = "Алекс";     

    // 2. Константа 
    const double PI = 3.14159; 

    // 3. Вывод значений переменных
    std::cout << "Имя: " << name << std::endl;
    std::cout << "Возраст: " << age << " лет" << std::endl;
    std::cout << "Рост: " << height << " м" << std::endl;
    std::cout << "Оценка: " << grade << std::endl;
    std::cout << "Студент? " << (isStudent ? "Да" : "Нет") << std::endl;
    std::cout << "Число Пи: " << PI << std::endl;

    return 0;
}
*/








//---------------------------------------





//ФУНКЦИИ


/*
//ВЫЗОВ
void sayHello() 
{
    cout << "Привет, мир!" << endl;
}

int main() 
{
    sayHello(); // Вызов функции
    return 0;
}
*/



/*
//ПАРАМЕТРЫ
void sum(int a, int b) 
{ 
    cout << "Сумма: " << (a + b) << endl;
}

int main() 
{
    sum(5, 10); 
    sum(7, 3);  
    return 0;
}
*/





//ВОЗВРАТ
/*
int sum(int a, int b) 
{ 
    return a + b; 
}

int main() 
{
    int result = sum(5, 3); 
    cout << "Результат: " << result << endl; 

    return 0;
}
*/



/*
//ДАННЫЕ ОТ ПОЛЬЗОВАТЕЛЯ
int sum(int a, int b) 
{ 
    if( b != 0)
    {
        return a / b;
    }
    
}


int main() 
{
    int x, y;
    cout << "Введите два числа: ";
    cin >> x >> y;

    cout << sum(x, y) 
    
    return 0;
}
*/



//задание: два числа от пользователя, проверить одно из них на 0 и поделить
// вернуть результат!



/*
//прототип
int sum(int a, int b);


int main() 
{
    int x, y;
    cout << "Введите два числа: ";
    cin >> x >> y;

    cout << "Сумма: " << sum(x, y) << endl;
    cout << "Сумма: " << sum(x, y) << endl;
    cout << "Сумма: " << sum(x, y) << endl;
    cout << "Сумма: " << sum(x, y) << endl;
    cout << "Сумма: " << sum(x, y) << endl;
    return 0;
}

int sum(int a, int b) 
{ 
    return a + b;
}
*/



//----------------------------------------------------
//условия

//тернарный оператор


/*
int main()
{
    int a = 10, b =20;

    if(a > b)
    {
        std::cout << a << std::endl;
    }
    else
    {
        std::cout << b << std::endl;
    }


    std::cout << ((a > b) ? a : b) << std::endl;




    int max;

    if(a > b)
    {
       max = a;
    }
    else
    {
        max = b;
    }

    max = (a > b) ? a : b;

    std::cout << max << std::endl;

}
*/





//---------------------------------------

//сравнения, И(&&) ИЛИ(||)


/*
int main()
{
    int a = 8, b = 0;


    if(b != 0)
    {
        if(a == 10 || (a < 10 && a > 7))
        {
            cout << "a / b = " << a / b << endl;
        }
        else
        {
            cout << "a * b = " << a * b << endl;
        }
    }
    else
    {
        b++;
        cout << "b = " << b << endl;

        if(a == 10 || (a < 10 && a > 7))
        {
            cout << "a / b = " << a / b << endl;
        }
        else
        {
            cout << "a * b = " << a * b << endl;
        }

    }
  
}
*/






//---------------------------------------
//цыклы


//while 
/*
int main()
{
    int a = 1;

    while (a <= 4)
    {
        cout << a << endl;
        a++;
    }

}  
*/



/*
int main()
{
    int a = 1, b;


    while (a <= 4)
    {
        b = 0;

        while (b <= 10)
        {
            cout << a << " * " << b << " = " << (a * b) << endl;
            b++;
        }
        a++;
        cout << endl; 
    }

}
*/


//задание: таблце на 5, 6, 8, 9




/*
int main() 
{
    int a = 5, b;  

    while (a <= 9) 
    {
        if (a == 7) {  a++; }

        b = 0;
        while (b <= 10) 
        {
            cout << a << " * " << b << " = " << (a * b) << endl;
            b++;
        }
        a++;
        cout << endl;  
    }

}
*/


// do while
/*
int main() 
{
    int i = 1;
    
    do 
    {
        cout << "Число: " << i << endl;
        i++; 

    } while (i <= 5);  

}
*/



//for

/*
int main() 
{
    for (int i = 1; i <= 5; i++) 
    { 
        cout << "Число: " << i << endl;

    }

}
*/


//четные
/*
int main() 
{
    for (int i = 2; i <= 10; i += 2) 
    { 
        cout << "Четное число: " << i << endl;
    }

}
*/
//задание: нечетные


//обратно
/*
int main() 
{
    for (int i = 10; i >= 1; i--) 
    {  
        cout << "Обратный отсчет: " << i << endl;
    }

}
*/


/*
int main() 
{
    int number = 8;  

    for (int i = 1; i <= 10; i++) 
    {
        cout << number << " * " << i << " = " << (number * i) << endl;
    }


}
*/


//задание: Вывод простых чисел в диапазоне 1–30







//---------------------------------------



/*
int main() 
{
    cout << "Простые числа от 1 до 50: ";

    for (int num = 3; num <= 50; num++) 
    {
        int count = 0;

        for (int i = 2; i * i <= num; i++) 
        { 
            if (num % i == 0) 
            {
                count++;    
            }
        }

        if (count == 0 ) { cout << num << " ";  }
    }

    cout << endl;
    return 0;
}
*/






/*
int main() 
{
    cout << "Простые числа от 1 до 50: ";

    for (int num = 2; num <= 50; num++) 
    {
        bool isPrime = true; // Флаг простого числа

        for (int i = 2; i * i <= num; i++) 
        {
            if (num % i == 0) {
                isPrime = false;
                break;  // Выходим, если нашли делитель
            }
        }

        if (isPrime) cout << num << " ";
    }

    cout << endl;
    return 0;
}
*/

