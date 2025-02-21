#include <iostream> 
using namespace std; 
#include <string>

/*
int main() 
{

    int numbers[5] = {1, 2, 3, 4, 5}; 
    cout << "First element: " << numbers[0] << endl;
    cout << "Second element: " << numbers[1] << endl;
    cout << "Third element: " << numbers[2] << endl;
    cout << "Fourth element: " << numbers[3] << endl;
    return 0;
}
*/




//цикл for для массива
/*
int main() 
{
    int numbers[5] = {10, 20, 30, 40, 50};

    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) 
    {
        cout << numbers[0] << " ";
    }

    return 0;
}
*/



//нахождение максимального элемента
/*
int main() 
{
    int numbers[5] = {7, 42, 15, 99, 23};
    int max = numbers[0];  // Начнем с первого элемента

    for (int i = 1; i < 5; i++) 
    {
        if (numbers[i] > max) 
        {
            max = numbers[i];  // Обновляем максимум
        }
    }

    cout << "Maximum number: " << max << endl;
    return 0;
}
*/


//Фиксированные массивы


/*
int main() 
{
    const int SIZE = 5;
    int arr[SIZE] = {1, 2, 3, 4, 5};

    cout << "Third element: " << arr[2] << endl;  
    return 0;
}
*/


//инициализация массива нулями
/*
int main() 
{
    const int SIZE = 10;
    int numbers[SIZE] = {};  // Все элементы = 0

    for (int i = 0; i < SIZE; i++) {
        cout << numbers[i] << " ";  // Выведет 0 0 0 0 0 0 0 0 0 0
    }

    return 0;
}
*/



/*
//нахождение среднего значения массива
int main() 
{
    const int SIZE = 5;
    int numbers[SIZE] = {10, 20, 30, 40, 50};

    int sum = 0;
    for (int i = 0; i < SIZE; i++) 
    {
        sum += numbers[i];  // Суммируем все элементы
    }

    double average = (double)sum / SIZE;  // Находим среднее значение
    cout << "Average value: " << average << endl;

    return 0;
}
*/



//заполнение массива пользователем
/*
int main() 
{
    const int SIZE = 5;
    int numbers[SIZE];

    cout << "Enter 5 numbers: ";
    
    for (int i = 0; i < SIZE; i++) 
    {
        cin >> numbers[i]; 
    }

    cout << "You entered: ";
    for (int i = 0; i < SIZE; i++) 
    {
        cout << numbers[i] << " "; 
    }

    return 0;
}
*/




//нахождение минимального и максимального значений
/*
int main() 
{
    const int SIZE = 5;
    int numbers[SIZE];

    cout << "Enter 5 numbers: ";
    for (int i = 0; i < SIZE; i++) 
    {
        cin >> numbers[i];
    }

    int min = numbers[0], max = numbers[0];

    for (int i = 1; i < SIZE; i++) 
    {
        if (numbers[i] < min) min = numbers[i];
        if (numbers[i] > max) max = numbers[i];
    }

    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;

    return 0;
}
*/






//Сортировка массивов методом выбора



//обмен двух чисел
/*
int main() 
{
    int a = 10, b = 20;

    cout << "Before swap: a = " << a << ", b = " << b << endl;
    
    int temp = a;
    a = b;
    b = temp;

    cout << "After swap: a = " << a << ", b = " << b << endl;

    return 0;
}
*/




//реализация сортировки выбором
/*
int main() 
{
    const int SIZE = 5;
    int numbers[SIZE] = {30, 10, 50, 20, 40};

    cout << "Original array: ";
    for (int i = 0; i < SIZE; i++) 
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Сортировка выбором
    for (int i = 0; i < SIZE - 1; i++) 
    {
        int minIndex = i;

        for (int j = i + 1; j < SIZE; j++) 
        {
            if (numbers[j] < numbers[minIndex]) 
            {
                minIndex = j;  // Нашли новый минимум
            }
        }

        // Меняем местами numbers[i] и numbers[minIndex]
        int temp = numbers[i];
        numbers[i] = numbers[minIndex];
        numbers[minIndex] = temp;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < SIZE; i++) 
    {
        cout << numbers[i] << " ";
    }

    return 0;
}
*/



/*
void selectionSort(int arr[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);  // Меняем местами элементы
    }
}

int main() 
{
    int arr[5] = {64, 25, 12, 22, 11};
    int size = 5;

    selectionSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }

    return 0;
}
*/




//сортировка в обратном порядке
/*
int main() 
{
    const int SIZE = 5;
    int numbers[SIZE] = {50, 40, 30, 20, 10};

    // Сортировка выбором (по убыванию)
    for (int i = 0; i < SIZE - 1; i++) 
    {
        int maxIndex = i;

        for (int j = i + 1; j < SIZE; j++) 
        {
            if (numbers[j] > numbers[maxIndex]) 
            {  // Меняем знак < на >
                maxIndex = j;  
            }
        }

        // Обмен значений
        int temp = numbers[i];
        numbers[i] = numbers[maxIndex];
        numbers[maxIndex] = temp;
        
    }

    cout << "Sorted array in descending order: ";
    for (int i = 0; i < SIZE; i++) 
    {
        cout << numbers[i] << " ";
    }

    return 0;
}
*/

