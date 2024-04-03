#include <iostream>
#include <map>
#include <memory>

// Приспособленец = Character !!!
//объявляет интерфейс, с помощью которого 
//приспособленцы могут получать внешнее состояние
class Character 
{
public:
    virtual void Show(int positionX, int positionY) = 0;
};

// Конкретные приспособленцы = боевые единицы !!!
class LightInfantry : public Character 
{
private:
    int speed;
    int strength;

public:
    LightInfantry() : speed(20), strength(10) {} //конструктор

    void Show(int positionX, int positionY) override 
    {
        std::cout << "Displaying Light Infantry at position (" << positionX << ", " << positionY << ")" << std::endl;
        std::cout << "Speed: " << speed << ", Strength: " << strength << std::endl;
    }
};

class TransportVehicle : public Character 
{
private:
    int speed;
    int strength;

public:
    TransportVehicle() : speed(70), strength(0) {}

    void Show(int positionX, int positionY) override 
    {
        std::cout << "Displaying Transport Vehicle at position (" << positionX << ", " << positionY << ")" << std::endl;
        std::cout << "Speed: " << speed << ", Strength: " << strength << std::endl;
    }
};

class HeavyGroundEquipment : public Character 
{
private:
    int speed;
    int strength;

public:
    HeavyGroundEquipment() : speed(15), strength(150) {}

    void Show(int positionX, int positionY) override 
    {
        std::cout << "Displaying Heavy Ground Equipment at position (" << positionX << ", " << positionY << ")" << std::endl;
        std::cout << "Speed: " << speed << ", Strength: " << strength << std::endl;
    }
};

class LightGroundEquipment : public Character 
{
private:
    int speed;
    int strength;

public:
    LightGroundEquipment() : speed(50), strength(30) {}

    void Show(int positionX, int positionY) override 
    {
        std::cout << "Displaying Light Ground Equipment at position (" << positionX << ", " << positionY << ")" << std::endl;
        std::cout << "Speed: " << speed << ", Strength: " << strength << std::endl;
    }
};

class Aircraft : public Character 
{
private:
    int speed;
    int strength;

public:
    Aircraft() : speed(300), strength(100) {}

    void Show(int positionX, int positionY) override 
    {
        std::cout << "Displaying Aircraft at position (" << positionX << ", " << positionY << ")" << std::endl;
        std::cout << "Speed: " << speed << ", Strength: " << strength << std::endl;
    }
};



// Фабрика приспособленцев !!!!!
class CharacterFactory 
{
private:
    std::map<std::string, std::unique_ptr<Character>> characters; //хранение созданных боевых единиц

public:
    Character* GetCharacter(const std::string& key) 
    {//получение боевых единиц по ключу
        if (characters.find(key) == characters.end()) { characters[key] = createCharacter(key); } //проверка создана ли уже боевая единица, создание если не создана раньше
        return characters[key].get(); //возвращаеся указатель на боевую единицу
    }
private:
    std::unique_ptr<Character> createCharacter(const std::string& key) 
    {//создание боевлй единицы по ключу
        if (key == "Inf") 
            return std::make_unique<LightInfantry>();
        else if (key == "Trans") 
            return std::make_unique<TransportVehicle>();
        else if (key == "Heavy") 
            return std::make_unique<HeavyGroundEquipment>();
        else if (key == "Light") 
            return std::make_unique<LightGroundEquipment>();
        else if (key == "Air") 
            return std::make_unique<Aircraft>();
    
        return nullptr; 
    }
};

int main() 
{
    CharacterFactory characterFactory;
    int positionX = 10;
    int positionY = 20;

    //создаются конкретные боевые единицы, вывод
    Character* infantry = characterFactory.GetCharacter("Inf");
    infantry->Show(positionX, positionY);
    
    std::cout << std::endl;
    Character* vehicle = characterFactory.GetCharacter("Trans");
    vehicle->Show(positionX + 30, positionY + 30);
    
    std::cout << std::endl;
    Character* heavyEquipment = characterFactory.GetCharacter("Heavy");
    heavyEquipment->Show(positionX + 60, positionY + 60);
    
    std::cout << std::endl;
    Character* lightEquipment = characterFactory.GetCharacter("Light");
    lightEquipment->Show(positionX + 90, positionY + 90);
    
    std::cout << std::endl;
    Character* aircraft = characterFactory.GetCharacter("Air");
    aircraft->Show(positionX + 120, positionY + 120);
    
    std::cout << std::endl;
    return 0;
}
