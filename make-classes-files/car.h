#include <string>
using namespace std;

class Car{
public:
    int number;
    float distance;
    string color;

    Car();
    Car(int num, string col, float dist);
    void printCarData();
    void incrementDistance(float speedplus);
};