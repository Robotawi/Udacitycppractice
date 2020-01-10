#include <iostream>
#include <string>

using namespace std;

class Car{
public:
    int number;
    string color;
    float distance;

    Car(): number(0), color("no color"), distance(0.0) {} ;
    Car(){
        number = 0;
        color = "no color";
        distance = 0.0;
    }
    Car(int num, string col, float dist){
        number = num;
        color = col;
        distance = dist;
    }
    void printCarData(){
        cout<< "Car number " << number << " has color "<< color <<"\n";
    }
    void incrementDistance(float speedplus){
        distance += speedplus;
    }
};

int main(){
    Car mycar;
    mycar.printCarData();

}