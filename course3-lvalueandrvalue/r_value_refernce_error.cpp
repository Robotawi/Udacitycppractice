//
// Created by zozo on 1/16/20.
//

#include <iostream>

void myFunction(int &val)
{
    std::cout << "val = " << val << std::endl;
}

int main()
{
    int j = 42;
    myFunction(j);

    myFunction(42);//causes an error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'

    int k = 23;
    myFunction(k);

    return 0;
}