//
// Created by zozo on 2/13/20.
//
#include <iostream>
#include <vector>
#include <future>
#include <algorithm>
#include <mutex>

struct Vehicle{
    Vehicle(int i): _id(i){};
    int _id;
};


class Garage{
private:
    std::vector<Vehicle> parkingVechiles;
    int _numvehicles{0};
    std::mutex mutexy;
public:
    void parkVehicle(Vehicle){
        mutexy.lock();
        int old_number = _numvehicles++;
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        _numvehicles = old_number+1;
        std::cout << "numvechiles is " << _numvehicles << std::endl;
        mutexy.unlock();

    }
    void printGarage(){
        std::cout << "Parked cars " << _numvehicles << std::endl;
    }
};


int main(){
    Garage mallgarage;
//    std::shared_ptr<Garage> mallgarage(new Garage);
    std::vector<std::future<void>> futures;
//    Vehicle car;
    for (int i = 1; i<=300; i++){
        std::cout << "task number "<< i << std::endl;
        Vehicle car(i);
        futures.emplace_back(std::async(std::launch::async, &Garage::parkVehicle, &mallgarage, car));
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }
    for_each(futures.begin(), futures.end(), [](std::future<void> &fut){ fut.wait();});
    mallgarage.printGarage();

}