#include <iostream>
using namespace std;

// Интерфейс транспортного средства
class ITransport 
{
public:
    virtual void Drive() = 0;
};

// Класс автомобиля
class Auto : public ITransport 
{
public:
    void Drive() override { cout << "The car drives on the road.\n"; }
};

// Класс путешественника (водителя)
class Driver {
public:
    void Travel(ITransport* transport) { transport->Drive(); }
};

// Интерфейс животного
class IAnimal 
{
public:
    virtual void Move() = 0;
};

// Класс верблюда
class Camel : public IAnimal 
{
public:
    void Move() override { cout << "Camel rides on the sands of the desert.\n"; }
};


class Horse : public IAnimal 
{
public:
    void Move() override  { cout << "Horse gallops across the field.\n"; }
};


class AnimalToTransportAdapter : public ITransport
{
    IAnimal* animal;
public:
    AnimalToTransportAdapter(IAnimal* animal) : animal(animal) {}

    void Drive() override { animal->Move(); }
};

int main() 
{
    // Путешественник
    Driver driver;

    // Автомобиль
    Auto car;
    ITransport* transport = &car;
    driver.Travel(transport); // отправляемся в путешествие на автомобиле

    // Встретились пески, необходимо использовать верблюда
    Camel camel;
    AnimalToTransportAdapter camelAdapter(&camel);
    transport = &camelAdapter;
    driver.Travel(transport); // продолжаем путь по пескам пустыни на верблюде

    //использовать лошадь
    Horse horse;
    AnimalToTransportAdapter horseAdapter(&horse);
    transport = &horseAdapter;
    driver.Travel(transport); // продолжаем путь по полям на лошади

    system("pause");
    return 0;
}
