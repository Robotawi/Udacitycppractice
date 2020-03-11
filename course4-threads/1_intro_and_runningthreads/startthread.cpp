//
// Created by zozo on 2/10/20.
//

#include<thread>
#include <iostream>


int main(){
    int cores = std::thread::hardware_concurrency();
    std::cout << "The main thread id is "<< std::this_thread::get_id() << std::endl;
    std::cout << "The number of cores is  "<< cores << std::endl;
}