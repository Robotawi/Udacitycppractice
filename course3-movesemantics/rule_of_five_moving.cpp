//
// Created by zozo on 1/17/20.
//

//
// Created by zozo on 1/16/20.
//

#include <stdlib.h>
#include <iostream>

class MyMovableClass
{
private:
    int _size;
    int *_data;

public:
    MyMovableClass(size_t size) // constructor
    {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size*sizeof(int)  << " bytes" << std::endl;
    }

    MyMovableClass(MyMovableClass &source) // 2 : copy constructor
    {
        _size = source._size;
        _data = new int [_size];
        *_data = *source._data;
        std::cout << "COPYING conent of instance " << &source << " to instance " << this << std::endl;
    }

    MyMovableClass& operator= (const MyMovableClass& source) // 3 : copy assignment operator
    {
        if (this == &source){return *this;}
        delete [] _data;
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        return *this;
    }

    MyMovableClass (MyMovableClass&& source) // 4 : move constructor
    {
        std::cout << "MOVING (constructor) instance " << &source << " to instance " << this << std::endl;
        //take the source data to the copy, and invalidate the source data
        _size = source._size;
        _data = source._data;
        source._size = 0;
        source._data = nullptr;
    }

    MyMovableClass &operator=(MyMovableClass &&source) // 5 : move assignment operator
    {
        std::cout << "MOVING (assign) instance " << &source << " to instance " << this << std::endl;
        if (this == &source)
            return *this;

        delete[] _data;
        //take the source data to the copy, and invalidate the source data
        _data = source._data;
        _size = source._size;

        source._data = nullptr;
        source._size = 0;

        return *this;
    }


    ~MyMovableClass() // 1 : destructor
    {
        std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
        delete[] _data;
    }
};

//compile with g++ -std=c++11 -fno-elide-constructors rule_of_five_moving.cpp -o trymove5, otherwise the moving constructor will not be called
int main()
{
    MyMovableClass obj1(100); // constructor

    //this is a temp rvalue reference -> the move assign is called
    obj1 = MyMovableClass(200); // move assignment operator

    //this is a temp rvalue reference -> the move constructor is called
    MyMovableClass obj4 = MyMovableClass(300); // move constructor

    return 0;
}


/*
As with the move constructor, the data handle is copied from source to target which is coming in as an rvalue reference again.
Afterwards, the data members of source are invalidated.
 */