//---------------------------------------




//МАССИВ В ФУНКЦИЮ
/*
int sumArray(int arr[], int size) 
{ 
    int sum = 0;
    for (int i = 0; i < size; i++) 
    {
        sum += arr[i];
    }
    return sum;
}

int main() 
{
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]); 

    cout << "Array elements sum: " << sumArray(numbers, size) << endl;
    return 0;
}
*/




/*
//ПО УМОЛЧАНИЮ
void greet(string name = "Guest") 
{ 
    cout << "Hello, " << name << "!" << endl;
}

int main() 
{
    greet("Alex"); 
    greet();        
    return 0;
}
*/













/*

int findMax(int arr[], int size) 
{
    int max = arr[0]; 
    for (int i = 1; i < size; i++) 
    {
        if (arr[i] > max) 
            max = arr[i];
    }
    return max;
}

int main() 
{
    int numbers[] = {3, 7, 2, 10, 6}; 
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Maximum element: " << findMax(numbers, size) << endl;

    return 0;
}






//двумерные
int main() 
{
    int matrix[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matrix elements output:" << endl;

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
*/


//---------------------------------------


/*
Задания на массивы:
1 Создайте массив из 10 чисел и найдите сумму всех элементов.
2 Отсортируйте массив из 7 элементов с помощью метода выбора.
3 Создайте двумерный массив (3x3) и выведите сумму всех его элементов.
*/




/*
4
Реализуйте поиск минимального и максимального элемента в массиве 
без использования sort()
*/



/*
5
Реализуйте программу, которая находит второй по величине элемент массива
*/


/*
6
Объявите двумерный массив 3x3 и заполните его числами от 1 до 9.
*/





//1
/*
int main() 
{
    int arr[10] = {3, 5, 7, 2, 8, 10, 1, 4, 6, 9};
    int sum = 0;

    for (int i = 0; i < 10; i++) 
    {
        sum += arr[i];
    }

    std::cout << "Сумма элементов массива: " << sum << std::endl;
    return 0;
}
*/



//2
/*
int main() 
{
    int arr[7] = {29, 10, 14, 37, 13, 2, 45};

    for (int i = 0; i < 6; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < 7; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < 7; i++) 
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}
*/




//3
/*
int main() 
{
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int sum = 0;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            sum += arr[i][j];
        }
    }

    std::cout << "Сумма всех элементов: " << sum << std::endl;
    return 0;
}
*/



//4
/*
int main() 
{
    int arr[10] = {3, 5, 7, 2, 8, 10, 1, 4, 6, 9};

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < 10; i++) 
    {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    std::cout << "Минимальный элемент: " << min << std::endl;
    std::cout << "Максимальный элемент: " << max << std::endl;
    return 0;
}
*/




//5
/*
int main() 
{
    int arr[10] = {3, 5, 7, 2, 8, 10, 1, 4, 6, 9};

    int max1 = arr[0], max2 = arr[0];

    for (int i = 1; i < 10; i++) 
    {
        if (arr[i] > max1) 
        {
            max2 = max1;
            max1 = arr[i];
        } 
        else if (arr[i] > max2 && arr[i] != max1) 
        {
            max2 = arr[i];
        }
    }

    std::cout << "Второй по величине элемент: " << max2 << std::endl;
    return 0;
}
*/




//6

/*
int main() 
{
    int arr[3][3];
    int value = 1;

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            arr[i][j] = value++;
        }
    }

    std::cout << "Двумерный массив 3x3:" << std::endl;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
*/






//---------------------------------------





//Строки C-style
/*
{'H', 'e', 'l', 'l', 'o', '\0'}

char str1[] = "Hello";  // Строка автоматически завершится '\0'
char str2[6] = "Hello"; // Размер 6, т.к. нужен '\0'
char str3[] = {'H', 'i', '\0'}; // Объявление вручную

char str4[3] = "Hi!"; //  Ошибка! Нет места для `\0`
*/


/*
int main() 
{
    char name[20];

    cout << "Введите имя: ";

    cin >> name;  // ПРОБЕЛЫ не считывает!!!
    cin.getline(name, 20); // решение пролемы 

    cout << "Привет, " << name << "!" << endl;
    return 0;
}
*/


//либо
/*
#include <string>

int main() 
{
    string name;

    cout << "Введите имя: ";
    getline(cin, name); // Считывает строку с пробелами

    cout << "Привет, " << name << "!" << endl;
    return 0;
}
*/




// Стандартные функции работы со строками (cstring)
/*
#include <cstring>


int main() 
{
    char str1[] = "Hello";
    char str2[] = "World";

    cout << "Длина строки str1: " << strlen(str1) << endl;
    strcat(str1, str2);  // str1 = "HelloWorld"
    cout << "Объединение строк: " << str1 << endl;

    strcpy(str1, "New"); // str1 = "New"
    cout << "Копирование строки: " << str1 << endl;

    cout << "Сравнение строк (Hello и World): " << strcmp("Hello", "World") << endl;

    return 0;
}
*/





