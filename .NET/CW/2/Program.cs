using System;
using System.Collections.Generic;

/*
//1
class Program
{
    static void Main()
    {
        int[] array = { 1, 2, 2, 3, 4, 5, 6, 7, 8, 9 };
        CountElements(array);
    }

    static void CountElements(int[] array)
    {
        HashSet<int> uniqueElements = new HashSet<int>(array);
        int evenCount = 0;
        int oddCount = 0;

        foreach (int num in uniqueElements)
        {
            if (num % 2 == 0)
                evenCount++;
            else
                oddCount++;
        }

        Console.WriteLine($"Четные элементы: {evenCount}");
        Console.WriteLine($"Нечетные элементы: {oddCount}");
        Console.WriteLine($"Уникальные элементы: {uniqueElements.Count}");
    }
}
*/


/*
//2
class Program
{
    static void Main()
    {
        int[] array = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        Console.Write("Введите число: ");
        int threshold = int.Parse(Console.ReadLine());
        CountLessThan(array, threshold);
    }

    static void CountLessThan(int[] array, int threshold)
    {
        int count = 0;

        foreach (int num in array)
        {
            if (num < threshold)
                count++;
        }

        Console.WriteLine($"Количество значений меньше {threshold}: {count}");
    }
}
*/

/*
//3
class Program
{
    static void Main()
    {
        Console.Write("Введите три числа (через пробел): ");
        string[] input = Console.ReadLine().Split(' ');
        int[] numbers = Array.ConvertAll(input, int.Parse);

        int[] array = { 7, 6, 5, 3, 4, 7, 6, 5, 8, 7, 6 };
        CountSequence(array, numbers);
    }

    static void CountSequence(int[] array, int[] sequence)
    {
        int count = 0;

        for (int i = 0; i <= array.Length - sequence.Length; i++)
        {
            bool match = true;

            for (int j = 0; j < sequence.Length; j++)
            {
                if (array[i + j] != sequence[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
                count++;
        }

        Console.WriteLine($"Количество повторений последовательности: {count}");
    }
}
*/

/*
//4
class Program
{
    static void Main()
    {
        int[] array1 = { 1, 2, 3, 4 };
        int[] array2 = { 3, 4, 5, 6 };

        int[] result = MergeArrays(array1, array2);
        Console.WriteLine("Объединенный массив: " + string.Join(", ", result));
    }

    static int[] MergeArrays(int[] array1, int[] array2)
    {
        HashSet<int> uniqueElements = new HashSet<int>(array1);
        foreach (int num in array2)
        {
            uniqueElements.Add(num);
        }

        return new List<int>(uniqueElements).ToArray();
    }
}
*/