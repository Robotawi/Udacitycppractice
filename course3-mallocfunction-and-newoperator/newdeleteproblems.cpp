//
// Created by zozo on 1/17/20.
//
#include <stdlib.h>
#include <iostream>

class MyClass{
private:
    int* i,j;
    float* k,l;
public:
    MyClass(){
        i = (int *) malloc (sizeof(int));
    }
};
int main(){

    int *p = new int;
    delete p;

    MyClass * ptr = new MyClass;
    delete ptr;

    MyClass * ptrarray = new MyClass[5] ;

    int*ptrint = new int[](5,6);

}