//
// Created by zozo on 1/15/20.
//

#include <iostream>

class MyClass
{
private:
    int *_myInt;
    static int _cnt;

public:
    MyClass(int val);
    ~MyClass();
    MyClass(MyClass &source);
    MyClass& operator= (MyClass& source);
};

int MyClass::_cnt = 0;

MyClass::MyClass(int val) //constructor
{
    _myInt = (int *)malloc(sizeof(int));
    *_myInt = val;
    _cnt++;
    std::cout << "resource allocated at address " << _myInt << std::endl;
}

MyClass::~MyClass() //destructor
{
    _cnt--;
    if (_cnt == 0)
    {
        free(_myInt);
        std::cout << "resource freed at address " << _myInt << std::endl;
    }
    else
    {
        std::cout << "instance at address " << this << " goes out of scope with _cnt = " << _cnt << std::endl;
    }
}

MyClass::MyClass(MyClass &source)
{
    _myInt = source._myInt; //the same pointer
    _cnt++;
    std::cout << _cnt << " instances with handles to address " << _myInt << " with _myInt = " << *_myInt << std::endl;
}

int main()
{
    MyClass source(42);
    MyClass destination1(source);
    MyClass destination2(source);
    MyClass destination3(source);

    return 0;
}