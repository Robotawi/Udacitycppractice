//
// Created by zozo on 2/11/20.
//

#include <iostream>
#include <thread>
#include <string>
class Vehicle
{
public:
    Vehicle() : _id(0) {}
    void addID(int id) { _id = id; }
    void setName(std::string name) {_name = name; }
    void printID()
    {
        std::cout << "Vehicle ID=" << _id << std::endl;
    }
    void printName(){
        std::cout << "Vehicle name is " << _name << std::endl;
    }
    // TODO: Modify the Vehicle class as indicated in the instructions on the left.
private:
    int _id;
    std::string _name;
};

int main()
{
    // create thread
    std::shared_ptr<Vehicle> v(new Vehicle);
    std::thread t (&Vehicle::addID, v, 1); // call member function on object v

    std::thread t2 (&Vehicle::setName, v, "Madam carah");
    // TODO: Modify the main to start setName as a thread.
    // Also, add code to main to print the name of the vehicle.

    // wait for thread to finish
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // print Vehicle id
    v->printID();
    v->printName();

    t.join();
    t2.join();

    return 0;
}