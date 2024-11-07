using System;
using System.Collections;
using System.Collections.Generic;

/*
public class SeaCreature
{
    public string Name { get; set; }
    public string Species { get; set; }

    public SeaCreature(string name, string species)
    {
        Name = name;
        Species = species;
    }

    public override string ToString()
    {
        return $"{Name} - {Species}";
    }
}




public class Oceanarium<T> : IEnumerable<T> where T : SeaCreature
{
    private List<T> creatures = new List<T>();

    public void AddCreature(T creature) { creatures.Add(creature); }

    public IEnumerator<T> GetEnumerator() { return creatures.GetEnumerator(); }

    IEnumerator IEnumerable.GetEnumerator() { return GetEnumerator();}
}


public class Program
{
    public static void Main()
    {
        Oceanarium<SeaCreature> oceanarium = new Oceanarium<SeaCreature>();
        oceanarium.AddCreature(new SeaCreature("Shark", "Fish"));
        oceanarium.AddCreature(new SeaCreature("Dolphin", "Mammal"));

        Console.WriteLine("Жители океанариума:");
        foreach (var creature in oceanarium)
        {
            Console.WriteLine(creature);
        }
    }
}
*/





/*
public class FootballPlayer
{
    public string Name { get; set; }
    public string Position { get; set; }

    public FootballPlayer(string name, string position)
    {
        Name = name;
        Position = position;
    }

    public override string ToString()
    {
        return $"{Name} - {Position}";
    }
}


public class FootballTeam<T> : IEnumerable<T> where T : FootballPlayer
{
    private List<T> players = new List<T>();

    public void AddPlayer(T player) { players.Add(player);}

    public IEnumerator<T> GetEnumerator() { return players.GetEnumerator(); }

    IEnumerator IEnumerable.GetEnumerator(){return GetEnumerator();}
}


public class Program
{
    public static void Main()
    {
        FootballTeam<FootballPlayer> team = new FootballTeam<FootballPlayer>();
        team.AddPlayer(new FootballPlayer("John Doe", "Forward"));
        team.AddPlayer(new FootballPlayer("Jane Smith", "Goalkeeper"));

        Console.WriteLine("Игроки футбольной команды:");
        foreach (var player in team)
        {
            Console.WriteLine(player);
        }
    }
}
*/



/*
public class CafeEmployee
{
    public string Name { get; set; }
    public string Position { get; set; }

    public CafeEmployee(string name, string position)
    {
        Name = name;
        Position = position;
    }

    public override string ToString()
    {
        return $"{Name} - {Position}";
    }
}


public class Cafe<T> : IEnumerable<T> where T : CafeEmployee
{
    private List<T> employees = new List<T>();

    public void AddEmployee(T employee){ employees.Add(employee);}

    public IEnumerator<T> GetEnumerator(){ return employees.GetEnumerator();}

    IEnumerator IEnumerable.GetEnumerator() {return GetEnumerator(); }
}


public class Program
{
    public static void Main()
    {
        Cafe<CafeEmployee> cafe = new Cafe<CafeEmployee>();
        cafe.AddEmployee(new CafeEmployee("Alice", "Barista"));
        cafe.AddEmployee(new CafeEmployee("Bob", "Chef"));

        Console.WriteLine("Работники кафе:");
        foreach (var employee in cafe)
        {
            Console.WriteLine(employee);
        }
    }
}
*/