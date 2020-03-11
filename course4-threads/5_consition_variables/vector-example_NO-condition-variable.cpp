//
// Created by zozo on 2/14/20.
//
//queue of cars to enter a garage
#include <queue>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <future>
#include <memory>

using std::cout; using std::endl;

class Vehicle{
private:
    int _id;
public:
    Vehicle(int id):_id(id){};
    int getID(){return _id;}
};


class Garage{
private:
    std::queue<Vehicle> _waitingqueue;
    std::mutex _mutex;
    std::condition_variable cond;
public:
    void enterGarage(Vehicle &&v){
        std::unique_lock<std::mutex> uLock(_mutex);
        _waitingqueue.push(std::move(v));
        cout<< "Vehicle with ID "<< _waitingqueue.back().getID() << " is waiting to enter the garage" << endl;
//        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void newVehicleInfo(){
        std::unique_lock<std::mutex> uLock(_mutex);
        if (!_waitingqueue.empty()){
            int v_id = _waitingqueue.back().getID();
            cout<< "Vehicle with ID "<< _waitingqueue.front().getID() << " entered the garage" << endl;
            _waitingqueue.pop();
//            std::this_thread::sleep_for(std::chrono::seconds(1));

        }
        else{
            cout<< "No vehicle entered the garage" << endl;
//            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
};

int main(){

    std::shared_ptr<Garage> mallgarage(new Garage);
    std::vector<std::future<void>> futures;
    for (int i = 1; i <= 10; i++){
        Vehicle car(i);
        futures.emplace_back(std::async(std::launch::async, &Garage::enterGarage, mallgarage, std::move(car)));
    }
    while (true){
        mallgarage->newVehicleInfo();
    }
}