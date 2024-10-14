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
        set => _day = value;
    }
    public int Month
    {
        get => _month;
        set => _month = value;
    }
    public int Year
    {
        get => _year;
        set => _year = value;
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
        _day = day;
        _month = month;
        _year = year;
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
        MyDate date1 = new MyDate();
        date1.DisplayDate();

        MyDate date2 = new MyDate(15, 10, 2024);
        date2.DisplayDate();

        int diff = date1.DifferenceInDays(date2);
        Console.WriteLine($"Difference between dates: {diff} days");

        date2.ChangeDate(10);
        date2.DisplayDate();
    }
}
