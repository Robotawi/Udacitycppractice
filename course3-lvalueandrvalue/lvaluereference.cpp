//
// Created by zozo on 1/16/20.
//

#include <iostream>

int main()
{
    int i = 1;
    int &j = i;
    ++i;
    ++j;

    std::cout << "i = " << i << ", j = " << j << std::endl;

    return 0;
}