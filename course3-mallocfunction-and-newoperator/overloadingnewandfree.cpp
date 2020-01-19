//
// Created by zozo on 1/17/20.
//
//To have our own class with the proper memory management istalled. We need to manage both allocations and deallocations.
//The syntax to overload new is:
//void* operator new (size_t size)
//The syntax to overload delete is:
//void operator delete(void *p)
#include <iostream>
#include <stdlib.h>

class MyClass
{
    int _mymember, _yournumber;

public:
    MyClass()
    {
        std::cout << "Constructor is called\n";
    }

    ~MyClass()
    {
        std::cout << "Destructor is called\n";
    }

//    void *operator new(size_t size)//no size_t size is needed to be passed, it is deduced by the compiler
//    {
//        std::cout << "new: Allocating " << size << " bytes of memory" << std::endl;
//        void *p = malloc(size);
//
//        return p;
//    }
//
//    void operator delete(void *p)
//    {
//        std::cout << "delete: Memory is freed again " << std::endl;
//        free(p);
//    }
};

int main()
{
    MyClass *p = new MyClass(); //no size_t size is needed, it is deduced by the compiler
//    delete p;

//    int*p = new int ;
}