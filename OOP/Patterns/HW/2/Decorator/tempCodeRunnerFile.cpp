#include <iostream>
#include <string>
using namespace std;

class Profession {
public:
    virtual int GetAttack() = 0;
    virtual int GetSpeed() = 0;
    virtual int GetHealth() = 0;
    virtual int GetDefense() = 0;
};

class BaseProfession : public Profession {
protected:
    int attack;
    int speed;
    int health;
    int defense;

public:
    BaseProfession(int atk, int spd, int hp, int def) : attack(atk), speed(spd), health(hp), defense(def) {}

    int GetAttack() override { return attack; }
    int GetSpeed() override { return speed; }
    int GetHealth() override { return health; }
    int GetDefense() override { return defense; }
};

class ProfessionDecorator : public Profession {
protected:
    Profession *profession;

public:
    ProfessionDecorator(Profession *prof) : profession(prof) {}

    int GetAttack() override { return profession->GetAttack(); }
    int GetSpeed() override { return profession->GetSpeed(); }
    int GetHealth() override { return profession->GetHealth(); }
    int GetDefense() override { return profession->GetDefense(); }
};

class AttackDecorator : public ProfessionDecorator {
protected:
    int attackModifier;

public:
    AttackDecorator(Profession *prof, int modifier) : ProfessionDecorator(prof), attackModifier(modifier) {}

    int GetAttack() override { return profession->GetAttack() + attackModifier; }
};

class Archer : public ProfessionDecorator {
public:
    Archer(Profession *prof) : ProfessionDecorator(prof) {}

    int GetAttack() override { return profession->GetAttack() + 20; }
    int GetSpeed() override { return profession->GetSpeed() + 20; }
    int GetHealth() override { return profession->GetHealth(); }
    int GetDefense() override { return profession->GetDefense(); }
};

// Define Human class
class Human : public BaseProfession {
public:
    Human() : BaseProfession(20, 20, 150, 0) {}
};

class Warrior : public AttackDecorator {
public:
    Warrior(Profession *prof) : AttackDecorator(prof, 20) {}
};

int main() {
    Profession *human = new Human();
    cout << "Human: Attack=" << human->GetAttack() << ", Speed=" << human->GetSpeed() << ", Health=" << human->GetHealth() << ", Defense=" << human->GetDefense() << endl;

    Profession *warrior = new Warrior(new Human());
    cout << "Warrior: Attack=" << warrior->GetAttack() << ", Speed=" << warrior->GetSpeed() << ", Health=" << warrior->GetHealth() << ", Defense=" << warrior->GetDefense() << endl;

    Profession *archer = new Archer(new Warrior(new Human()));
    cout << "Archer: Attack=" << archer->GetAttack() << ", Speed=" << archer->GetSpeed() << ", Health=" << archer->GetHealth() << ", Defense=" << archer->GetDefense() << endl;

    return 0;
}
