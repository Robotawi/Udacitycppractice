//
// Created by zozo on 2/10/20.
//

#include <thread>
#include <iostream>

void ThreadFunction(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "ThreadFunction has an id of " << std::this_thread::get_id() << std::endl;
};
int main(){
    std::thread t(ThreadFunction);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "The Main Function has an id of " << std::this_thread::get_id() << std::endl;
    t.join();
    return 0;
}