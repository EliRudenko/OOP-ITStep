using System;
using System.Collections.Generic;
using System.Linq;

namespace LINQIntroduction
{
    public class Program
    {
        public static void Main()
        {
            var firms = new List<Firm>
            {
                new Firm("White Food Ltd", new DateTime(2020, 5, 1), "Marketing", "John White", 120, "London"),
                new Firm("Tech IT Solutions", new DateTime(2019, 8, 12), "IT", "Sarah Black", 250, "New York"),
                new Firm("Foodies Paradise", new DateTime(2021, 3, 15), "Food", "Emily White", 50, "London"),
                new Firm("Black White Marketing", new DateTime(2023, 1, 10), "Marketing", "Robert Black", 75, "Paris"),
                new Firm("Innovative IT Co.", new DateTime(2018, 11, 20), "IT", "Liam Green", 500, "Berlin")
            };


            firms[0].Employees.AddRange(new List<Employee>
            {
                new Employee("Lione Smith", "Manager", "234567890", "lione.smith@example.com", 80000),
                new Employee("David Johnson", "Developer", "234567891", "david.johnson@example.com", 70000)
            });
            firms[1].Employees.Add(new Employee("Anna Brown", "Manager", "234123456", "anna.brown@example.com", 85000));
            




            Console.WriteLine("1. Все фирмы:");
            firms.ForEach(Console.WriteLine);

            Console.WriteLine("\n2. Фирмы с названием, содержащим 'Food':");
            var foodFirms = from f in firms where f.Name.Contains("Food") select f;
            foodFirms.ToList().ForEach(Console.WriteLine);

            Console.WriteLine("\n3. Фирмы в области маркетинга:");
            var marketingFirms = from f in firms where f.BusinessProfile == "Marketing" select f;
            marketingFirms.ToList().ForEach(Console.WriteLine);

            Console.WriteLine("\n4. Фирмы в области маркетинга или IT:");
            var marketingOrItFirms = from f in firms where f.BusinessProfile == "Marketing" || f.BusinessProfile == "IT" select f;
            marketingOrItFirms.ToList().ForEach(Console.WriteLine);

            Console.WriteLine("\n5. Фирмы с количеством сотрудников больше 100:");
            firms.Where(f => f.EmployeesCount > 100).ToList().ForEach(Console.WriteLine);

            Console.WriteLine("\n6. Фирмы с количеством сотрудников от 100 до 300:");
            firms.Where(f => f.EmployeesCount >= 100 && f.EmployeesCount <= 300).ToList().ForEach(Console.WriteLine);

            Console.WriteLine("\n7. Фирмы в Лондоне:");
            firms.Where(f => f.Address == "London").ToList().ForEach(Console.WriteLine);

            Console.WriteLine("\n8. Фирмы с директором White:");
            firms.Where(f => f.Director.Split(' ').Last() == "White").ToList().ForEach(Console.WriteLine);

            Console.WriteLine("\n9. Фирмы старше двух лет:");
            firms.Where(f => (DateTime.Now - f.FoundationDate).TotalDays > 730).ToList().ForEach(Console.WriteLine);

            Console.WriteLine("\n10. Фирмы, основанные 123 дня назад:");
            firms.Where(f => (DateTime.Now - f.FoundationDate).TotalDays == 123).ToList().ForEach(Console.WriteLine);

            Console.WriteLine("\n11. Фирмы с директором Black и названием, содержащим White:");
            firms.Where(f => f.Director.Split(' ').Last() == "Black" && f.Name.Contains("White")).ToList().ForEach(Console.WriteLine);






            Console.WriteLine("\n12. Сотрудники фирмы 'White Food Ltd':");
            firms.First(f => f.Name == "White Food Ltd").Employees.ForEach(Console.WriteLine);

            Console.WriteLine("\n13. Сотрудники фирмы 'White Food Ltd' с зарплатой больше 75,000:");
            firms.First(f => f.Name == "White Food Ltd").Employees.Where(e => e.Salary > 75000).ToList().ForEach(Console.WriteLine);

            Console.WriteLine("\n14. Сотрудники всех фирм с должностью 'Manager':");
            firms.SelectMany(f => f.Employees).Where(e => e.Position == "Manager").ToList().ForEach(Console.WriteLine);

            Console.WriteLine("\n15. Сотрудники с телефоном, начинающимся на 23:");
            firms.SelectMany(f => f.Employees).Where(e => e.Phone.StartsWith("23")).ToList().ForEach(Console.WriteLine);

            Console.WriteLine("\n16. Сотрудники с Email, начинающимся на 'di':");
            firms.SelectMany(f => f.Employees).Where(e => e.Email.StartsWith("di")).ToList().ForEach(Console.WriteLine);

            Console.WriteLine("\n17. Сотрудники с именем Lione:");
            firms.SelectMany(f => f.Employees).Where(e => e.FullName.Contains("Lione")).ToList().ForEach(Console.WriteLine);
        }
    }

    public class Firm
    {
        public string Name { get; }
        public DateTime FoundationDate { get; }
        public string BusinessProfile { get; }
        public string Director { get; }
        public int EmployeesCount { get; }
        public string Address { get; }
        public List<Employee> Employees { get; }

        public Firm(string name, DateTime foundationDate, string businessProfile, string director, int employeesCount, string address)
        {
            Name = name;
            FoundationDate = foundationDate;
            BusinessProfile = businessProfile;
            Director = director;
            EmployeesCount = employeesCount;
            Address = address;
            Employees = new List<Employee>();
        }

        public override string ToString() => $"{Name}, {BusinessProfile}, Director: {Director}, Employees: {EmployeesCount}, Address: {Address}";
    }

    public class Employee
    {
        public string FullName { get; }
        public string Position { get; }
        public string Phone { get; }
        public string Email { get; }
        public decimal Salary { get; }

        public Employee(string fullName, string position, string phone, string email, decimal salary)
        {
            FullName = fullName;
            Position = position;
            Phone = phone;
            Email = email;
            Salary = salary;
        }

        public override string ToString() => $"{FullName}, {Position}, Phone: {Phone}, Email: {Email}, Salary: {Salary:C}";
    }
}
