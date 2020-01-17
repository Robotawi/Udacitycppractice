//
// Created by zozo on 1/16/20.
//

#include <iostream>

void myFunction(int &val)
{
    ++val;
}

int main()
{
    int i = 1;
    myFunction(i);

    std::cout << "i = " << i << std::endl;

    return 0;
}