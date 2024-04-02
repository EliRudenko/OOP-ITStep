#include <iostream>
#include <string>

class Profession 
{
protected:
    int attack;
    int speed;
    int health;
    int defense;
    std::string modifiers;
public:
    Profession(int att, int spd, int hlth, int def, const std::string& mod) : attack(att), speed(spd), health(hlth), defense(def), modifiers(mod) {}
    virtual ~Profession() {}
    virtual int GetAttack() { return attack; }
    virtual int GetSpeed() { return speed; }
    virtual int GetHealth() { return health; }
    virtual int GetDefense() { return defense; }
    virtual std::string GetModifiers() { return modifiers; }
};

class ProfessionDecorator : public Profession 
{
protected:
    Profession *profession;
public:
    ProfessionDecorator(Profession *prof, int att, int spd, int hlth, int def, const std::string& mod) : Profession(att, spd, hlth, def, mod), profession(prof) {}
    virtual ~ProfessionDecorator() { delete profession; }
    virtual int GetAttack() { return profession->GetAttack() + attack; }
    virtual int GetSpeed() { return profession->GetSpeed() + speed; }
    virtual int GetHealth() { return profession->GetHealth() + health; }
    virtual int GetDefense() { return profession->GetDefense() + defense; }
    virtual std::string GetModifiers() { return profession->GetModifiers() + ", " + modifiers; }
};

// Конкретные декораторы
class WarriorDecorator : public ProfessionDecorator 
{
public:
    WarriorDecorator(Profession *prof) : ProfessionDecorator(prof, 20, 10, 50, 20, "from profession 'Warrior'") {}
};

class SwordsmanDecorator : public ProfessionDecorator 
{
public:
    SwordsmanDecorator(Profession *prof) : ProfessionDecorator(prof, 40, -10, 0, 40, "from profession 'Swordsman'") {}
};

class ArcherDecorator : public ProfessionDecorator 
{
public:
    ArcherDecorator(Profession *prof) : ProfessionDecorator(prof, 20, 20, 0, 10, "from profession 'Archer'") {}
};

class RiderDecorator : public ProfessionDecorator
{
public:
    RiderDecorator(Profession *prof) : ProfessionDecorator(prof, -10, 40, 200, 100, "from profession 'Rider'") {}
};

class MageDecorator : public ProfessionDecorator 
{
public:
    MageDecorator(Profession *prof) : ProfessionDecorator(prof, 0, 0, 0, 0, "") {}
};



class EvilMageDecorator : public MageDecorator 
{
public:
    EvilMageDecorator(Profession *prof) : MageDecorator(prof) 
    {
        attack = 70;
        speed = 20;
        modifiers = "from profession 'Evil Mage'";
    }
};

class GoodMageDecorator : public MageDecorator 
{
public:
    GoodMageDecorator(Profession *prof) : MageDecorator(prof) 
    {
        attack = 50;
        speed = 30;
        health = 100;
        defense = 30;
        modifiers = "from profession 'Good Mage'";
    }
};



// Конкретные профессии
class Human : public Profession 
{
public:
    Human() : Profession(20, 20, 150, 0, "from base profession") {}
};



class HumanWarrior : public WarriorDecorator 
{
public:
    HumanWarrior() : WarriorDecorator(new Human()) {}
};

class Swordsman : public SwordsmanDecorator 
{
public:
    Swordsman() : SwordsmanDecorator(new HumanWarrior()) {}
};

class Archer : public ArcherDecorator 
{
public:
    Archer() : ArcherDecorator(new HumanWarrior()) {}
};

class Horseman : public RiderDecorator 
{
public:
    Horseman() : RiderDecorator(new Swordsman()) {}
};


class Elf : public Profession 
{
public:
    Elf() : Profession(15, 30, 100, 0, "from base profession") {}
};


class ElvenWarrior : public WarriorDecorator 
{
public:
    ElvenWarrior() : WarriorDecorator(new Elf()) {}
};

class ElvenMage : public GoodMageDecorator
{
public:
    ElvenMage() : GoodMageDecorator(new Elf()) {}
};

class Crossbowman : public ArcherDecorator 
{
public:
    Crossbowman() : ArcherDecorator(new ElvenWarrior()) {}
};

class EvilMage : public EvilMageDecorator 
{
public:
    EvilMage() : EvilMageDecorator(new ElvenMage()) {}
};

class GoodMage : public GoodMageDecorator 
{
public:
    GoodMage() : GoodMageDecorator(new ElvenMage()) {}
};



