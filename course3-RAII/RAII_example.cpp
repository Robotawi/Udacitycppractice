//
// Created by zozo on 1/17/20.
//
#include <iostream>

class MyDouble
{
    double *_p; // pointer to heap data
public:
    MyDouble(double *p = NULL) { _p = p; }
    ~MyDouble()
    {
        std::cout << "resource " << *_p << " deallocated" << std::endl;
        delete _p;
    }
    double &operator*() { return *_p; } // // overload dereferencing operator
};

int main()
{
    double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    for (size_t i = 0; i < 5; ++i)
    {
        // allocate the resource on the stack
        MyDouble en(new double(i));

        // use the resource
        std::cout << *en << "/" << den[i] << " = " << *en / den[i] << std::endl;
    }

    return 0;
}