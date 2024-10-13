using System;
using System.Globalization;

/*
//1
class CaesarCipher
{
    public static string Encrypt(string input, int shift)
    {
        string result = "";
        foreach (char c in input)
        {
            if (char.IsLetter(c))
            {
                char offset = char.IsUpper(c) ? 'A' : 'a';
                result += (char)(((c + shift - offset) % 26) + offset);
            }
            else
            {
                result += c;
            }
        }
        return result;
    }

    public static string Decrypt(string input, int shift)
    {
        return Encrypt(input, 26 - shift); 
    }

    static void Main()
    {
        Console.WriteLine("Введите строку для шифрования:");
        string input = Console.ReadLine();
        Console.WriteLine("Введите сдвиг:");
        int shift = int.Parse(Console.ReadLine());

        string encrypted = Encrypt(input, shift);
        string decrypted = Decrypt(encrypted, shift);

        Console.WriteLine($"Зашифрованная строка: {encrypted}");
        Console.WriteLine($"Расшифрованная строка: {decrypted}");
    }
}
*/




/*
//2
class Program
{
    static void Main()
    {
        Console.WriteLine("Введите арифметическое выражение (поддерживаются только + и -):");
        string input = Console.ReadLine();

        try
        {
            int result = EvaluateExpression(input);
            Console.WriteLine("Результат: " + result);
        }
        catch (Exception ex)
        {
            Console.WriteLine("Ошибка: " + ex.Message);
        }
    }

    static int EvaluateExpression(string expression)
    {
        int sum = 0;
        int currentNumber = 0;
        bool isNegative = false;

        for (int i = 0; i < expression.Length; i++)
        {
            char c = expression[i];

            if (char.IsDigit(c))
            {
                currentNumber = currentNumber * 10 + (c - '0'); 
            }
            else if (c == '+' || c == '-')
            {
                sum += isNegative ? -currentNumber : currentNumber; 
                currentNumber = 0; 

                isNegative = (c == '-'); 
            }
        }

        sum += isNegative ? -currentNumber : currentNumber;

        return sum;
    }
}
*/


/*
//3
class SentenceCapitalizer
{
    static void Main()
    {
        Console.WriteLine("Введите текст:");
        string input = Console.ReadLine();

        string[] sentences = input.Split(new[] { ". " }, StringSplitOptions.None);
        for (int i = 0; i < sentences.Length; i++)
        {
            if (!string.IsNullOrEmpty(sentences[i]))
            {
                sentences[i] = char.ToUpper(sentences[i][0]) + sentences[i].Substring(1);
            }
        }

        string result = string.Join(". ", sentences);
        Console.WriteLine($"Результат: {result}");
    }
}
*/

/*
//4
class WordReplacer
{
    static void Main()
    {
        Console.WriteLine("Введите текст:");
        string input = Console.ReadLine();

        Console.WriteLine("Введите недопустимое слово:");
        string forbiddenWord = Console.ReadLine();

        string replacement = new string('*', forbiddenWord.Length);
        int count = 0;
        string result = input.Replace(forbiddenWord, replacement, StringComparison.OrdinalIgnoreCase);

        count = (input.Length - result.Length) / forbiddenWord.Length;

        Console.WriteLine("Результат:");
        Console.WriteLine(result);
        Console.WriteLine($"Статистика: {count} замены слова {forbiddenWord}");
    }
}
*/