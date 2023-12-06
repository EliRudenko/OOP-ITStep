    class Animal 
    {
        constructor(weight, life) 
        {
            this.weight = weight;
            this.life = life;
        }
    }
    class Herbivore extends Animal 
    {
        constructor(weight, life) 
        {
            //род
            super(weight, life);
        }
    
        eatGrass() 
        { 
            this.weight += 10; 
            console.log("Herbivore is eating grass. Weight increased to: " + this.weight);
        } //набираем вес(
    }
    
    class Carnivore extends Animal 
    {
        constructor(power, life) 
        {
            //пока что 0, потому что потом прибавляем
            super(0, life);
            this.power = power;
        }
    
        eat(herbivore) 
        {//проверки по условию
            if (this.power >= herbivore.weight) 
            {
                this.power += 10;
            } else { this.power -= 10; }
            console.log("Carnivore is eating. Power changed to: " + this.power);
        }
    }
    
    class Wildebeest extends Herbivore 
    {
        constructor(weight, life) 
        {
            //род
            super(weight, life);
        }
    }
    class Bison extends Herbivore 
    {
        constructor(weight, life) 
        {
            //род
            super(weight, life);
        }
    }
    

    class Lion extends Carnivore 
    {
        constructor(power, life) 
        {
            //родиетльский 
            super(power, life); //передали аргументы для Lion
        }
    }
    class Wolf extends Carnivore 
    {
        constructor(power, life) 
        {
            //родительский
            super(power, life);//передаем аргументы для Wolf
        }
    }
    

    class Continent 
    {
        constructor(){}
    }
    

    class Africa extends Continent 
    {
        constructor(wildebeest_Weight, lion_Power) // для wildebeest и lion континент Africa, переданные значения
        {
            super();//род

            //создаются обьекты и передаем значение  для животных Африки
            this.wildebeest = new Wildebeest(wildebeest_Weight, true);
            this.lion = new Lion(lion_Power, true);
        }
    }
    
    class NorthAmerica extends Continent 
    {
        constructor(bison_Weight, wolf_Power)  // переданные значения для континента NorthAmerica, ждя животного бизон и волк 
        {
            super();//род

            //создаются обьекты с передачей значения 
            this.bison = new Bison(bison_Weight, true);
            this.wolf = new Wolf(wolf_Power, true);
        }
    }

    //тут были проверки
    // console.log(northAmerica.bison); 
    // console.log(northAmerica.wolf);
    
    class AnimalWorld 
    {
        constructor(){}
    
        mealHerbivores(continent) 
        {
            continent.wildebeest.eatGrass(); //для травоядных
            continent.bison && continent.bison.eatGrass(); //существует ли бизон, ибо так по условию, проверочка
        }
    
        mealCarnivores(continent) 
        {
            continent.lion && continent.lion.eat(continent.wildebeest); // ест wildebeest если он существует, проверочка, существует ли лев
            continent.wolf && continent.wolf.eat(continent.bison);// так же как со львом
        }
    }
    
