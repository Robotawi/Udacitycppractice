//
// Created by zozo on 2/10/20.
//

#include <iostream>
using std::cout; using std::endl;
void sayHello(){
    cout << "Hello!" <<endl;
}

int main(){
    void (*funcptr) () = sayHello;
    funcptr();
    return 0;
}