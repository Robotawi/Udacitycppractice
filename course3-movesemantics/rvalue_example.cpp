//
// Created by zozo on 1/16/20.
//

#include <iostream>

void myFunction(int &&val)
{   std::cout << "Hey, I am myFunction(int &&val). No copies needed!" <<std::endl;
    std::cout << "val = " << val << std::endl;
}


void myFunction(int &val)
{
    std::cout << "Hey, I am myFunction(int &val). You poor needed a useless copy to the memory!" <<std::endl;
    std::cout << "val = " << val << std::endl;
}

int main()
{   int i = 42;
    myFunction(42);
    myFunction(i);

    return 0;
}

/*
myFunction(42);
This is interesting from two perspectives:
Passing values like this improves performance as no temporary copy needs to be made anymore and
ownership changes, since the object the reference binds to has been abandoned by the caller and now binds to a handle which is available only to the receiver. This could not have been achieved with lvalue references as any change to the object that binds to the lvalue reference would also be visible on the caller side.
*/