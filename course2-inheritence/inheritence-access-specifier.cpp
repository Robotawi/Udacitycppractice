// This example demonstrates the privacy levels
// between parent and child classes
// Access the methods of the parent inside the child and in the main function
#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    int wheels = 0;
    string color = "blue";

    void Wheels(int w){this->wheels = w;}

    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
    }
};


class Car : public Vehicle {
public:
    bool sunroof = false;
};

class Bicycle : protected Vehicle {
public:
    bool kickstand = true;
    void Wheels(int w){this->wheels = w; Print();}
};

class Scooter : private Vehicle {
public:
    bool electric = false;
    void Wheels(int w){this->wheels = w; Print();}

};

int main()
{
    Car car;
    car.wheels = 4;

    Bicycle bicycle;
    bicycle.Wheels(2);


    Scooter scooter;
    scooter.Wheels(1);
};