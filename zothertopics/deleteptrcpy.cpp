//
// Created by zozo on 2/4/20.
//

#include <iostream>

using namespace std;

int main()
{
    int * ptr = new int(10);
    int * ptrcpy = ptr;
    int i = 10;
    int * ptrstack = &i;
    cout << *ptrcpy << endl;
    delete ptrcpy;
//    delete ptrstack;
    return 0;
}
