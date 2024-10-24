using System;


abstract class Herbivore
{
    public int Weight { get; protected set; }
    public bool IsAlive { get; private set; } = true;

    public Herbivore(int weight) { Weight = weight; }

    public void EatGrass()
    {
        if (IsAlive)
        {
            Weight += 10;
            Console.WriteLine($"{this.GetType().Name} ate grass and now weighs {Weight} kg.");
        }
    }

    public void Die()
    {
        IsAlive = false;
        Console.WriteLine($"{this.GetType().Name} has died.");
    }
}

abstract class Carnivore
{
    public int Power { get; protected set; }

    public Carnivore(int power) { Power = power; }

    public void Eat(Herbivore herbivore)
    {
        if (herbivore.IsAlive && Power > herbivore.Weight)
        {
            Power += 10;
            herbivore.Die();
            Console.WriteLine($"{this.GetType().Name} ate {herbivore.GetType().Name} and its power is now {Power}.");
        }
        else
        {
            Power -= 10;
            Console.WriteLine($"{this.GetType().Name} failed to eat {herbivore.GetType().Name}, and its power decreased to {Power}.");
        }
    }
}




class Wildebeest : Herbivore
{
    public Wildebeest(int weight) : base(weight) { }
}
class Bison : Herbivore
{
    public Bison(int weight) : base(weight) { }
}
class Kangaroo : Herbivore
{
    public Kangaroo(int weight) : base(weight) { }
}


class Lion : Carnivore
{
    public Lion(int power) : base(power) { }
}
class Wolf : Carnivore
{
    public Wolf(int power) : base(power) { }
}
class TasmanianWolf : Carnivore
{
    public TasmanianWolf(int power) : base(power) { }
}




abstract class ContinentFactory
{
    public abstract Herbivore CreateHerbivore();
    public abstract Carnivore CreateCarnivore();
}



class AfricaFactory : ContinentFactory
{
    public override Herbivore CreateHerbivore() => new Wildebeest(150);
    public override Carnivore CreateCarnivore() => new Lion(200);
}
class NorthAmericaFactory : ContinentFactory
{
    public override Herbivore CreateHerbivore() => new Bison(300);
    public override Carnivore CreateCarnivore() => new Wolf(180);
}
class AustraliaFactory : ContinentFactory
{
    public override Herbivore CreateHerbivore() => new Kangaroo(120);
    public override Carnivore CreateCarnivore() => new TasmanianWolf(160);
}




class AnimalWorld
{
    private Herbivore _herbivore;
    private Carnivore _carnivore;

    public AnimalWorld(ContinentFactory factory)
    {
        _herbivore = factory.CreateHerbivore();
        _carnivore = factory.CreateCarnivore();
    }

    public void MealsHerbivores()
    {
        _herbivore.EatGrass();
    }

    public void NutritionCarnivores()
    {
        _carnivore.Eat(_herbivore);
    }
}

class Program
{
    static void Main(string[] args)
    {

        ContinentFactory africa = new AfricaFactory();
        AnimalWorld animalWorldAfrica = new AnimalWorld(africa);
        animalWorldAfrica.MealsHerbivores();
        animalWorldAfrica.NutritionCarnivores();

        Console.WriteLine();




        ContinentFactory northAmerica = new NorthAmericaFactory();
        AnimalWorld animalWorldNA = new AnimalWorld(northAmerica);
        animalWorldNA.MealsHerbivores();
        animalWorldNA.NutritionCarnivores();

        Console.WriteLine();




        ContinentFactory australia = new AustraliaFactory();
        AnimalWorld animalWorldAustralia = new AnimalWorld(australia);
        animalWorldAustralia.MealsHerbivores();
        animalWorldAustralia.NutritionCarnivores();
    }
}
