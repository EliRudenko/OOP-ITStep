#include <iostream>
#include <memory> // Для использования умных указателей
//std::unique_ptr для управления созданными объектами,автоматическое освобождение памяти в конце

class Herbivore 
{//АБСТРАКТНЫЙ КЛАСС ТРАВОЯДНЫХ, ИНТЕРФЕЙС ДЛЯ КОНТРЕТНЫХ ЖИВОТНЫХ
protected:
    unsigned int weight; // =ВЕС
    bool life; //НЕ СЬЕЛИ ЛИ ЕГО
public:
    Herbivore(unsigned int weight) : weight(weight), life(true) {}

    void EatGrass() 
    {//ПИТАЕТСЯ ТРАВОЙ
        if (!life)
            return;
        weight += 10; //УВЕЛИЧЕНИЕ ВЕСА ПОСЛЕ ЕДЫ
    }

    int GetWeight() const { return weight; }

    bool IsAlive() const { return life; }

    void SetLife(bool life) { this->life = life; }

    virtual std::string GetName() const = 0; // АБСТРАКТНЫЙ МЕТОД КОТОРЫЙ РЕАЛИЗУЮТ КОНКРЕТНЫЕ КЛАССЫ, ВОЗВРАТ ИМЕНИ КОНКРЕТНОГО ТРАВОЯДНОГО
};

class Carnivore 
{//АБСТРАКТНЫЙ КЛАСС хищников, ИНТЕРФЕЙС ДЛЯ КОНТРЕТНЫХ ЖИВОТНЫХ
protected:
    unsigned int power; // СИЛА
public:
    Carnivore(unsigned int power) : power(power) {}

    unsigned int GetPower() const { return power; }

    
    virtual void Eat(Herbivore *herbivore) = 0;//АБСТРАКТНЫЙ МЕТОД, КОТОРЫЙ РЕАЛИЗУЮ КОНКРЕТНЫЕ КЛАССЫ, ХИЩНИКИ ПИТАЮТСЯ ТОЛЬКО ТРАВОЯДНЫМИ

    virtual std::string GetName() const = 0;//ВОЗВРАТ ИМЕНИ ХИЩНИКА
};


//КОНКРЕТНЫЕ КЛАССЫ

class Wildebeest : public Herbivore 
{//ИНТЕРФЕЙС ТРАВОЯДНОГО, АНТИЛОПА ГНУ
public:
    Wildebeest() : Herbivore(150) {}
    std::string GetName() const override { return "Wildebeest"; }
};

class Bison : public Herbivore 
{//ИНТЕРФЕЙС ТРАВОЯДНОГО, БИЗОН
public:
    Bison() : Herbivore(500) {}
    std::string GetName() const override { return "Bison"; }
};

class Elk : public Herbivore 
{//ИНТЕРФЕЙС ТРАВОЯДНОГО, ЛОСЬ
public:
    Elk() : Herbivore(250) {}
    std::string GetName() const override { return "Elk"; }
};


class Lion : public Carnivore 
{//ИНТЕРФЕЙС ХИЩНИКА, ЛЁВИК
public:
    Lion() : Carnivore(500) {}

    //МЕТОД ДЛЯ ПИТАНИЯ (ТРАВОЯДНЫМИ)
    void Eat(Herbivore *herbivore) override 
    {
        if (this->GetPower() >= herbivore->GetWeight()) 
        {
            this->power += 10; // УВЕЛИЧЕНИЕ СИЛЫ на 10 при КАРМЁШКЕ
            herbivore->SetLife(false);  //ТРАВОЯДНОЕ ЖИВОТНОЕ = ЕДАА
            std::cout << this->GetName() << " has eaten " << herbivore->GetName() << std::endl; // ИНФА
        } 
        else { this->power -= 10;  }  // УМЕНЬШЕНИЕ СИЛЫ на 10, если НЕ ПОЙМАЛИ ЕДУ
    }

    std::string GetName() const override { return "Lion"; }
};

class Wolf : public Carnivore 
{//ИНТЕРФЕЙС ХИЩНИКА, ВОЛК
public:
    Wolf() : Carnivore(240) {}

    //МЕТОД ДЛЯ ПИТАНИЯ (ТРАВОЯДНЫМИ)
    void Eat(Herbivore *herbivore) override 
    {
        if (this->GetPower() >= herbivore->GetWeight()) 
        {
            this->power += 10; // УВЕЛИЧЕНИЕ СИЛЫ на 10 при КАРМЁШКЕ
            herbivore->SetLife(false);  //ТРАВОЯДНОЕ ЖИВОТНОЕ = ЕДАА
            std::cout << this->GetName() << " has eaten " << herbivore->GetName() << std::endl; //ИНФА
        } 
        else { this->power -= 10; } // УМЕНЬШЕНИЕ СИЛЫ на 10, если НЕ ПОЙМАЛИ ЕДУ
    }

    std::string GetName() const override { return "Wolf"; }
};

class Tiger : public Carnivore 
{//ИНТЕРФЕЙС ХИЩНИКА, ТИГРИК
public:
    Tiger() : Carnivore(450) {}

