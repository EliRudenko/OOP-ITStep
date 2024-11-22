using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    class Phone
    {
        public string Name { get; set; }
        public string Manufacturer { get; set; }
        public decimal Price { get; set; }
        public DateTime ReleaseDate { get; set; }
    }

    static void Main()
    {

        var phones = new List<Phone>
        {
            new Phone { Name = "Galaxy S22", Manufacturer = "Samsung", Price = 800, ReleaseDate = new DateTime(2022, 2, 1) },
            new Phone { Name = "IPhone 13", Manufacturer = "Apple", Price = 1000, ReleaseDate = new DateTime(2021, 9, 1) },
            new Phone { Name = "Xperia 5", Manufacturer = "Sony", Price = 700, ReleaseDate = new DateTime(2021, 3, 1) },
            new Phone { Name = "Galaxy A50", Manufacturer = "Samsung", Price = 400, ReleaseDate = new DateTime(2019, 5, 1) },
            new Phone { Name = "IPhone X", Manufacturer = "Apple", Price = 600, ReleaseDate = new DateTime(2018, 11, 1) },
            new Phone { Name = "Redmi Note 10", Manufacturer = "Xiaomi", Price = 200, ReleaseDate = new DateTime(2020, 6, 1) },
            new Phone { Name = "Pixel 6", Manufacturer = "Google", Price = 500, ReleaseDate = new DateTime(2021, 10, 1) }
        };




        Console.WriteLine($"Количество телефонов: {phones.Count}");
        Console.WriteLine($"Телефоны с ценой больше 100: {phones.Count(p => p.Price > 100)}");
        Console.WriteLine($"Телефоны с ценой от 400 до 700: {phones.Count(p => p.Price >= 400 && p.Price <= 700)}");
        Console.WriteLine($"Телефоны Samsung: {phones.Count(p => p.Manufacturer == "Samsung")}");
        Console.WriteLine($"Телефон с минимальной ценой: {phones.OrderBy(p => p.Price).First().Name}");
        Console.WriteLine($"Телефон с максимальной ценой: {phones.OrderByDescending(p => p.Price).First().Name}");
        Console.WriteLine($"Самый старый телефон: {phones.OrderBy(p => p.ReleaseDate).First().Name}");
        Console.WriteLine($"Самый свежий телефон: {phones.OrderByDescending(p => p.ReleaseDate).First().Name}");
        Console.WriteLine($"Средняя цена телефона: {phones.Average(p => p.Price):F2}");





        Console.WriteLine("\nПять самых дорогих телефонов:");
        foreach (var phone in phones.OrderByDescending(p => p.Price).Take(5))
            Console.WriteLine(phone.Name);


        Console.WriteLine("\nПять самых дешевых телефонов:");
        foreach (var phone in phones.OrderBy(p => p.Price).Take(5))
            Console.WriteLine(phone.Name);



        Console.WriteLine("\nТри самых старых телефона:");
        foreach (var phone in phones.OrderBy(p => p.ReleaseDate).Take(3))
            Console.WriteLine(phone.Name);


        Console.WriteLine("\nТри самых новых телефона:");
        foreach (var phone in phones.OrderByDescending(p => p.ReleaseDate).Take(3))
            Console.WriteLine(phone.Name);






        Console.WriteLine("\nСтатистика по производителям:");
        var manufacturers = phones.GroupBy(p => p.Manufacturer)
                                  .Select(g => new { Manufacturer = g.Key, Count = g.Count() });
        foreach (var group in manufacturers)
            Console.WriteLine($"{group.Manufacturer} – {group.Count}");


        Console.WriteLine("\nСтатистика по моделям:");
        var models = phones.GroupBy(p => p.Name)
                           .Select(g => new { Model = g.Key, Count = g.Count() });
        foreach (var group in models)
            Console.WriteLine($"{group.Model} – {group.Count}");



        Console.WriteLine("\nСтатистика телефонов по годам:");
        var years = phones.GroupBy(p => p.ReleaseDate.Year)
                          .Select(g => new { Year = g.Key, Count = g.Count() });
        foreach (var group in years)
            Console.WriteLine($"{group.Year} – {group.Count}");
    }
}
