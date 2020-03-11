//
// Created by zozo on 2/13/20.
//
#include <iostream>
#include <vector>
#include <future>
#include <algorithm>
#include <mutex>

class Vehicle{
public:
    Vehicle(int i): _id(i){};
    Vehicle(const Vehicle &src){
        _id = src._id;
//        std::cout << "copy constructor called " << std::endl;
    }
    void operator= (const Vehicle &src){
        _id = src._id;
//        std::cout << "copt constructor called " << std::endl;
    }
    int _id;

};


class Garage{
private:
    std::vector<Vehicle> parkingVechiles;
    int _numvehicles{0};
    std::mutex mutexy;
    std::timed_mutex tmutex;
public:
    void parkVehicle(Vehicle v){
            if (tmutex.try_lock_for(std::chrono::milliseconds(15))){
                int old_number = _numvehicles++;
                std::this_thread::sleep_for(std::chrono::microseconds(100));
                _numvehicles = old_number+1;
                std::cout << "numvechiles is " << _numvehicles << std::endl;
                tmutex.unlock();
            }
            else{
                std::cout << "Waiting for Vehile with id " << v._id << "to park" << std::endl;
            }



    }
    void printGarage(){
        tmutex.lock();
        std::cout << "Parked cars " << _numvehicles << std::endl;
        tmutex.unlock();
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
    std::this_thread::sleep_for(std::chrono::microseconds(100));
    mallgarage.printGarage();

}