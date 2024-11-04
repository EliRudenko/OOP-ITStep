using System;
using System.Linq;
using System.Collections.Generic;



/*
using System;

class Program
{
    static void Main()
    {
        Func<string, string> getRainbowColorRGB = delegate (string color)
        {
            return color.ToLower() switch
            {
                "красный" => "RGB(255, 0, 0)",
                "оранжевый" => "RGB(255, 165, 0)",
                "жёлтый" => "RGB(255, 255, 0)",
                "зелёный" => "RGB(0, 128, 0)",
                "голубой" => "RGB(0, 255, 255)",
                "синий" => "RGB(0, 0, 255)",
                "фиолетовый" => "RGB(128, 0, 128)",
                _ => "Неизвестный цвет"
            };
        };

        string[] colors = { "Красный", "Оранжевый", "Жёлтый", "Зелёный", "Голубой", "Синий", "Фиолетовый", "Белый" };

        for (int i = 0; i < colors.Length; i++)
        {
            Console.WriteLine($"{colors[i]}: {getRainbowColorRGB(colors[i])}");
        }
    }
}
*/





/*
class Program
{
    static void Main()
    {
        int[] numbers = { 7, 14, 21, 10, 35, 8, 50 };

        int countMultiplesOfSeven = numbers.Count(n => n % 7 == 0);
        
        Console.WriteLine($"Количество чисел, кратных 7: {countMultiplesOfSeven}");
    }
}
*/



/*
class Program
{
    static void Main()
    {
        int[] numbers = { -5, 3, 10, -8, 15, 0, 25 };

        int countPositiveNumbers = numbers.Count(n => n > 0);
        
        Console.WriteLine($"Количество положительных чисел: {countPositiveNumbers}");
    }
}
*/



/*
class Program
{
    static void Main()
    {
        int[] numbers = { -5, -10, -5, 3, -8, 15, -8, -20 };

        var uniqueNegativeNumbers = numbers.Where(n => n < 0).Distinct();

        Console.WriteLine("Уникальные отрицательные числа: " + string.Join(", ", uniqueNegativeNumbers));
    }
}
*/



/*
class Program
{
    static void Main()
    {
        string text = "Этот текст содержит несколько слов, включая слово 'текст'.";
        string wordToFind = "текст";

        bool containsWord = text.Contains(wordToFind, StringComparison.OrdinalIgnoreCase);

        Console.WriteLine($"Текст содержит слово '{wordToFind}': {containsWord}");
    }
}
*/



/*
public class Backpack
{
    public string Color { get; set; }
    public string Brand { get; set; }
    public string Fabric { get; set; }
    public double Weight { get; set; }
    public double Volume { get; set; }

    private List<Item> contents;
    private double currentVolume;

    public Backpack(double volume)
    {
        Volume = volume;
        contents = new List<Item>();
        currentVolume = 0;

        OnItemAdded += (sender, item) =>
        {
            if (currentVolume + item.Volume > Volume)
                throw new InvalidOperationException("Объём рюкзака превышен!");

            contents.Add(item);
            currentVolume += item.Volume;
            Console.WriteLine($"Добавлен объект '{item.Name}' объемом {item.Volume} л.");
        };
    }

    public event EventHandler<Item> OnItemAdded;

    public void AddItem(string name, double itemVolume)
    {
        Item newItem = new Item { Name = name, Volume = itemVolume };
        OnItemAdded?.Invoke(this, newItem);
    }

    public class Item
    {
        public string Name { get; set; }
        public double Volume { get; set; }
    }

    public void ShowContents()
    {
        Console.WriteLine("\nСодержимое рюкзака:");
        foreach (var item in contents)
        {
            Console.WriteLine($"- {item.Name} ({item.Volume} л)");
        }
        Console.WriteLine($"Общий занимаемый объем: {currentVolume} из {Volume} л");
    }
}

class Program
{
    static void Main()
    {
        Backpack backpack = new Backpack(10);
        backpack.Color = "Черный";
        backpack.Brand = "Nike";
        backpack.Fabric = "Полиэстер";
        backpack.Weight = 0.8;

        try
        {
            backpack.AddItem("Бутылка воды", 2);
            backpack.AddItem("Книга", 1.5);
            backpack.AddItem("Ноутбук", 5);

            backpack.AddItem("Плед", 3); 
        }
        catch (InvalidOperationException ex)
        {
            Console.WriteLine($"Ошибка: {ex.Message}");
        }

        backpack.ShowContents();
    }
}
*/
