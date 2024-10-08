using System;

/*
//1
class Program
{
    static void Main()
    {
        PrintQuote();
    }

    static void PrintQuote()
    {
        Console.WriteLine("It's easy to win forgiveness for being wrong;");
        Console.WriteLine("being right is what gets you into real trouble.");
        Console.WriteLine("Bjarne Stroustrup");
    }
}
*/

/*
//2
class Program
{
    static void Main()
    {
        int[] numbers = GetNumbersFromUser();
        int sum = GetSum(numbers);
        int max = GetMax(numbers);
        int min = GetMin(numbers);
        int product = GetProduct(numbers);

        PrintResults(sum, max, min, product);
    }

    static int[] GetNumbersFromUser()
    {
        int[] numbers = new int[5];
        Console.WriteLine("Введите 5 чисел:");

        for (int i = 0; i < 5; i++)
        {
            Console.Write($"Число {i + 1}: ");
            numbers[i] = int.Parse(Console.ReadLine());
        }

        return numbers;
    }

    static int GetSum(int[] numbers)
    {
        int sum = 0;
        foreach (int number in numbers)
        {
            sum += number;
        }
        return sum;
    }

    static int GetMax(int[] numbers)
    {
        int max = numbers[0];
        foreach (int number in numbers)
        {
            if (number > max)
                max = number;
        }
        return max;
    }

    static int GetMin(int[] numbers)
    {
        int min = numbers[0];
        foreach (int number in numbers)
        {
            if (number < min)
                min = number;
        }
        return min;
    }

    static int GetProduct(int[] numbers)
    {
        int product = 1;
        foreach (int number in numbers)
        {
            product *= number;
        }
        return product;
    }

    static void PrintResults(int sum, int max, int min, int product)
    {
        Console.WriteLine($"Сумма: {sum}");
        Console.WriteLine($"Максимум: {max}");
        Console.WriteLine($"Минимум: {min}");
        Console.WriteLine($"Произведение: {product}");
    }
}
*/

/*
//3
class Program
{
    static void Main()
    {
        ReverseNumber();
    }

    static void ReverseNumber()
    {
        Console.WriteLine("Введите шестизначное число:");
        string input = Console.ReadLine();
        
        char[] reversedArray = input.ToCharArray();
        Array.Reverse(reversedArray);

        string reversedNumber = new string(reversedArray);
        Console.WriteLine($"Перевернутое число: {reversedNumber}");
    }
}
*/


/*
//4
class Program
{
    static void Main()
    {
        ShowFibonacciInRange();
    }

    static void ShowFibonacciInRange()
    {
        Console.Write("Введите начало диапазона: ");
        int start = int.Parse(Console.ReadLine());

        Console.Write("Введите конец диапазона: ");
        int end = int.Parse(Console.ReadLine());

        Console.WriteLine("Числа Фибоначчи в диапазоне:");

        int a = 0, b = 1;
        while (a <= end)
        {
            if (a >= start)
            {
                Console.Write(a + " ");
            }
            int temp = a;
            a = b;
            b = temp + b;
        }
        Console.WriteLine();
    }
}
*/

/*
//5
class Program
{
    static void Main()
    {
        PrintNumbersWithRepetition();
    }

    static void PrintNumbersWithRepetition()
    {
        Console.Write("Введите число A (A < B): ");
        int A = int.Parse(Console.ReadLine());

        Console.Write("Введите число B (A < B): ");
        int B = int.Parse(Console.ReadLine());

        if (A >= B)
        {
            Console.WriteLine("Ошибка: A должно быть меньше B.");
            return;
        }

        // Цикл от A до B включительно
        for (int i = A; i <= B; i++)
        {
            // Выводим текущее число i, i раз
            for (int j = 0; j < i; j++)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine(); 
        }
    }
}
*/

/*
//6
class Program
{
    static void Main()
    {
        DrawLine();
    }

    static void DrawLine()
    {
        Console.Write("Введите длину линии: ");
        int length = int.Parse(Console.ReadLine());

        Console.Write("Введите символ заполнителя: ");
        char symbol = Console.ReadKey().KeyChar;
        Console.WriteLine();

        Console.Write("Введите направление ('h' для горизонтальной, 'v' для вертикальной): ");
        char direction = Console.ReadKey().KeyChar;
        Console.WriteLine();

        if (direction == 'h')
        {
            for (int i = 0; i < length; i++)
            {
                Console.Write(symbol);
            }
            Console.WriteLine();
        }
        else if (direction == 'v')
        {
            for (int i = 0; i < length; i++)
            {
                Console.WriteLine(symbol);
            }
        }
        else
        {
            Console.WriteLine("Неверное направление.");
        }
    }
}
*/


