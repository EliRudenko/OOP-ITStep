using System;

/*
//1
class KreditnayaKartochka
{
    public string NomerKarty { get; private set; }
    public string FIO { get; private set; }
    public int CVC { get; private set; }
    public DateTime DataOkonchaniya { get; private set; }

    public KreditnayaKartochka(string nomerKarty, string fio, int cvc, DateTime dataOkonchaniya)
    {
        if (nomerKarty.Length != 16)
        {
            throw new ArgumentException("Номер карты должен содержать 16 символов.");
        }

        if (cvc < 100 || cvc > 999)
        {
            throw new ArgumentException("CVC должен содержать 3 цифры.");
        }

        if (dataOkonchaniya < DateTime.Now)
        {
            throw new ArgumentException("Срок действия карты истек.");
        }

        NomerKarty = nomerKarty;
        FIO = fio;
        CVC = cvc;
        DataOkonchaniya = dataOkonchaniya;
    }
}

class Program
{
    static void Main(string[] args)
    {
        try
        {
            Console.Write("Введите номер карты (16 цифр): ");
            string nomerKarty = Console.ReadLine();

            Console.Write("Введите ФИО владельца: ");
            string fio = Console.ReadLine();

            Console.Write("Введите CVC (3 цифры): ");
            int cvc = int.Parse(Console.ReadLine());

            Console.Write("Введите дату окончания (ГГГГ-ММ-ДД): ");
            DateTime dataOkonchaniya = DateTime.Parse(Console.ReadLine());

            KreditnayaKartochka karta = new KreditnayaKartochka(nomerKarty, fio, cvc, dataOkonchaniya);
            Console.WriteLine("Карта успешно создана!");
        }
        catch (Exception ex) { Console.WriteLine("Ошибка: " + ex.Message);}
    }
}
*/


/*
//2
class Program
{
    static void Main(string[] args)
    {
        try
        {
            Console.WriteLine("Введите математическое выражение (например, 3*2*1*4):");
            string input = Console.ReadLine();

            string[] numbers = input.Split('*');
            int result = 1;

            foreach (string number in numbers)
            {
                if (int.TryParse(number, out int num))
                {
                    result *= num;
                }
                else
                { throw new ArgumentException("Неверный формат числа: " + number); }
            }

            Console.WriteLine("Результат: " + result);
        }
        catch (Exception ex) { Console.WriteLine("Ошибка: " + ex.Message); }
    }
}
*/