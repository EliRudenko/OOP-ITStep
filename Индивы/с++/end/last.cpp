#include <iostream>



//1


// Функция для поиска минимального и максимального элементов массива
// Использует указатели для возврата значений

void findMinMax(int* arr, int size, int* min, int* max) 
{
    *min = *max = arr[0]; // Устанавливаем начальные значения
    for (int i = 1; i < size; i++) 
    {
        if (arr[i] < *min) *min = arr[i]; // Обновляем минимум
        if (arr[i] > *max) *max = arr[i]; // Обновляем максимум
    }
}

int main() 
{
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    // Динамическое выделение памяти для массива
    int* arr = new int[n];

    // Заполнение массива случайными числами (просто умножаем индекс)
    std::cout << "Сгенерированный массив: ";
    for (int i = 0; i < n; i++) 
    {
        arr[i] = (i * 7) % 100 + 1; // Генерация чисел (без библиотеки <cstdlib>)
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int min, max;
    findMinMax(arr, n, &min, &max);

    std::cout << "Минимальное значение: " << min << std::endl;
    std::cout << "Максимальное значение: " << max << std::endl;

    // Освобождение памяти
    delete[] arr;
    return 0;
}









//2


// Определение перечисления Gender
enum Gender { Male, Female };

// Определение структуры Student
struct Student 
{
    char name[50]; // Имя студента
    int age;       // Возраст
    double gpa;    // Средний балл
    Gender gender; // Пол (Male или Female)
};


// Функция для поиска студента с наивысшим средним баллом
// Принимает массив студентов по ссылке
void findBestStudent(Student* students, int size, Student& best) 
{
    best = students[0]; // Начальное значение - первый студент
    for (int i = 1; i < size; i++) 
    {
        if (students[i].gpa > best.gpa) 
        {
            best = students[i]; // Обновляем лучшего студента
        }
    }
}

int main() 
{
    const int numStudents = 3; // Количество студентов
    Student students[numStudents];

    // Ввод данных для студентов
    for (int i = 0; i < numStudents; i++) 
    {
        std::cout << "Введите имя студента " << i + 1 << ": ";
        std::cin >> students[i].name;
        std::cout << "Введите возраст: ";
        std::cin >> students[i].age;
        std::cout << "Введите средний балл: ";
        std::cin >> students[i].gpa;
        int genderInput;
        std::cout << "Введите пол (0 - Male, 1 - Female): ";
        std::cin >> genderInput;
        students[i].gender = (genderInput == 0) ? Male : Female;
    }

    Student bestStudent;
    findBestStudent(students, numStudents, bestStudent);

    // Вывод информации о лучшем студенте
    std::cout << "\nЛучший студент: " << bestStudent.name 
              << ", возраст: " << bestStudent.age 
              << ", средний балл: " << bestStudent.gpa 
              << ", пол: " << (bestStudent.gender == Male ? "Male" : "Female") 
              << std::endl;

    return 0;
}










//3


int main() 
{
    char choice;
    do {
        double num1, num2, result;
        char op;

        // Ввод первого числа
        std::cout << "Введите первое число: ";
        std::cin >> num1;

        // Ввод оператора
        std::cout << "Введите оператор (+, -, *, /): ";
        std::cin >> op;

        // Ввод второго числа
        std::cout << "Введите второе число: ";
        std::cin >> num2;

        // Выполнение операций с помощью switch
        switch (op) 
        {
            case '+':
                result = num1 + num2;
                std::cout << "Результат: " << result << std::endl;
                break;
            case '-':
                result = num1 - num2;
                std::cout << "Результат: " << result << std::endl;
                break;
            case '*':
                result = num1 * num2;
                std::cout << "Результат: " << result << std::endl;
                break;
            case '/':
                if (num2 == 0) 
                {
                    std::cout << "Ошибка: деление на ноль запрещено!" << std::endl;
                } 
                else {
                    result = num1 / num2;
                    std::cout << "Результат: " << result << std::endl;
                }
                break;
            default:
                std::cout << "Ошибка: неверный оператор!" << std::endl;
        }

        // Спрашиваем, хочет ли пользователь продолжить
        std::cout << "Хотите продолжить? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');


    return 0;
}









