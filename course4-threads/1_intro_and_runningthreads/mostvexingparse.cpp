//
// Created by zozo on 2/10/20.
//

#include <iostream>
#include <thread>

class Vehicle
{
public:
    void operator()()
    {
        std::cout << "Vehicle object has been created \n" << std::endl;
    }
};


int main()
{
    // create thread
//    std::thread t0(Vehicle()); // C++'s most vexing parse
    std::thread t00 = std::thread(Vehicle());
    std::thread t000 = std::thread{Vehicle()};
    std::thread t1( (Vehicle()) ); // Add an extra pair of parantheses

    std::thread t2 = std::thread( Vehicle() ); // Use copy initialization

    std::thread t3{ Vehicle() };// Use uniform initialization with braces

    // do something in main()
    std::cout << "Finished work in main \n";

    // wait for thread to finish
//    t0.join();
    t00.join();
    t000.join();

    t1.join();
    t2.join();
    t3.join();

    return 0;
}