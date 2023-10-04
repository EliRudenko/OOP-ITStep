
#include "Transport.h"

class Plane : public Transport 
{
private:
    std::string name;
    int passengerCapacity;

public:
    Plane(double speed = 0, double volume = 0, std::string fuelType = "", std::string name = "", int passengerCapacity = 0);

    void display() const;

    std::string getName() const;
    void setName(std::string name);
    int getPassengerCapacity() const;
    void setPassengerCapacity(int passengerCapacity);
    
    void Input();
};
