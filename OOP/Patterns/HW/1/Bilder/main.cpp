#include <iostream>
#include <string>

class Car 
{
public:
    std::string engine;
    std::string body;
    int horsepower;
    int wheels;
    std::string transmission;

    void display() 
    {

        std::cout << "Car Specifications:\n";
        std::cout << std::endl;
        std::cout << "Engine: " << engine << std::endl;
        std::cout << "Body: " << body << std::endl;
        std::cout << "Horsepower: " << horsepower << std::endl;
        std::cout << "Wheels: " << wheels << std::endl;
        std::cout << "Transmission: " << transmission << std::endl;
        std::cout << std::endl;
    }
};

class CarBuilder
{
protected:
    Car car;
public:
    virtual void buildEngine() = 0;
    virtual void buildBody() = 0;
    virtual void buildHorsepower() = 0;
    virtual void buildWheels() = 0;
    virtual void buildTransmission() = 0;
    
    Car getCar() { return car; }
};

class DaewooLanosBuilder : public CarBuilder 
{
public:
    void buildEngine() override { car.engine = "Daewoo Lanos"; }
    
    void buildBody() override { car.body = "Sedan"; }
    
    void buildHorsepower() override { car.horsepower = 98; }
    
    void buildWheels() override { car.wheels = 13; }
    
    void buildTransmission() override { car.transmission = "5 Manual"; }
};

class FordProbeBuilder : public CarBuilder 
{
public:
    void buildEngine() override { car.engine = "Ford Probe"; }
    
    void buildBody() override { car.body = "Coupe"; }
    
    void buildHorsepower() override { car.horsepower = 160; }
    
    void buildWheels() override { car.wheels = 14; }
    
    void buildTransmission() override { car.transmission = "4 Auto"; }
};

class UazPatriotBuilder : public CarBuilder 
{
public:
    void buildEngine() override { car.engine = "UAZ Patriot"; }
    
    void buildBody() override { car.body = "Universal"; }
    
    void buildHorsepower() override { car.horsepower = 120; }
    
    void buildWheels() override { car.wheels = 16; }
    
    void buildTransmission() override { car.transmission = "4 Manual"; }
};

class HyundaiGetzBuilder : public CarBuilder 
{
public:
    void buildEngine() override { car.engine = "Hyundai Getz"; }
    
    void buildBody() override { car.body = "Hatchback"; }

    void buildHorsepower() override { car.horsepower = 66; }

    void buildWheels() override { car.wheels = 13; }
    
    void buildTransmission() override { car.transmission = "4 Auto"; }
};


class Shop 
{
public:
    CarBuilder* carBuilder;

    void setCarBuilder(CarBuilder* builder) { carBuilder = builder; }

    Car buildCar() 
    {
        carBuilder->buildEngine();
        carBuilder->buildBody();
        carBuilder->buildHorsepower();
        carBuilder->buildWheels();
        carBuilder->buildTransmission();
        return carBuilder->getCar();
    }
};

int main() 
{
    Shop shop;
    
    DaewooLanosBuilder daewooBuilder;
    shop.setCarBuilder(&daewooBuilder);
    Car daewooLanos = shop.buildCar();
    daewooLanos.display();
    
    FordProbeBuilder fordBuilder;
    shop.setCarBuilder(&fordBuilder);
    Car fordProbe = shop.buildCar();
    fordProbe.display();
     
    UazPatriotBuilder uazBuilder;
    shop.setCarBuilder(&uazBuilder);
    Car uazPatriot = shop.buildCar();
    uazPatriot.display();
    
    HyundaiGetzBuilder hyundaiBuilder;
    shop.setCarBuilder(&hyundaiBuilder);
    Car hyundaiGetz = shop.buildCar();
    hyundaiGetz.display();
    
    return 0;
}
