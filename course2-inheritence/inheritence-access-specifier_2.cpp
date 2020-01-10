// This example demonstrates the privacy levels
// between parent and child classes
// Access the methods of the parent inside the child and in the main function
#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
    }

private:
    int wheels = 0;
    string color = "blue";
};


class Car : public Vehicle {
public:
    bool sunroof = false;
    void Wheels()
};

class Bicycle : protected Vehicle {
public:
    bool kickstand = true;
};

class Scooter : private Vehicle {
public:
    bool electric = false;
};

int main()
{
    Car car;
    car.wheels = 4;

    //Bicycle bicycle;
    //bicycle.wheels = 2;

    //Scooter scooter;
    //scooter.wheels = 2;

};