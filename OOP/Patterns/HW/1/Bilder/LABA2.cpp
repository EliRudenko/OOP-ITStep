#include <iostream>
#include <string>

using namespace std;

class Pizza
{
    string dough;
    string sauce;
    string topping;
public:
    void SetDough(string dough)
    {
        this->dough = dough;
    }
    string GetDough()
    {
        return this->dough;
    }
    void SetSauce(string sauce)
    {
        this->sauce = sauce;
    }
    string GetSauce()
    {
        return this->sauce;
    }
    void SetTopping(string topping)
    {
        this->topping = topping;
    }
    string GetTopping()
    {
        return this->topping;
    }
    void ShowPizza()
    {
        cout << " Yummy! Pizza with Dough as " + dough + ", Sauce as " + sauce + " and Topping as " + topping +"\n";
    }
};

class PizzaBuilder
{
protected:
    Pizza pizza;
public:
    Pizza GetPizza()
    {
        return pizza;
    }
    virtual void BuildDough() = 0;
    virtual void BuildSauce() = 0;
    virtual void BuildTopping() = 0;
};

class HawaiianPizzaBuilder: public PizzaBuilder
{
public:
    void BuildDough() override
    {
        pizza.SetDough("thin");
    }
    void BuildSauce() override
    {
        pizza.SetSauce("mild");
    }
    void BuildTopping() override
    {
        pizza.SetTopping("ham+pineapple");
    }
};

class SpicyPizzaBuilder: public PizzaBuilder
{
public:
    void BuildDough() override
    {
        pizza.SetDough("thick");
    }
    void BuildSauce() override
    {
        pizza.SetSauce("hot");
    }
    void BuildTopping() override
    {
        pizza.SetTopping("pepperoni+salami");
    }
};

class PepperoniPizzaBuilder: public PizzaBuilder
{
public:
    void BuildDough() override
    {
        pizza.SetDough("thick");
    }
    void BuildSauce() override
    {
        pizza.SetSauce("spicy");
    }
    void BuildTopping() override
    {
        pizza.SetTopping("pepperoni");
    }
};

class Waiter
{
    PizzaBuilder *pizzaBuilder;
public:
    void SetPizzaBuilder(PizzaBuilder* pb)
    {
        pizzaBuilder = pb;
    }
    Pizza GetPizza()
    {
        return pizzaBuilder->GetPizza();
    }
    void ConstructPizza()
    {
        pizzaBuilder->BuildDough();
        pizzaBuilder->BuildSauce();
        pizzaBuilder->BuildTopping();
    }
};

int main()
{
    Waiter waiter;
    PizzaBuilder *builder = new HawaiianPizzaBuilder();
    waiter.SetPizzaBuilder(builder);
    waiter.ConstructPizza();
    Pizza pizza = waiter.GetPizza();
    pizza.ShowPizza();
    delete builder;

    builder = new SpicyPizzaBuilder();
    waiter.SetPizzaBuilder(builder);
    waiter.ConstructPizza();
    pizza = waiter.GetPizza();
    pizza.ShowPizza();
    delete builder;

    builder = new PepperoniPizzaBuilder();
    waiter.SetPizzaBuilder(builder);
    waiter.ConstructPizza();
    pizza = waiter.GetPizza();
    pizza.ShowPizza();
    delete builder;

    system("pause");
    return 0;
}
