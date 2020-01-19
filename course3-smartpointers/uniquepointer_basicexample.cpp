//
// Created by zozo on 1/19/20.
//

#include <memory>

void RawPointer()
{
    int *raw = new int; // create a raw pointer on the heap
    *raw = 1; // assign a value
    delete raw; // delete the resource again
}

void UniquePointer()
{
    std::unique_ptr<int> unique(new int); // create a unique pointer on the stack

    *unique = 2; // assign a value
    // delete is not neccessary
}

int main(){


    return 0;
}