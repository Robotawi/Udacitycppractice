//
// Created by zozo on 2/12/20.
//
#include <future>
#include <iostream>
#include <thread>

class Vehicle{
private:
    int _id;
public:
    Vehicle():_id(0){};
    Vehicle(int id): _id(id){};
    void setID(int id){
        _id = id;
        std::cout << "ID is set to " << id << ",in thread " << std::this_thread::get_id() << std::endl;
    }
    int getID(){
        return _id;
    }
};

int main(){
    Vehicle mycar;
    //using async
    //    std::future<void> fut = std::async(&Vehicle::setID,&mycar,20);
    //    fut.wait_for(std::chrono::milliseconds(1));

    //using thread
    std::thread toto(&Vehicle::setID, &mycar, 20);
    toto.join();
    std::cout << mycar.getID() << std::endl;
    return 0;
}