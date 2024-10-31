using System;
using System.Collections.Generic;


public interface IPart
{
    bool IsBuilt { get; set; }
    void Build();
}

public interface IWorker
{
    void Work(House house);
}




public class Basement : IPart
{
    public bool IsBuilt { get; set; }
    public void Build()
    {
        IsBuilt = true;
        Console.WriteLine("Фундамент построен.");
    }
}
public class Wall : IPart
{
    public bool IsBuilt { get; set; }
    public void Build()
    {
        IsBuilt = true;
        Console.WriteLine("Стена построена.");
    }
}
public class Door : IPart
{
    public bool IsBuilt { get; set; }
    public void Build()
    {
        IsBuilt = true;
        Console.WriteLine("Дверь установлена.");
    }
}
public class Window : IPart
{
    public bool IsBuilt { get; set; }
    public void Build()
    {
        IsBuilt = true;
        Console.WriteLine("Окно установлено.");
    }
}
public class Roof : IPart
{
    public bool IsBuilt { get; set; }
    public void Build()
    {
        IsBuilt = true;
        Console.WriteLine("Крыша построена.");
    }
}



public class House
{
    public Basement Basement { get; } = new Basement();
    public List<Wall> Walls { get; } = new List<Wall> { new Wall(), new Wall(), new Wall(), new Wall() };
    public Door Door { get; } = new Door();
    public List<Window> Windows { get; } = new List<Window> { new Window(), new Window(), new Window(), new Window() };
    public Roof Roof { get; } = new Roof();

    public bool IsBuilt => Basement.IsBuilt && Walls.TrueForAll(w => w.IsBuilt) && Door.IsBuilt && Windows.TrueForAll(w => w.IsBuilt) && Roof.IsBuilt;
    public void DisplayHouse()
    {
        Console.WriteLine("Строительство дома завершено!");
        Console.WriteLine("      ____________");
        Console.WriteLine("     /           \\");
        Console.WriteLine("    /             \\");
        Console.WriteLine("   /_______________\\");
        Console.WriteLine("  |      ___       |");
        Console.WriteLine("  |     |   |      |");
        Console.WriteLine("  |_____|___|______|");

    }

}



public class Worker : IWorker
{
    public void Work(House house)
    {
        if (!house.Basement.IsBuilt)
        {
            house.Basement.Build();
        }
        else if (house.Walls.Exists(w => !w.IsBuilt))
        {
            house.Walls.Find(w => !w.IsBuilt)?.Build();
        }
        else if (!house.Door.IsBuilt)
        {
            house.Door.Build();
        }
        else if (house.Windows.Exists(w => !w.IsBuilt))
        {
            house.Windows.Find(w => !w.IsBuilt)?.Build();
        }
        else if (!house.Roof.IsBuilt)
        {
            house.Roof.Build();
        }
    }
}



public class TeamLeader : IWorker
{
    public void Work(House house)
    {
        int totalParts = 1 + house.Walls.Count + 1 + house.Windows.Count + 1;
        int builtParts = (house.Basement.IsBuilt ? 1 : 0)
                         + house.Walls.FindAll(w => w.IsBuilt).Count
                         + (house.Door.IsBuilt ? 1 : 0)
                         + house.Windows.FindAll(w => w.IsBuilt).Count
                         + (house.Roof.IsBuilt ? 1 : 0);

        Console.WriteLine($"Отчёт: построено {builtParts} из {totalParts} частей дома.");
    }
}


public class Team
{
    private readonly List<IWorker> workers;

    public Team()
    {
        workers = new List<IWorker> { new Worker(), new Worker(), new TeamLeader() };
    }

    public void BuildHouse(House house)
    {
        while (!house.IsBuilt)
        {
            foreach (var worker in workers)
            {
                worker.Work(house);
            }
        }
        house.DisplayHouse();
    }
}





class Program
{
    static void Main()
    {
        House house = new House();
        Team team = new Team();
        team.BuildHouse(house);
    }
}
