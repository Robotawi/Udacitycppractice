#include "car.h"
#include <string>
#include <iostream>

int main(){
    Car mycar;
    mycar.printCarData();

    Car my2ndcar(1001);
    my2ndcar.printCarData();
}