using System;
using System.IO;
using System.Threading;
namespace ThreadSample
{
    class Program
    {
        static void Main(string[] args)
        {
            #region 1 Task
            //int[] numbers = new int[4] { 1, 2, 3, 5 };

            //Thread thread = new Thread(() =>
            //{
            //    foreach (int item in numbers)
            //    {
            //        Console.WriteLine("From num to string: " + item.ToString());

            //    }
            //});
            //thread.Start();
            #endregion

            Bank myBank = new Bank("UniverseBank", 10000, 2);
            myBank.Name = "BankUniverse";
            myBank.Money = 100;
            myBank.Percent = 1;
            Console.WriteLine("Свойства изменены. Данные записываются в файл...");
            Console.ReadLine();
            #region 2 Task


            #endregion
        }


        class Bank
        {
            private int money;
            private string name;
            private int percent;

            public int Money
            {
                get => money;
                set
                {
                    money = value;
                    ThreadLog();
                }
            }

            public string Name
            {
                get => name;
                set
                {
                    name = value;
                    ThreadLog();
                }
            }

            public int Percent
            {
                get => percent;
                set
                {
                    percent = value;
                    ThreadLog();
                }
            }

            public Bank(string name, int money, int percent)
            {
                this.name = name;
                this.money = money;
                this.percent = percent;
                ShowInf();
            }

            private void ShowInf()
            {
                Console.WriteLine($"Bank name: {Name} | Money: {Money} | Percent:{Percent}%");
            }

            private void WriteToFile()
            {
                string path = "dataBank.txt";
                string data = $"Bank name: {Name} | Money: {Money} | Percent:{Percent}%";

                if (!File.Exists(path))
                {
                    using (StreamWriter writer = File.CreateText(path))
                    {
                        writer.WriteLine(data);
                    }
                    Console.WriteLine("Файл был создан и записан.");
                }
                else
                {
                    Console.WriteLine("Файл уже существует.");
                }

            }

            private void ThreadLog() { 

                Thread log = new Thread(WriteToFile);
                log.Start();
               
            }

        }
    }

}