int main() 
{
    // Экземпляры всех профессий
    Human human;
    HumanWarrior humanWarrior;
    Swordsman swordsman;
    Archer archer;
    Horseman horseman;
    Elf elf;
    ElvenWarrior elvenWarrior;
    ElvenMage elvenMage;
    Crossbowman crossbowman;
    EvilMage evilMage;
    GoodMage goodMage;

    std::cout << "Human:" << std::endl;
    std::cout << "Attack: " << human.GetAttack() << ", Speed: " << human.GetSpeed() << ", Health: " << human.GetHealth() << ", Defense: " << human.GetDefense() << std::endl;
    std::cout << "Modifiers: " << human.GetModifiers() << std::endl;

    std::cout << std::endl;
    std::cout << "Human Warrior:" << std::endl;
    std::cout << "Attack: " << humanWarrior.GetAttack() << ", Speed: " << humanWarrior.GetSpeed() << ", Health: " << humanWarrior.GetHealth() << ", Defense: " << humanWarrior.GetDefense() << std::endl;
    std::cout << "Modifiers: " << humanWarrior.GetModifiers() << std::endl;

    std::cout << std::endl;
    std::cout << "Swordsman:" << std::endl;
    std::cout << "Attack: " << swordsman.GetAttack() << ", Speed: " << swordsman.GetSpeed() << ", Health: " << swordsman.GetHealth() << ", Defense: " << swordsman.GetDefense() << std::endl;
    std::cout << "Modifiers: " << swordsman.GetModifiers() << std::endl;

    std::cout << std::endl;
    std::cout << "Archer:" << std::endl;
    std::cout << "Attack: " << archer.GetAttack() << ", Speed: " << archer.GetSpeed() << ", Health: " << archer.GetHealth() << ", Defense: " << archer.GetDefense() << std::endl;
    std::cout << "Modifiers: " << archer.GetModifiers() << std::endl;

    std::cout << std::endl;
    std::cout << "Horseman:" << std::endl;
    std::cout << "Attack: " << horseman.GetAttack() << ", Speed: " << horseman.GetSpeed() << ", Health: " << horseman.GetHealth() << ", Defense: " << horseman.GetDefense() << std::endl;
    std::cout << "Modifiers: " << horseman.GetModifiers() << std::endl;

    std::cout << std::endl;
    std::cout << "Elf:" << std::endl;
    std::cout << "Attack: " << elf.GetAttack() << ", Speed: " << elf.GetSpeed() << ", Health: " << elf.GetHealth() << ", Defense: " << elf.GetDefense() << std::endl;
    std::cout << "Modifiers: " << elf.GetModifiers() << std::endl;

    std::cout << std::endl;
    std::cout << "Elven Warrior:" << std::endl;
    std::cout << "Attack: " << elvenWarrior.GetAttack() << ", Speed: " << elvenWarrior.GetSpeed() << ", Health: " << elvenWarrior.GetHealth() << ", Defense: " << elvenWarrior.GetDefense() << std::endl;
    std::cout << "Modifiers: " << elvenWarrior.GetModifiers() << std::endl;

    std::cout << std::endl;
    std::cout << "Elven Mage:" << std::endl;
    std::cout << "Attack: " << elvenMage.GetAttack() << ", Speed: " << elvenMage.GetSpeed() << ", Health: " << elvenMage.GetHealth() << ", Defense: " << elvenMage.GetDefense() << std::endl;
    std::cout << "Modifiers: " << elvenMage.GetModifiers() << std::endl;

    std::cout << std::endl;
    std::cout << "Crossbowman:" << std::endl;
    std::cout << "Attack: " << crossbowman.GetAttack() << ", Speed: " << crossbowman.GetSpeed() << ", Health: " << crossbowman.GetHealth() << ", Defense: " << crossbowman.GetDefense() << std::endl;
    std::cout << "Modifiers: " << crossbowman.GetModifiers() << std::endl;

    std::cout << std::endl;
    std::cout << "Evil Mage:" << std::endl;
    std::cout << "Attack: " << evilMage.GetAttack() << ", Speed: " << evilMage.GetSpeed() << ", Health: " << evilMage.GetHealth() << ", Defense: " << evilMage.GetDefense() << std::endl;
    std::cout << "Modifiers: " << evilMage.GetModifiers() << std::endl;

    std::cout << std::endl;
    std::cout << "Good Mage:" << std::endl;
    std::cout << "Attack: " << goodMage.GetAttack() << ", Speed: " << goodMage.GetSpeed() << ", Health: " << goodMage.GetHealth() << ", Defense: " << goodMage.GetDefense() << std::endl;
    std::cout << "Modifiers: " << goodMage.GetModifiers() << std::endl;
    std::cout << std::endl;

    return 0;
}
