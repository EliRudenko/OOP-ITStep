using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;

class Program
{
    static List<int> arr = new List<int> { 6, 8, 9, 3, 5 }; 
    static Mutex mutex = new Mutex();
    static List<int> modifiedArr = new List<int>(); 

    static void Main()
    {
        Console.WriteLine("Массив: " + string.Join(" ", arr)); 

        Task task1 = Task.Factory.StartNew(Thread1);
        Task task2 = Task.Factory.StartNew(Thread2);

        Task.WaitAll(task1, task2);

        Console.ReadLine();
    }

    static void Thread1()
    {
        Random rnd = new Random();
        mutex.WaitOne(); 

        for (int i = 0; i < arr.Count; i++)
        {
            int randomValue = rnd.Next(1000000000, 2000000000); 
            modifiedArr.Add(arr[i] + randomValue); 
        }

        mutex.ReleaseMutex(); 
    }

    static void Thread2()
    {
        mutex.WaitOne();

        Console.WriteLine("Mассив + число: " + string.Join(" ", modifiedArr));

        int max = modifiedArr.Max();
        Console.WriteLine("Max: " + max);

        mutex.ReleaseMutex(); 
    }
}
