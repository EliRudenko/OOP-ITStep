#include <iostream>
#include <string>

using namespace std;


class TravelStrategy 
{
public:
    virtual void travel() const = 0;
    virtual ~TravelStrategy() {}
};

class BicycleTravel : public TravelStrategy 
{
public:
    void travel() const override { cout << "Travel by bicycle. Cost: 0 UAH, Time: 60 minutes." << endl; }
};


class BusTravel : public TravelStrategy 
{
public:
    void travel() const override { cout << "Travel by bus. Cost: 30 UAH, Time: 40 minutes." << endl; }
};

class TaxiTravel : public TravelStrategy 
{
public:
    void travel() const override { cout << "Travel by taxi. Cost: 100 UAH, Time: 20 minutes." << endl; }
};


class AirportTransport 
{
private:
    TravelStrategy* strategy;

public:
    AirportTransport() : strategy(nullptr) {}

    void setStrategy(TravelStrategy* strategy) { this->strategy = strategy; }
    
    void goToAirport() const 
    {
        if (strategy) { strategy->travel(); } 
        else { cout << "No travel strategy selected." << endl; }
    }
};
int main() 
{
    BicycleTravel bicycle;
    BusTravel bus;
    TaxiTravel taxi;
    AirportTransport transport;

    int choice;
    cout << "Choose your transport to the airport:" << endl;
    cout << "1. Bicycle" << endl;
    cout << "2. Bus" << endl;
    cout << "3. Taxi" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    switch (choice) 
    {
        case 1:
            transport.setStrategy(&bicycle);
            break;
        case 2:
            transport.setStrategy(&bus);
            break;
        case 3:
            transport.setStrategy(&taxi);
            break;
        default:
            cout << "Invalid choice. Exiting." << endl;
            return 1;
    }
    transport.goToAirport();

    return 0;
}
