//
// Created by zozo on 2/12/20.
//

#include <thread>
#include <cmath>
#include <iostream>
#include <vector>
#include <future>

void calcPower(float base, float power){
    float result{0.0};
    for (int ii = 0 ; ii <= 100000 ; ii++){
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        result = std::pow(base, power);
        std::cout << ii << ", " ;
    }
    std::cout << std::endl;
}

int main(){
    std::vector<std::future<void>> futures;
    for (int i = 0 ; i<= 50 ; i++){
        futures.emplace_back(std::async(std::launch::async | std::launch::deferred, calcPower,55555,55555555));
    }
    std::cout << " The task is done :) " <<std::endl;
    return 0;
}