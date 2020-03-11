//
// Created by zozo on 2/10/20.
//
#include <iostream>
#include <thread>


using std::cout; using std::endl;

class Vehicle{
private:
    int _id;
public:
    Vehicle(int id): _id(id) {}
    void operator()(){
        cout << "Vehicle with id " << _id << " was created!" << endl;
    }


};


int main(){
    int i = 5;
    std::thread t (Vehicle(1));
    //using lambdas
    std::thread t2 ([i] () mutable {i = 20; cout << "i from inside thread is "<<i<<endl;});
    t.join();
    t2.join();
    return 0;
}