//
// Created by zozo on 1/15/20.
//

#include <iostream>

class MyClass
{
private:
    int *_myInt;

public:
    MyClass(int num)
    {
        _myInt = (int *)malloc(sizeof(int));
        *_myInt = num;
        std::cout << "resource allocated, address is "<< _myInt << std::endl;
    }
    ~MyClass()
    {
            free(_myInt);
            std::cout << "resource freed" << std::endl;
    }
    //make this class from a source class
    //to have only one copy at one point of time able to handle the heap memory
    MyClass(MyClass &source){
        _myInt = (int *) malloc(sizeof(int));
        *_myInt = *source._myInt;
        std::cout << "resource allocated, address is "<< _myInt << std::endl;
    }
    //It takes a reference and returns a reference
    MyClass& operator= (MyClass &source){
        _myInt = (int *) malloc(sizeof(int));
        *_myInt = *source._myInt;
        std::cout << "resource allocated, address is "<< _myInt << std::endl;
        return *this;
    }
};

int main()
{
    MyClass source(25);
    MyClass destination(source);
    MyClass newone = destination;

    return 0;

}