#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Component {
public:
    virtual ~Component() {}
    virtual void Add(Component* c) { cout << "Cannot add to file\n"; }
    virtual void Remove(Component* c) { cout << "Cannot remove from file\n"; }
    virtual void Display(int depth) = 0;
    virtual double GetPrice() const { return 0.0; }
};

class Composite : public Component {
    vector<Component*> components;
public:
    void Add(Component* component) override {
        components.push_back(component);
    }
    void Remove(Component* component) override {
        auto iter = find(components.begin(), components.end(), component);
        components.erase(iter);
    }
    void Display(int depth) override {
        string s(depth, '-');
        cout << s + "Composite" << endl;
        for (Component* component : components) {
            component->Display(depth + 2);
        }
    }
    vector<Component*> GetComponents() const {
        return components;
    }
};

class Leaf : public Component {
    string name;
    double price;
public:
    Leaf(string name, double price) : name(name), price(price) {}
    void Display(int depth) override {
        string s(depth, '-');
        cout << s + name << " $" << price << endl;
    }
    double GetPrice() const override { return price; }
};

Component* createLeaf(string name, double price) {
    return new Leaf(name, price);
}

Component* createComposite(string name, double price) {
    return new Composite();
}

int main() {
    Component* root = createComposite("Office Supplies", 0);

    // Adding components for the Reception
    Component* reception = createComposite("Reception", 0);
    reception->Add(createComposite("Warm Colors", 0));
    reception->Add(createLeaf("Magazine Table", 50));
    reception->Add(createLeaf("Sofa", 200));
    reception->Add(createLeaf("Secretary Desk", 150));
    reception->Add(createLeaf("Water Cooler", 100));
    root->Add(reception);

    // Adding components for Classroom 1
    Component* classroom1 = createComposite("Classroom 1", 0);
    classroom1->Add(createLeaf("Desks", 500));
    classroom1->Add(createLeaf("Blackboard", 100));
    classroom1->Add(createLeaf("Teacher's Desk", 200));
    classroom1->Add(createLeaf("Mathematicians Posters", 50));
    root->Add(classroom1);

    // Adding components for Classroom 2
    Component* classroom2 = createComposite("Classroom 2", 0);
    classroom2->Add(createLeaf("Desks (Black)", 0));
    classroom2->Add(createLeaf("Desks (Oval or Circle)", 0));
    classroom2->Add(createLeaf("Blackboard", 100));
    classroom2->Add(createLeaf("Sofa", 0));
    root->Add(classroom2);

    // Adding components for Computer Room
    Component* computerRoom = createComposite("Computer Room", 0);
    computerRoom->Add(createLeaf("Computer Desks", 0));
    computerRoom->Add(createLeaf("Computers", 0));
    computerRoom->Add(createLeaf("Sockets", 0));
    computerRoom->Add(createLeaf("Blackboard", 0));
    computerRoom->Add(createLeaf("Colorful Markers Set", 0));
    root->Add(computerRoom);

    // Adding components for Cafeteria
    Component* cafeteria = createComposite("Cafeteria", 0);
    cafeteria->Add(createLeaf("Coffee Machine", 0));
    cafeteria->Add(createComposite("Table", 0));
    cafeteria->Add(createLeaf("Chairs", 0));
    cafeteria->Add(createLeaf("Fridge", 0));
    cafeteria->Add(createLeaf("Sink", 0));
    root->Add(cafeteria);

    root->Display(0);

    // Code for calculating total cost and freeing memory
    double totalCost = 0.0;
    for (const Component* component : static_cast<const Composite*>(root)->GetComponents()) {
        totalCost += component->GetPrice();
    }
    cout << "Total cost: $" << totalCost << endl;

    delete root;

    return 0;
}
