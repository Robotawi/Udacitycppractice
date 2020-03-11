//
// Created by zozo on 2/11/20.
//
#include <thread>
#include <iostream>
using std::cout; using std::endl;

class Vehicle
{
public:
    Vehicle() : _id(0) {}
    void addID(int id) { _id = id; }
    void printID()
    {
        std::cout << "Vehicle ID=" << _id << std::endl;
    }

private:
    int _id;
};


int main (){
    Vehicle v1, v2;
    std::thread t1 (&Vehicle::addID, v1, 25);
    std::thread t2 (&Vehicle::addID, &v2, 30);

    t1.join();
    t2.join();

    v1.printID();
    v2.printID();
    return 0;
}