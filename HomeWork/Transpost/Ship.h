
#include "Transport.h"


class Ship : public Transport 
{
private:
    std::string name;
    int cargoCapacity;

public:
    Ship(double speed = 0, double volume = 0, std::string fuelType = "", std::string name = "", int cargoCapacity = 0);

    void display() const;
    
    std::string getName() const;
    void setName(std::string name);
    int getCargoCapacity() const;
    void setCargoCapacity(int cargoCapacity);

    void Input();
};

