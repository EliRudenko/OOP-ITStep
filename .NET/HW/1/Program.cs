using System;

/*
//1
class Program
{
    static void Main()
    {
        Console.Write("Введите число от 1 до 100: ");
        int number = int.Parse(Console.ReadLine());

        if (number < 1 || number > 100)
        {
            Console.WriteLine("Ошибка: Число должно быть в диапазоне от 1 до 100.");
        }
        else
        {
            if (number % 3 == 0 && number % 5 == 0){ Console.WriteLine("Fizz Buzz"); }
            else if (number % 3 == 0) { Console.WriteLine("Fizz"); }
            else if (number % 5 == 0) { Console.WriteLine("Buzz"); }
            else{ Console.WriteLine(number); }
        }
    }
}
*/


/*
//2
class Program
{
    static void Main()
    {
        Console.Write("Введите число: ");
        double value = double.Parse(Console.ReadLine());

        Console.Write("Введите процент: ");
        double percent = double.Parse(Console.ReadLine());

        double result = value * percent / 100;

        Console.WriteLine($"{percent}% от {value} равно {result}");
    }
}
*/


/*
//3
using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Введите 4 цифры:");

        Console.Write("Введите первую цифру: ");
        int digit1 = int.Parse(Console.ReadLine());

        Console.Write("Введите вторую цифру: ");
        int digit2 = int.Parse(Console.ReadLine());

        Console.Write("Введите третью цифру: ");
        int digit3 = int.Parse(Console.ReadLine());

        Console.Write("Введите четвертую цифру: ");
        int digit4 = int.Parse(Console.ReadLine());

        int number = digit1 * 1000 + digit2 * 100 + digit3 * 10 + digit4;

        Console.WriteLine($"Сформированное число: {number}");
    }
}
*/


/*
//4
class Program
{
    static void Main()
    {
        Console.Write("Введите шестизначное число: ");
        string input = Console.ReadLine();

        if (input.Length != 6 || !int.TryParse(input, out _))
        {
            Console.WriteLine("Ошибка: Введите корректное шестизначное число.");
            return;
        }

        Console.Write("Введите номера разрядов для обмена (например, 1 и 6): ");
        string[] positions = Console.ReadLine().Split();
        int pos1 = int.Parse(positions[0]) - 1; 
        int pos2 = int.Parse(positions[1]) - 1; 


        char[] digits = input.ToCharArray();
        char temp = digits[pos1];
        digits[pos1] = digits[pos2];
        digits[pos2] = temp;

        string result = new string(digits);
        Console.WriteLine($"Результат: {result}");
    }
}
*/


/*
//5
class Program
{
    static void Main()
    {
        Console.Write("Введите дату (дд.мм.гггг): ");
        string input = Console.ReadLine();
        
        if (DateTime.TryParse(input, out DateTime date))
        {
            string season = GetSeason(date);
            string dayOfWeek = date.ToString("dddd");

            Console.WriteLine($"{season} {dayOfWeek}");
        }
        else
        {
            Console.WriteLine("Ошибка: Неверный формат даты.");
        }
    }

    static string GetSeason(DateTime date)
    {
        if (date.Month == 12 || date.Month <= 2)
            return "Winter";
        else if (date.Month <= 5)
            return "Spring";
        else if (date.Month <= 8)
            return "Summer";
        else
            return "Autumn";
    }
}
*/

/*
//6
class Program
{
    static void Main()
    {
        Console.Write("Введите температуру: ");
        double temperature = double.Parse(Console.ReadLine());

        Console.Write("Выберите перевод: 1 (Фаренгейт в Цельсий) или 2 (Цельсий в Фаренгейт): ");
        int choice = int.Parse(Console.ReadLine());

        if (choice == 1)
        {
            double celsius = (temperature - 32) * 5 / 9;
            Console.WriteLine($"{temperature}°F = {celsius:F2}°C");
        }
        else if (choice == 2)
        {
            double fahrenheit = (temperature * 9 / 5) + 32;
            Console.WriteLine($"{temperature}°C = {fahrenheit:F2}°F");
        }
        else { Console.WriteLine("Ошибка: Неверный выбор."); }
    }
}
*/



//7
class Program
{
    static void Main()
    {
        Console.Write("Введите первое число: ");
        int firstNumber = int.Parse(Console.ReadLine());

        Console.Write("Введите второе число: ");
        int secondNumber = int.Parse(Console.ReadLine());

        int start = Math.Min(firstNumber, secondNumber);
        int end = Math.Max(firstNumber, secondNumber);

        Console.WriteLine($"Четные числа в диапазоне от {start} до {end}:");
        
        for (int i = start; i <= end; i++)
        {
            if (i % 2 == 0)
            { Console.WriteLine(i); }
        }
    }
}
