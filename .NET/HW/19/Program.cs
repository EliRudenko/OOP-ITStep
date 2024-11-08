using System;
using System.Collections.Generic;


/*
class EmployeeManager
{
    private Dictionary<string, string> employeePasswords = new Dictionary<string, string>();

    public void AddEmployee(string login, string password)
    {
        if (!employeePasswords.ContainsKey(login))
        {
            employeePasswords[login] = password;
            Console.WriteLine("Сотрудник добавлен.");
        }
        else
        {
            Console.WriteLine("Логин уже существует.");
        }
    }

    public void RemoveEmployee(string login)
    {
        if (employeePasswords.Remove(login))
        {
            Console.WriteLine("Сотрудник удален.");
        }
        else
        {
            Console.WriteLine("Сотрудник не найден.");
        }
    }

    public void UpdatePassword(string login, string newPassword)
    {
        if (employeePasswords.ContainsKey(login))
        {
            employeePasswords[login] = newPassword;
            Console.WriteLine("Пароль изменен.");
        }
        else
        {
            Console.WriteLine("Сотрудник не найден.");
        }
    }

    public string GetPassword(string login)
    {
        if (employeePasswords.TryGetValue(login, out string password))
        {
            return password;
        }
        else
        {
            return "Сотрудник не найден.";
        }
    }
}
*/



/*
class EnglishFrenchDictionary
{
    private Dictionary<string, List<string>> dictionary = new Dictionary<string, List<string>>();
    
    public void AddWord(string word, string translation)
    {
        if (!dictionary.ContainsKey(word))
        {
            dictionary[word] = new List<string>();
        }
        dictionary[word].Add(translation);
        Console.WriteLine("Перевод добавлен.");
    }

    public void RemoveWord(string word)
    {
        if (dictionary.Remove(word))
        {
            Console.WriteLine("Слово удалено.");
        }
        else
        {
            Console.WriteLine("Слово не найдено.");
        }
    }

    public void UpdateTranslation(string word, int index, string newTranslation)
    {
        if (dictionary.ContainsKey(word) && index < dictionary[word].Count)
        {
            dictionary[word][index] = newTranslation;
            Console.WriteLine("Перевод изменен.");
        }
        else
        {
            Console.WriteLine("Перевод не найден.");
        }
    }

    public List<string> GetTranslations(string word)
    {
        if (dictionary.TryGetValue(word, out List<string> translations))
        {
            return translations;
        }
        else
        {
            return new List<string> { "Перевод не найден." };
        }
    }
}
*/


/*
class CafeQueue
{
    private Queue<string> queue = new Queue<string>();

    public void AddCustomer(string customerName)
    {
        queue.Enqueue(customerName);
        Console.WriteLine($"Клиент {customerName} добавлен в очередь.");
    }

    public void ServeCustomer()
    {
        if (queue.Count > 0)
        {
            string servedCustomer = queue.Dequeue();
            Console.WriteLine($"Клиент {servedCustomer} обслужен.");
        }
        else
        {
            Console.WriteLine("Очередь пуста.");
        }
    }

    public string PeekNextCustomer()
    {
        if (queue.Count > 0)
        {
            return $"Следующий клиент: {queue.Peek()}";
        }
        else
        {
            return "Очередь пуста.";
        }
    }

    public void DisplayQueue()
    {
        if (queue.Count > 0)
        {
            Console.WriteLine("Очередь клиентов:");
            foreach (string customer in queue)
            {
                Console.WriteLine(customer);
            }
        }
        else
        {
            Console.WriteLine("Очередь пуста.");
        }
    }
}
*/