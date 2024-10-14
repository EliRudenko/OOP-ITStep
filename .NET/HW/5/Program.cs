using System;


/*
//1
internal class Employee
{
    private string _fullName;
    private DateTime _birthDate;
    private string _contactNumber;
    private string _workEmail;
    private string _position;
    private string _jobDescription;

    public string FullName
    {
        get => _fullName;
        set => _fullName = value;
    }
    public DateTime BirthDate
    {
        get => _birthDate;
        set => _birthDate = value;
    }
    public string ContactNumber
    {
        get => _contactNumber;
        set => _contactNumber = value;
    }
    public string WorkEmail
    {
        get => _workEmail;
        set => _workEmail = value;
    }
    public string Position
    {
        get => _position;
        set => _position = value;
    }
    public string JobDescription
    {
        get => _jobDescription;
        set => _jobDescription = value;
    }




    public void InputData()
    {
        Console.WriteLine("Enter full name:");
        FullName = Console.ReadLine();

        Console.WriteLine("Enter birthdate (yyyy-mm-dd):");
        BirthDate = DateTime.Parse(Console.ReadLine());

        Console.WriteLine("Enter contact number:");
        ContactNumber = Console.ReadLine();

        Console.WriteLine("Enter work email:");
        WorkEmail = Console.ReadLine();

        Console.WriteLine("Enter position:");
        Position = Console.ReadLine();

        Console.WriteLine("Enter job description:");
        JobDescription = Console.ReadLine();
    }


    public void OutputData()
    {
        Console.WriteLine($"Full Name: {FullName}");
        Console.WriteLine($"Birthdate: {BirthDate.ToShortDateString()}");
        Console.WriteLine($"Contact Number: {ContactNumber}");
        Console.WriteLine($"Work Email: {WorkEmail}");
        Console.WriteLine($"Position: {Position}");
        Console.WriteLine($"Job Description: {JobDescription}");
    }
}

class ProgramEmployee
{
    static void Main()
    {
        Employee employee = new Employee();
        employee.InputData();
        employee.OutputData();
    }
}
*/


/*
//2
internal class Airplane
{
    private string _airplaneName;
    private string _manufacturer;
    private int _yearOfManufacture;
    private double _wingspan;
    private string _type;

    public string AirplaneName
    {
        get => _airplaneName;
        set => _airplaneName = value;
    }
    public string Manufacturer
    {
        get => _manufacturer;
        set => _manufacturer = value;
    }
    public int YearOfManufacture
    {
        get => _yearOfManufacture;
        set => _yearOfManufacture = value;
    }
    public double Wingspan
    {
        get => _wingspan;
        set => _wingspan = value;
    }
    public string Type
    {
        get => _type;
        set => _type = value;
    }
    public Airplane()
    {
        _airplaneName = "Unknown";
        _manufacturer = "Unknown";
        _yearOfManufacture = 0;
        _wingspan = 0.0;
        _type = "Unknown";
    }
    public Airplane(string airplaneName, string manufacturer, int yearOfManufacture, double wingspan, string type)
    {
        _airplaneName = airplaneName;
        _manufacturer = manufacturer;
        _yearOfManufacture = yearOfManufacture;
        _wingspan = wingspan;
        _type = type;
    }



    public void InputData()
    {
        Console.WriteLine("Enter airplane name:");
        AirplaneName = Console.ReadLine();

        Console.WriteLine("Enter manufacturer:");
        Manufacturer = Console.ReadLine();

        Console.WriteLine("Enter year of manufacture:");
        YearOfManufacture = int.Parse(Console.ReadLine());

        Console.WriteLine("Enter wingspan:");
        Wingspan = double.Parse(Console.ReadLine());

        Console.WriteLine("Enter type:");
        Type = Console.ReadLine();
    }


    public void OutputData()
    {
        Console.WriteLine($"Airplane Name: {AirplaneName}");
        Console.WriteLine($"Manufacturer: {Manufacturer}");
        Console.WriteLine($"Year of Manufacture: {YearOfManufacture}");
        Console.WriteLine($"Wingspan: {Wingspan} meters");
        Console.WriteLine($"Type: {Type}");
    }

    public void OutputData(string format)
    {
        if (format == "short")
        {
            Console.WriteLine($"Name: {AirplaneName}, Manufacturer: {Manufacturer}");
        }
        else
        {
            OutputData();
        }
    }
}

class ProgramAirplane
{
    static void Main()
    {
        Airplane airplane = new Airplane();
        airplane.InputData();
        airplane.OutputData(); 

        airplane.OutputData("short");
    }
}
*/