using System;

internal class MyDate
{
    private int _day;
    private int _month;
    private int _year;
    private static string _dayOfWeek;

    public int Day
    {
        get => _day;
        set
        {
            if (value < 1 || value > DateTime.DaysInMonth(_year, _month))
                throw new ArgumentOutOfRangeException(nameof(value), $"День должен быть в диапазоне от 1 до {DateTime.DaysInMonth(_year, _month)} для указанного месяца.");
            _day = value;
        }
    }
    
    public int Month
    {
        get => _month;
        set
        {
            if (value < 1 || value > 12)
                throw new ArgumentOutOfRangeException(nameof(value), "Месяц должен быть в диапазоне от 1 до 12.");
            _month = value;
        }
    }
    
    public int Year
    {
        get => _year;
        set
        {
            if (value < 1 || value > DateTime.Now.Year)
                throw new ArgumentOutOfRangeException(nameof(value), "Год должен быть больше 0 и не превышать текущий год.");
            _year = value;
        }
    }
    
    public static string DayOfWeek
    {
        get => _dayOfWeek;
        private set => _dayOfWeek = value;
    }

    static MyDate()
    {
        _dayOfWeek = "Monday"; 
    }

    public MyDate()
    {
        _day = 1;
        _month = 1;
        _year = 2000;
        UpdateDayOfWeek();
    }

    public MyDate(int day, int month, int year)
    {
        Year = year;
        Month = month;
        Day = day; 
        UpdateDayOfWeek();
    }

    public int DifferenceInDays(MyDate otherDate)
    {
        DateTime thisDate = new DateTime(_year, _month, _day);
        DateTime other = new DateTime(otherDate.Year, otherDate.Month, otherDate.Day);
        return (thisDate - other).Days;
    }

    public void ChangeDate(int days)
    {
        DateTime date = new DateTime(_year, _month, _day).AddDays(days);
        _day = date.Day;
        _month = date.Month;
        _year = date.Year;
        UpdateDayOfWeek();
    }

    public void DisplayDate()
    {
        Console.WriteLine($"Date: {_day:D2}/{_month:D2}/{_year}, Day of the week: {DayOfWeek}");
    }

    private void UpdateDayOfWeek()
    {
        DateTime date = new DateTime(_year, _month, _day);
        DayOfWeek = date.DayOfWeek.ToString();
    }
}

class Program
{
    static void Main()
    {
        try
        {
            MyDate date1 = new MyDate();
            date1.DisplayDate();

            MyDate date2 = new MyDate(31, 2, 2024);
            date2.DisplayDate();

            int diff = date1.DifferenceInDays(date2);
            Console.WriteLine($"Difference between dates: {diff} days");

            date2.ChangeDate(10);
            date2.DisplayDate();
        }
        catch (Exception ex)
        {
            Console.WriteLine("Ошибка: " + ex.Message);
        }
    }
}
