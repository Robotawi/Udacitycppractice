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
//private:


public:
    int _size;
    int *_data;
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

void useObject(MyMovableClass obj)
{
    std::cout << "using object " << &obj << std::endl;
}

int main()
{
    MyMovableClass obj1(100); // constructor
    std::cout <<obj1._data<<std::endl;
//     useObject(obj1); //this pass by value will require a temp copy, a temp deep copy
//    note that this can be solved by useObject(std::move(obj1)) which treats lvalue as rvalue reference
    useObject(std::move(obj1)); // ths move constructor will be called instead of the copy constructor
//     useObject(MyMovableClass (200)); //this saves us from the need to create a copy as in the above call to useObject
    //note very well the data inside obj1 is invalidated after moving its owenership to the function as if its taken to nother scope and kept living there.
    std::cout <<obj1._data<<std::endl;
    return 0;
}


/*
By using std::move, we were able to pass the ownership of the resources within obj1 to the function useObject.
 The local copy obj1 in the argument list was created with the move constructor and thus accepted the ownership transfer from obj1 to obj.
 Note that after the call to useObject, the instance obj1 has been invalidated by setting its internal handle to null and thus may not
 be used anymore within the scope of main (even though you could theoretically try to access it, but this would be a really bad idea).
 */