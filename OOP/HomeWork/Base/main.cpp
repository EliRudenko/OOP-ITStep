#include "Base.cpp"
#include "Vehicle.cpp"
#include "Bus.cpp"
#include "Truck.cpp"

int main() 
{
    Base base;
    Vehicle car(&base, 80.0, 20.0);

    Bus bus(&base, 20, 80, 280.0, 628.0);
    Truck truck(&base, 60.0, 28.0, 86.0, 828.0);

    car.arrive();
    bus.arrive();
    truck.arrive();

    base.printStats();

    car.leave();
    bus.leave();
    truck.leave();

    base.printStats();

    return 0;
}

