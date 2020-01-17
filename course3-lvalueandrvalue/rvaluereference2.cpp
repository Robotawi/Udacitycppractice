//
// Created by zozo on 1/16/20.
//

#include <iostream>

int main()
{
    int i = 1;
    int j = 2;
    int k = i + j;
    int &&l = i + j; //here we can just use 1+2 and forget about all the copying in the lines before

    std::cout << "k = " << k << ", l = " << l << std::endl;

    return 0;
}