//---------------------------------------


//подводка к тебе Указатели 

/*
void modifyValue(int x) 
{ // x - копия переменной
    x = 99; // Меняем копию, но не оригинал
}

int main() 
{
    int a = 10;
    modifyValue(a); 
    cout << "Значение a после вызова функции: " << a << endl; // 10
    // Проблема: a не изменился, потому что x была его копией.
    return 0;
}
*/


/*
void modifyValue(int* p) 
{ // p - указатель на переменную
    *p = 99; // Изменяем оригинальную переменную
}

int main() 
{
    int a = 10;
    modifyValue(&a); 
    cout << "Значение a после вызова функции: " << a << endl; // 99
    // Теперь переменная a изменилась, потому что передавалась не копия, а указатель на неё.
    return 0;
}
*/


// В C++ имя массива – это уже указатель на его первый элемент.

/*
почему указатели важны?
✔ Позволяют изменять данные внутри функций без копирования.
✔ Экономят память при передаче больших объектов.
✔ Позволяют работать с динамической памятью.
✔ Дают доступ к массивам, строкам и сложным структурам.
*/





//УКАЗАТЕЛИ
/*
int a = 10; // переменная, где-то в памяти хранится, ячейка памяти
int* p = &a;  // p хранит адрес переменной a

 // & (Амперсанд)  – получить адрес переменной.
 // * – разыменование (доступ к значению по адресу, получить значение).


cout << &a; // Выведет адрес переменной a  (такого вида: 0x7ffee8c3aabc)
*/



/*
int main() 
{
    int x = 42;
    int* ptr = &x; // Указатель хранит адрес x

    cout << "Адрес x: " << ptr << endl;
    cout << "Значение по указателю: " << *ptr << endl;

    *ptr = 99; // Изменяем x через указатель
    cout << "Новое значение x: " << x << endl;

    return 0;
}
*/

/*
ptr хранит адрес x.
*ptr разыменовывает указатель и дает доступ к значению x.
Меняя *ptr, мы меняем саму переменную x!
*/





//указатель nullptr
/*
int* p = nullptr; // Указатель не указывает ни на что
if (p == nullptr) 
{
    cout << "Указатель пуст!" << endl;
}


int* p = nullptr;
cout << *p; // Ошибка! Нельзя разыменовать `nullptr`
*/



//указатели и массивы
/*
int arr[3] = {10, 20, 30};
int* p = arr;  // p указывает на arr[0]

cout << *p;    // 10 (arr[0])
cout << *(p + 1); // 20 (arr[1])
cout << *(p + 2); // 30 (arr[2])
*/



/*
int main() 
{
    int arr[5] = {1, 2, 3, 4, 5};
    int* p = arr;  

    for (int i = 0; i < 5; i++) 
    {
        cout << "Элемент " << i << ": " << *(p + i) << endl;
    }

    return 0;
}
*/



// Адресная арифметика
/*
int main() 
{

    int arr[3] = {10, 20, 30};
    int* p = arr;

    cout << "Адрес первого элемента: " << p << endl;
    cout << "Адрес второго элемента: " << (p + 1) << endl;
    cout << "Адрес третьего элемента: " << (p + 2) << endl;

    return 0;
}
*/




//---------------------------------------


//Динамическая память

/*
Стек (stack) – область памяти для локальных переменных 
(быстро, но ограничено).

Куча (heap) – область памяти для динамических данных 
(гибко, но требует ручного управления).
*/

/*
void func() 
{
    int a = 10;  // Переменная создается в стеке (автоматически освобождается)
    int* p = new int(20); // Число 20 выделяется в куче (требует ручного удаления)
}
*/



//Оператор new, выделение памяти в куче

/*
int* ptr = new int;  // Выделяем место под один int в куче
*ptr = 42;           // Присваиваем значение
cout << *ptr;        // Выведет 42
*/




// Освобождение памяти – delete

/*
int* ptr = new int(10); // Выделяем память
cout << *ptr << endl; // Вывод: 10

delete ptr; // Освобождаем память
ptr = nullptr; // Безопасно обнуляем указатель
*/





//Выделение памяти для массивов – new[] и delete[]

/*
int* arr = new int[5]; 

for (int i = 0; i < 5; i++) 
{
    arr[i] = i * 10;
}

delete[] arr; 
arr = nullptr;
//Если забыть delete[], будет утечка памяти!
*/



//Динамическое выделение многомерных массивов

/*
int rows = 3, cols = 3;
int** matrix = new int*[rows]; // Выделяем массив указателей

for (int i = 0; i < rows; i++) 
{
    matrix[i] = new int[cols]; // Выделяем массив для каждой строки
}

// Освобождение памяти
for (int i = 0; i < rows; i++) 
{
    delete[] matrix[i]; // Удаляем строки
}
delete[] matrix; // Удаляем массив указателей
*/




//nullptr и безопасные указатели

// вместо NULL лучше использовать nullptr
//int* ptr = nullptr; // Безопасный нулевой указатель



