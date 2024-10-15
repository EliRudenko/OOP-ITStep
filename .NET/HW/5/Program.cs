using System;


/*
//1
internal class Employee
{
    public string FullName { get; set; }
    public DateTime BirthDate { get; set; }
    public string ContactNumber { get; set; }
    public string WorkEmail { get; set; }
    public string Position { get; set; }
    public string JobDescription { get; set; }

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

    public void UpdateContactNumber(ref string newContactNumber)
    {
        ContactNumber = newContactNumber;
        Console.WriteLine($"Updated Contact Number: {ContactNumber}");
    }

    public void GetEssentialInfo(out string fullName, out string position)
    {
        fullName = FullName;
        position = Position;
    }
}

class ProgramEmployee
{
    static void Main()
    {
        Employee employee = new Employee();
        employee.InputData();
        employee.OutputData();

        string newContact = "123-456-7890";
        employee.UpdateContactNumber(ref newContact);

        employee.GetEssentialInfo(out string name, out string pos);
        Console.WriteLine($"Essential Info: Name - {name}, Position - {pos}");
    }
}
*/



/*
//2
internal class Airplane

    public string AirplaneName { get; set; } = "Unknown";
    public string Manufacturer { get; set; } = "Unknown";

    private int _yearOfManufacture;
    public int YearOfManufacture
    {
        get => _yearOfManufacture;
        set
        {
            if (value > 1900 && value <= DateTime.Now.Year)
                _yearOfManufacture = value;
            else
                throw new ArgumentException("Invalid year of manufacture");
        }
    }

    private double _wingspan;
    public double Wingspan
    {
        get => _wingspan;
        set
        {
            if (value > 0)
                _wingspan = value;
            else
                throw new ArgumentException("Wingspan must be positive");
        }
    }

    public string Type { get; set; } = "Unknown";

    public Airplane() { }

    public Airplane(string airplaneName, string manufacturer, int yearOfManufacture, double wingspan, string type)
    {
        AirplaneName = airplaneName;
        Manufacturer = manufacturer;
        YearOfManufacture = yearOfManufacture;
        Wingspan = wingspan;
        Type = type;
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
        else { OutputData(); }
    }

    public void UpdateWingspan(ref double newWingspan)
    {
        Wingspan = newWingspan;
        Console.WriteLine($"Updated Wingspan: {Wingspan}");
    }

    public void GetAirplaneDetails(out string name, out string manufacturer, out int year)
    {
        name = AirplaneName;
        manufacturer = Manufacturer;
        year = YearOfManufacture;
    }

    public void PrintDetails(in string message)
    {
        Console.WriteLine($"Message: {message}, Airplane: {AirplaneName}, Year: {YearOfManufacture}");
    }
}

class ProgramAirplane
{
    static void Main()
    {
        Airplane airplane = new Airplane();
        airplane.InputData();
        airplane.OutputData(); 

        double newWingspan = 35.5;
        airplane.UpdateWingspan(ref newWingspan);

        airplane.GetAirplaneDetails(out string name, out string manufacturer, out int year);
        Console.WriteLine($"Airplane Details: {name}, {manufacturer}, Year: {year}");

        string message = "Airplane Info";
        airplane.PrintDetails(in message);
    }
}
*/