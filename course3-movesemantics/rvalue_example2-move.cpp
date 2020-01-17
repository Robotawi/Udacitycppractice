//
// Created by zozo on 1/16/20.
//

#include <iostream>

void myFunction(int &&val)
{   std::cout << "Hey, I am myFunction(int &&val). No copies needed!" <<std::endl;
    std::cout << "val = " << val << std::endl;
}


// void myFunction(int &val)
// {
//     std::cout << "Hey, I am myFunction(int &val). You poor needed a useless copy to the memory!" <<std::endl;
//     std::cout << "val = " << val << std::endl;
// }

int main()
{   int i = 42;
    myFunction(42);
    myFunction(std::move(i)); //convert an lvalue to rvalue

    return 0;
}


