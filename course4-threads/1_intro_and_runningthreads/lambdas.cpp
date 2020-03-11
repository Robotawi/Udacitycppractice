//
// Created by zozo on 2/10/20.
//

#include <iostream>
using std::cout; using std::endl;

int main(){
    //lambdas
    int id = 10;
    auto f1 = [id] () {cout << "ID is "<< id <<endl;};

    auto f2 = [&id] () {cout << "ID is "<< id <<endl;};

    auto f3 = [id] () mutable {id = 30; cout << "ID is "<< id <<endl;};

    auto f4 = [] (int id){id = 300; cout << "ID is "<< id <<endl;};

    f1();
    f2();
    f3();
    f4(10);

    return 0;
}