using System;
using System.Collections.Generic;


/*
//3
public class ArrayOperations
{
    public static int[] GetEvenNumbers(int[] array) => Array.FindAll(array, x => x % 2 == 0);

    public static int[] GetOddNumbers(int[] array) => Array.FindAll(array, x => x % 2 != 0);

    public static int[] GetPrimeNumbers(int[] array)
    {
        List<int> primes = new List<int>();
        foreach (var num in array)
        {
            if (IsPrime(num))
                primes.Add(num);
        }
        return primes.ToArray();
    }

    private static bool IsPrime(int num)
    {
        if (num <= 1) return false;
        for (int i = 2; i <= Math.Sqrt(num); i++)
        {
            if (num % i == 0) return false;
        }
        return true;
    }

    public static int[] GetFibonacciNumbers(int[] array)
    {
        List<int> fibonacci = new List<int>();
        foreach (var num in array)
        {
            if (IsFibonacci(num))
                fibonacci.Add(num);
        }
        return fibonacci.ToArray();
    }

    private static bool IsFibonacci(int num)
    {
        int a = 0, b = 1, sum = 0;
        while (sum < num)
        {
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum == num;
    }
}

public delegate int[] ArrayOperation(int[] array);

class Program
{
    static void Main()
    {
        int[] numbers = { 2, 3, 5, 8, 13, 21, 34 };

        ArrayOperation getEvens = ArrayOperations.GetEvenNumbers;
        ArrayOperation getOdds = ArrayOperations.GetOddNumbers;
        ArrayOperation getPrimes = ArrayOperations.GetPrimeNumbers;
        ArrayOperation getFibonacci = ArrayOperations.GetFibonacciNumbers;

        Console.WriteLine("Четные числа: " + string.Join(", ", getEvens(numbers)));
        Console.WriteLine("Нечетные числа: " + string.Join(", ", getOdds(numbers)));
        Console.WriteLine("Простые числа: " + string.Join(", ", getPrimes(numbers)));
        Console.WriteLine("Числа Фибоначчи: " + string.Join(", ", getFibonacci(numbers)));
    }
}
*/


/*
//2
public class DisplayOperations
{

    public static void DisplayTime() => Console.WriteLine("Текущее время: " + DateTime.Now.ToString("T"));
    public static void DisplayDate() => Console.WriteLine("Текущая дата: " + DateTime.Now.ToString("D"));
    public static void DisplayDayOfWeek() => Console.WriteLine("Текущий день недели: " + DateTime.Now.DayOfWeek);
    public static double CalculateTriangleArea(double baseLength, double height) => 0.5 * baseLength * height;
    public static double CalculateRectangleArea(double width, double height) => width * height;
}

class Program
{
    static void Main()
    {
        Action showTime = DisplayOperations.DisplayTime;
        Action showDate = DisplayOperations.DisplayDate;
        Action showDayOfWeek = DisplayOperations.DisplayDayOfWeek;

        showTime();
        showDate();
        showDayOfWeek();

        Func<double, double, double> triangleArea = DisplayOperations.CalculateTriangleArea;
        Func<double, double, double> rectangleArea = DisplayOperations.CalculateRectangleArea;

        Console.WriteLine("Площадь треугольника: " + triangleArea(10, 5));
        Console.WriteLine("Площадь прямоугольника: " + rectangleArea(10, 5));
    }
}
*/


/*
//3
public class CreditCard
{
    public string CardNumber { get; set; }
    public string CardHolderName { get; set; }
    public DateTime ExpiryDate { get; set; }
    private string pin;
    public double CreditLimit { get; set; }
    public double Balance { get; private set; }

    public event Action<double> OnBalanceAdded;
    public event Action<double> OnBalanceSpent;
    public event Action OnCreditLimitReached;
    public event Action OnCreditUsageStarted;
    public event Action OnPinChanged;

    public CreditCard(string cardNumber, string cardHolderName, DateTime expiryDate, string pin, double creditLimit)
    {
        CardNumber = cardNumber;
        CardHolderName = cardHolderName;
        ExpiryDate = expiryDate;
        this.pin = pin;
        CreditLimit = creditLimit;
        Balance = 0;
    }

    public void AddFunds(double amount)
    {
        Balance += amount;
        OnBalanceAdded?.Invoke(amount);

        if (Balance >= CreditLimit)
        {
            OnCreditLimitReached?.Invoke();
        }
    }

    public void SpendFunds(double amount)
    {
        if (Balance < amount)
        {
            Console.WriteLine("Недостаточно средств.");
            return;
        }

        Balance -= amount;
        OnBalanceSpent?.Invoke(amount);

        if (Balance < 0)
        {
            OnCreditUsageStarted?.Invoke();
        }
    }

    public void ChangePin(string newPin)
    {
        pin = newPin;
        OnPinChanged?.Invoke();
    }
}


class Program3
{
    static void Main()
    {
        var card = new CreditCard("1234-5678-9876-5432", "Иван Иванов", DateTime.Now.AddYears(3), "1234", 1000);

        card.OnBalanceAdded += (amount) => Console.WriteLine($"Счёт пополнен на {amount}.");
        card.OnBalanceSpent += (amount) => Console.WriteLine($"Списано со счёта: {amount}.");
        card.OnCreditLimitReached += () => Console.WriteLine("Достигнут кредитный лимит.");
        card.OnCreditUsageStarted += () => Console.WriteLine("Началось использование кредитных средств.");
        card.OnPinChanged += () => Console.WriteLine("PIN успешно изменён.");

        card.AddFunds(500);
        card.SpendFunds(200);
        card.SpendFunds(800); 
        card.ChangePin("5678");
    }
}
*/