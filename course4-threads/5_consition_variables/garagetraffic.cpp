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
    std::vector<Vehicle> _parkedVechiles;
    std::mutex _mutex;
    int _old_number{0};
    bool _newparked;
public:
    bool isNewDataAvailable(){
        std::lock_guard<std::mutex> mylckg(_mutex);
        std::cout << "Is data available checked!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (_newparked){
            _newparked = false;
            std::cout << "trueeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" << std::endl;
            return true;
        }
        else{
            std::cout << "falseeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" << std::endl;;
            return false;}
    }
    void parkVehicle(Vehicle && v){
        std::lock_guard<std::mutex> lckg(_mutex);
        _parkedVechiles.emplace_back(std::move(v));
        _newparked = true;
        std::cout << "inside parkVechile newparked set to TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT" << std::endl;;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "numvechiles is " <<  _parkedVechiles.size() << std::endl;

    }
    void printGarage(){
        std::lock_guard<std::mutex> lckg(_mutex);
        std::cout << "Parked cars " << _parkedVechiles.size() << std::endl;
    }
};


int main(){
//    Garage mallgarage;
    std::shared_ptr<Garage> mallgarage(new Garage);
    std::vector<std::future<void>> futures;
//    Vehicle car;
    for (int i = 1; i<=10; i++){
        std::cout << "task number "<< i << std::endl;
        Vehicle car(i);
        futures.emplace_back(std::async(std::launch::async, &Garage::parkVehicle, mallgarage, std::move(car)));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    while(true){
        if (mallgarage->isNewDataAvailable()){
            mallgarage->printGarage();
//            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

    }
    for_each(futures.begin(), futures.end(), [](std::future<void> &fut){ fut.wait();});
//    mallgarage.printGarage();

}