//
// Created by zozo on 1/15/20.
//

#include <iostream>

class MyClass
{
private:
    int *_myInt;

public:
    MyClass()
    {
        _myInt = (int *)malloc(sizeof(int));
        std::cout << "resource allocated" << std::endl;
    }
    ~MyClass()
    {
        if (_myInt != nullptr)
        {
            free(_myInt);
            std::cout << "resource freed" << std::endl;
        }

    }
    //make this class from a source class
    //to have only one copy at one point of time able to handle the heap memory
    MyClass(MyClass &source){
        _myInt = source._myInt;
        source._myInt = nullptr;
    }
    //It takes a reference and returns a reference
    MyClass& operator= (MyClass &source){
        _myInt = source._myInt;
        source._myInt = nullptr;
        return *this;
    }
};

int main()
{
    MyClass source;
    MyClass destination(source);
    MyClass newone = destination;
    std::cout <<"} not yet reached "<< std::endl;
    return 0;

}