
class Herbivore 
{
    constructor(weight, life) 
    {
      this.weight = weight;
      this.life = life;
    }
  
    eatGrass() 
    {
      this.weight += 10;
    }
  }
  

  class Wildebeest extends Herbivore 
  {
    constructor(weight, life) 
    {
      super(weight, life);
    }
  }
  
  class Bison extends Herbivore 
  {
    constructor(weight, life) 
    {
      super(weight, life);
    }
  }

  class Carnivore 
  {
    constructor(power) 
    {
      this.power = power;
    }
  

    eat(herbivore) 
    {
      if (this.power > herbivore.weight) 
      {
        this.power += 10;
      } else { this.power -= 10; }
    }
  }
  
  class Lion extends Carnivore 
  {
    constructor(power) 
    {
      super(power);
    }
  }
  
  class Wolf extends Carnivore {
    constructor(power) {
      super(power);
    }
  }
  
  // Класс Континент - абстрактный
  class Continent {
    constructor() {
      if (this.constructor === Continent) {
        throw new Error("Abstract classes can't be instantiated.");
      }
    }
  }
  
  // Конкретные классы континентов
  class Africa extends Continent {
    constructor() {
      super();
    }
  }
  
  class NorthAmerica extends Continent {
    constructor() {
      super();
    }
  }
  
  // Класс Мир животных - клиент
  class AnimalWorld {
    // Метод для кормления травоядных
    mealsHerbivores(herbivores) {
      herbivores.forEach((herbivore) => {
        herbivore.eatGrass();
      });
    }
  
    // Метод для питания плотоядных
    nutritionCarnivores(carnivores, herbivore) {
      carnivores.forEach((carnivore) => {
        carnivore.eat(herbivore);
      });
    }
  }
  
  // Пример использования:
  
  // Создание экземпляров травоядных и плотоядных
  const wildebeest = new Wildebeest(100, true);
  const bison = new Bison(150, true);
  
  const lion = new Lion(120);
  const wolf = new Wolf(90);
  
  // Создание континентов
  const africa = new Africa();
  const northAmerica = new NorthAmerica();
  
  // Создание экземпляра мира животных
  const animalWorld = new AnimalWorld();
  
  // Вызов методов для кормления и питания
  animalWorld.mealsHerbivores([wildebeest, bison]);
  animalWorld.nutritionCarnivores([lion, wolf], wildebeest);
  