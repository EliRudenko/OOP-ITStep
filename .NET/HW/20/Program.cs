using System;
using System.IO;

public class Money : IDisposable
{
    public int UAH { get; private set; } 
    public int Kopecks { get; private set; }

    private StreamWriter logWriter;

    public Money(int uah, int kopecks) 
    {
        logWriter = new StreamWriter("money_log.txt", true);
        Log($"Создан объект Money: {uah} UAH {kopecks} коп");

        if (uah < 0 || kopecks < 0)
            throw new InvalidOperationException("Сумма не может быть отрицательной.");

        UAH = uah + kopecks / 100;
        Kopecks = kopecks % 100;
    }

    // +
    public static Money operator +(Money m1, Money m2)
    {
        int totalKopecks = m1.Kopecks + m2.Kopecks;
        int totalUAH = m1.UAH + m2.UAH + totalKopecks / 100;
        Money result = new Money(totalUAH, totalKopecks % 100);
        
        result.Log($"Операция сложения: {m1} + {m2} = {result}");
        return result;
    }

    // -
    public static Money operator -(Money m1, Money m2)
    {
        int totalKopecks = m1.Kopecks - m2.Kopecks;
        int totalUAH = m1.UAH - m2.UAH;

        if (totalKopecks < 0)
        {
            totalKopecks += 100;
            totalUAH--;
        }

        if (totalUAH < 0)
        {
            var exceptionMessage = "Недостаточно средств (банкрот)";
            LogError(exceptionMessage);
            throw new InvalidOperationException(exceptionMessage);
        }

        Money result = new Money(totalUAH, totalKopecks);
        result.Log($"Операция вычитания: {m1} - {m2} = {result}");
        return result;
    }

    // *
    public static Money operator *(Money m, int multiplier)
    {
        int totalKopecks = m.Kopecks * multiplier;
        int totalUAH = m.UAH * multiplier + totalKopecks / 100;
        Money result = new Money(totalUAH, totalKopecks % 100);
        
        result.Log($"Операция умножения: {m} * {multiplier} = {result}");
        return result;
    }

    // /
    public static Money operator /(Money m, int divisor)
    {
        if (divisor == 0)
        {
            var exceptionMessage = "Деление на ноль невозможно.";
            LogError(exceptionMessage);
            throw new DivideByZeroException(exceptionMessage);
        }

        int totalKopecks = m.UAH * 100 + m.Kopecks;
        totalKopecks /= divisor;
        Money result = new Money(totalKopecks / 100, totalKopecks % 100);
        
        result.Log($"Операция деления: {m} / {divisor} = {result}");
        return result;
    }

    //  == и !=
    public static bool operator ==(Money m1, Money m2)
    {
        bool result = m1.UAH == m2.UAH && m1.Kopecks == m2.Kopecks;
        
        Log($"Операция сравнения (==): {m1} == {m2} = {result}");
        return result;
    }

    public static bool operator !=(Money m1, Money m2)
    {
        bool result = !(m1 == m2);
        
        Log($"Операция сравнения (!=): {m1} != {m2} = {result}");
        return result;
    }

    // <
    public static bool operator <(Money m1, Money m2)
    {
        bool result = m1.UAH < m2.UAH || (m1.UAH == m2.UAH && m1.Kopecks < m2.Kopecks);
        
        Log($"Операция сравнения (<): {m1} < {m2} = {result}");
        return result;
    }

    //  ++
    public static Money operator ++(Money m)
    {
        Money result = m + new Money(0, 1);  // Увеличиваем на 1 копейку
        
        result.Log($"Операция инкремента: {m}++ = {result}");
        return result;
    }

    // --
    public static Money operator --(Money m)
    {
        Money result = m - new Money(0, 1);  // Уменьшаем на 1 копейку
        
        result.Log($"Операция декремента: {m}-- = {result}");
        return result;
    }

    // Переопределение метода ToString для вывода
    public override string ToString()
    {
        return $"{UAH} UAH {Kopecks} коп";  // Заменили на UAH
    }

    // Логирование операции
    private void Log(string message)
    {
        logWriter.WriteLine($"{DateTime.Now}: {message}");
        logWriter.Flush();
    }

    // Логирование ошибок
    private static void LogError(string message)
    {
        using (StreamWriter errorWriter = new StreamWriter("error_log.txt", true))
        {
            errorWriter.WriteLine($"{DateTime.Now}: {message}");
            errorWriter.Flush();
        }
    }


    public void Dispose()
    {
        logWriter?.Dispose();
        Log("Ресурсы освобождены.");
    }

    public override bool Equals(object obj)
    {
        if (obj is Money)
        {
            var other = (Money)obj;
            return this == other;
        }
        return false;
    }

    public override int GetHashCode()
    {
        return UAH.GetHashCode() ^ Kopecks.GetHashCode();
    }
}

class Program
{
    static void Main()
    {
        try
        {
            using (Money m1 = new Money(10, 50))
            using (Money m2 = new Money(5, 75))
            {
                Money sum = m1 + m2;
                Money difference = m1 - m2;
                Money product = m1 * 2;
                Money quotient = m1 / 2;

                Console.WriteLine($"Сумма: {sum}");
                Console.WriteLine($"Разница: {difference}");
                Console.WriteLine($"Умножение на 2: {product}");
                Console.WriteLine($"Деление на 2: {quotient}");
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка: {ex.Message}");
        }
    }
}