    //МЕТОД ДЛЯ ПИТАНИЯ (ТРАВОЯДНЫМИ)
    void Eat(Herbivore *herbivore) override 
    {
        if (this->GetPower() >= herbivore->GetWeight()) 
        {
            this->power += 10; // УВЕЛИЧЕНИЕ СИЛЫ на 10 при КАРМЁШКЕ
            herbivore->SetLife(false); //ТРАВОЯДНОЕ ЖИВОТНОЕ = ЕДАА
            std::cout << this->GetName() << " has eaten " << herbivore->GetName() << std::endl; //ИНФА
        } 
        else { this->power -= 10; }  // УМЕНЬШЕНИЕ СИЛЫ на 10, если НЕ ПОЙМАЛИ ЕДУ
       
    }

    std::string GetName() const override { return "Tiger"; }
};


class ContinentFactory 
{//ОПРЕДЕЛЕНИЕ ИНТЕРФЕЙСА ДЛЯ ЗВЕРЮЩЕК, АБСТРАКТНЫЙ КЛАСС ЭТО АБСТРАКТНАЯ ФАБРИКА!!
public:
    virtual ~ContinentFactory() {}
    virtual std::unique_ptr<Herbivore> CreateHerbivore() const = 0; // СОЗДАНИЕ И ВОЗВРАТ ТРАВОЯДНЫХ
    virtual std::unique_ptr<Carnivore> CreateCarnivore() const = 0; // СОЗДАНИЕ И ВОЗВРАТ ХИЩНИКОВ
};


class AfricaFactory : public ContinentFactory
{//РЕАЛИЗАЦИЯ ИНТЕРФЕЙСА АБСТРАКТНОЙ ФАБРИКИ, КЛАСС ЭТО ФАБРИКА ДЛЯ СОЗДАНИЯ ЖИВОТНЫХ В Африке
public:
    // Создает и возвращает травоядное животное для Африки - АНТИЛОПА ГНУ
    std::unique_ptr<Herbivore> CreateHerbivore() const override { return std::make_unique<Wildebeest>(); }

    // Создает и возвращает хищника для Африки - ЛЁВИКИ
    std::unique_ptr<Carnivore> CreateCarnivore() const override { return std::make_unique<Lion>(); }
};

class AmericaFactory : public ContinentFactory 
{//РЕАЛИЗАЦИЯ ИНТЕРФЕЙСА АБСТРАКТНОЙ ФАБРИКИ, КЛАСС ЭТО ФАБРИКА ДЛЯ СОЗДАНИЯ ЖИВОТНЫХ В Америке
public:
    // Создает и возвращает травоядное животное для Америки - БИЗОН
    std::unique_ptr<Herbivore> CreateHerbivore() const override { return std::make_unique<Bison>(); }
    // Создает и возвращает хищника для Америки - ВОЛК
    std::unique_ptr<Carnivore> CreateCarnivore() const override { return std::make_unique<Wolf>(); }
};

class EurasiaFactory : public ContinentFactory 
{//РЕАЛИЗАЦИЯ ИНТЕРФЕЙСА АБСТРАКТНОЙ ФАБРИКИ, КЛАСС ЭТО ФАБРИКА ДЛЯ СОЗДАНИЯ ЖИВОТНЫХ В Евразии
public:
    
    // Создает и возвращает травоядное животное для Евразии - ЛОСЬ
    std::unique_ptr<Herbivore> CreateHerbivore() const override { return std::make_unique<Elk>(); }
    // Создает и возвращает хищника для Евразии - ТИГР
    std::unique_ptr<Carnivore> CreateCarnivore() const override { return std::make_unique<Tiger>(); }
};


class AnimalWorld 
{//"МИР ЖИВОТНЫХ", то есть клиентский код взаимодействует с этим классом
public:
    // Метод для питания травоядных животных.
    void NutritionHerbivores(Herbivore *herbivore) { herbivore->EatGrass(); } // Травоядные питаются травой

    // Метод для питания хищников.
    void NutritionCarnivores(Carnivore *carnivore, Herbivore *herbivore) { carnivore->Eat(herbivore); } // Хищники охотятся на травоядных
};


void simulateContinent(const ContinentFactory &factory, const std::string &continentName) 
{//СОЗДАНИЕ ОБЬЕКТОВ КОНТИНЕНТА БЛАГОДАРЯ  !!АБСТРАКТНОЙ ФАБРИКИ!!
    AnimalWorld world;
    
    auto herbivore = factory.CreateHerbivore();
    auto carnivore = factory.CreateCarnivore();
    
    world.NutritionHerbivores(herbivore.get());
    world.NutritionCarnivores(carnivore.get(), herbivore.get());
    
    std::cout << "Continent: " << continentName << std::endl;
    std::cout << "Herbivore: " << herbivore->GetName() << ", Weight: " << herbivore->GetWeight() << ", Alive: " << std::boolalpha << herbivore->IsAlive() << std::endl;
    std::cout << "Carnivore: " << carnivore->GetName() << ", Power: " << carnivore->GetPower() << std::endl << std::endl;
}


int main() 
{
    //СОЗДАЮТСЯ ФАБРИКИ ИЗ 3 КОНТИНЕНТОВ

    std::unique_ptr<ContinentFactory> africaFactory = std::make_unique<AfricaFactory>();
    std::unique_ptr<ContinentFactory> americaFactory = std::make_unique<AmericaFactory>();
    std::unique_ptr<ContinentFactory> eurasiaFactory = std::make_unique<EurasiaFactory>();

    //для того что бы показать
    simulateContinent(*africaFactory, "Africa");
    simulateContinent(*americaFactory, "America");
    simulateContinent(*eurasiaFactory, "Eurasia");

    return 0;
}
