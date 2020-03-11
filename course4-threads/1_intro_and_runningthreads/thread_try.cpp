//
// Created by zozo on 2/11/20.
//
#include <iostream>
#include <thread>
using std::cout; using std::endl;

void printEven(int start, int end){
    for (int i = start; i <= end; i=i+2){
        cout<< "Print Even number " << i << endl;
    }
}

void printOdd(int start, int end){
    for (int i = start; i <= end; i=i+2){
        cout<< "Print Odd number " << i << endl;
    }
}


int main(){
    std::thread t1 = std::thread(printEven, 2, 20);
    std::thread t2 = std::thread(printOdd, 1, 19);
    std::this_thread::sleep_for(std::chrono::microseconds(1000));
    t1.join();
    t2.join();
    return 0;
}