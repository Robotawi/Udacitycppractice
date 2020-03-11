//
// Created by zozo on 2/14/20.
//

#include <mutex>
#include <iostream>
#include <condition_variable>
#include <queue>
#include <thread>

std::queue<int> q;
std::mutex mutx;
std::condition_variable cond;

void Producer(){
    int count = 0;
    while (count <= 10){
        std::unique_lock<std::mutex> uLock(mutx);
        q.push(count);
        std::cout << "Pushed " << count << std::endl;
        uLock.unlock();
        cond.notify_one();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count++;
    }
}


void Consumer(){
    int data = 0;
    while(true){
        std::unique_lock<std::mutex> uLock(mutx);
        cond.wait(uLock, [](){return !q.empty();});
        if (!q.empty()){
            data = q.back();
            q.pop();
            std::cout << "Consumer got data " << data << std::endl;
            if (data == 10) break;
        }
    }
}



int main(){
    std::thread t1(Producer);
    std::thread t2(Consumer);

    t1.join();
    t2.join();
    return 0;
}