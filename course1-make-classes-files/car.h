#include <string>
using namespace std;

class Car{
public:
    int number;
    float distance;
    string color;

    Car();
    Car(int num, string col, float dist);
    Car(int num);

    void printCarData();
    void incrementDistance(float speedplus);
};