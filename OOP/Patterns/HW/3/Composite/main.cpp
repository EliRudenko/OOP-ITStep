#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Component 
{
protected:
    string name;
    double price;
public:
    Component(string name, double price) : name(name), price(price) {}
    virtual double GetPrice() const { return price; }
    virtual void Display(int depth) const = 0;
};

class Composite : public Component 
{
private:
    vector<Component*> components;
public:
    Composite(string name, double price) : Component(name, price) {}

    void Add(Component* component) { components.push_back(component); }

    double GetPrice() const override 
    {
        double total_price = price;
        for (const auto& component : components) { total_price += component->GetPrice(); }
        return total_price;
    }

    void Display(int depth) const override 
    {
        cout << string(depth, '\t') << name << " $" << price << endl;
        for (const auto& component : components) { component->Display(depth + 1); }
    }
};


class Leaf : public Component 
{
public:
    Leaf(string name, double price) : Component(name, price) {}

    void Display(int depth) const override { cout << string(depth, '\t') << name << " $" << price << endl; }
};

int main() 
{
    Composite* reception = new Composite("Reception", 0);
    reception->Add(new Leaf("Should be done in warm colors", 0));
    Composite* journalTable = new Composite("Journal table", 0);
    journalTable->Add(new Leaf("10-20 magazines like 'computer world'", 10));
    reception->Add(journalTable);
    reception->Add(new Leaf("Soft couch", 500));
    Composite* secretaryDesk = new Composite("Secretary's desk", 0);
    secretaryDesk->Add(new Leaf("Computer", 1500));
    secretaryDesk->Add(new Leaf("Office tools", 200));
    reception->Add(secretaryDesk);
    reception->Add(new Leaf("Cooler with warm and cold water", 300));

    Composite* classroom1 = new Composite("Classroom 1", 0);
    classroom1->Add(new Leaf("10 tables", 2000));
    classroom1->Add(new Leaf("Blackboard", 500));
    Composite* teacherDesk = new Composite("Teacher's desk", 0);
    teacherDesk->Add(new Leaf("Computer", 1500));
    classroom1->Add(teacherDesk);
    classroom1->Add(new Leaf("Posters of great mathematicians", 100));

    Composite* classroom2 = new Composite("Classroom 2", 0);
    classroom2->Add(new Leaf("20 tables", 4000));
    Composite* ovalTables = new Composite("Black tables set in oval or circle", 0);
    ovalTables->Add(new Leaf("Black tables", 2000));
    ovalTables->Add(new Leaf("Tables set in oval or circle", 3000));
    classroom2->Add(ovalTables);
    classroom2->Add(new Leaf("Blackboard", 500));
    classroom2->Add(new Leaf("Soft couch", 500));

    Composite* computerRoom = new Composite("Computer room", 0);
    computerRoom->Add(new Leaf("10 computer desks", 5000));
    Composite* computers = new Composite("Computer on each desk", 0);
    computers->Add(new Leaf("Processor 2.2GHz", 1000));
    computers->Add(new Leaf("80GB hard drive", 300));
    computers->Add(new Leaf("1024MB RAM", 200));
    computerRoom->Add(computers);
    computerRoom->Add(new Leaf("Socket near each desk", 50));
    computerRoom->Add(new Leaf("Blackboard", 500));
    computerRoom->Add(new Leaf("Set of multicolored markers", 20));

    Composite* cafeteria = new Composite("Cafeteria", 0);
    cafeteria->Add(new Leaf("Coffee machine", 1000));
    Composite* table = new Composite("Table", 0);
    table->Add(new Leaf("4 chairs", 200));
    cafeteria->Add(table);
    cafeteria->Add(new Leaf("Refrigerator", 1500));
    cafeteria->Add(new Leaf("Washbasin", 300));

    Composite* root = new Composite("Components", 0);
    root->Add(reception);
    root->Add(classroom1);
    root->Add(classroom2);
    root->Add(computerRoom);
    root->Add(cafeteria);

    root->Display(0);
    cout << "Total Price: $" << root->GetPrice() << endl;

    delete root;

    return 0;
}
