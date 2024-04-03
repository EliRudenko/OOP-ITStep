#include <iostream>
#include <map>
using namespace std;

// Приспособленец (Character) - объявляет интерфейс, с помощью которого приспособленцы могут получать внешнее состояние.
class Character {
public:
    virtual void Show(int positionX, int positionY) = 0;
};

// Конкретные приспособленцы (боевые единицы)
class LightInfantry : public Character {
private:
    char symbol;
    int speed;
    int strength;

public:
    LightInfantry() : symbol('A'), speed(20), strength(10) {}

    void Show(int positionX, int positionY) override {
        cout << "Displaying Light Infantry at position (" << positionX << ", " << positionY << ")" << endl;
        cout << "Speed: " << speed << ", Strength: " << strength << endl;
    }
};

class TransportVehicle : public Character {
private:
    char symbol;
    int speed;
    int strength;

public:
    TransportVehicle() : symbol('B'), speed(70), strength(0) {}

    void Show(int positionX, int positionY) override {
        cout << "Displaying Transport Vehicle at position (" << positionX << ", " << positionY << ")" << endl;
        cout << "Speed: " << speed << ", Strength: " << strength << endl;
    }
};

// Фабрика приспособленцев
class CharacterFactory {
private:
    map<char, Character*> characters;

public:
    Character* GetCharacter(char key) {
        Character* character = characters[key];
        if (!character) {
            switch (key) {
                case 'A':
                    character = new LightInfantry();
                    break;
                case 'B':
                    character = new TransportVehicle();
                    break;
                // Добавьте создание остальных типов боевых единиц по аналогии
            }
            characters[key] = character;
        }
        return character;
    }
};

int main() {
    CharacterFactory characterFactory;
    int positionX = 10;
    int positionY = 20;

    // Создание и отображение конкретных боевых единиц
    Character* infantry = characterFactory.GetCharacter('A');
    infantry->Show(positionX, positionY);

    Character* vehicle = characterFactory.GetCharacter('B');
    vehicle->Show(positionX + 30, positionY + 30);

    return 0;
}
