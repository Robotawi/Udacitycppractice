//
// Created by zozo on 2/11/20.
//
#include <iostream>
#include <thread>
#include <vector>
using std::cout; using std::endl;

void counter(int start){
    while (true){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout<< "Worker thread is counting " << start << endl;
        start++;
    }
}

void printer(){
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "I am printing something, I am a printer!!!" << endl;
    }
}
int main(){
    std::vector<std::thread> threads;
    for (size_t i = 0; i < 5 ; i++){
        threads.emplace_back(std::thread(counter, 1));
        threads.emplace_back(std::thread(printer));
    }
    for (auto &t : threads){t.join();}
    return 0;
}