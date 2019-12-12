#include "car.h"
#include <string>
#include <iostream>
using namespace std;

Car::Car(): number(0), color("no color"), distance(0) {};
Car::Car(int num, string col, float dist): number(num), color(col), distance(dist) {};

void Car::printCarData() {
    cout<< "Car number " << number << " has color "<< color <<"\n";
}

void Car::incrementDistance(float speedplus) {
    distance += speedplus;
}