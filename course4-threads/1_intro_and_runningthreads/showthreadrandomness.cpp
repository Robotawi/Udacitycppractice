//
// Created by zozo on 2/10/20.
//

#include <thread>
#include <iostream>

using namespace std;
void firstThread(){
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout<< "First thread finished work!" << endl;
}
void secondThread(){
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout<< "Second thread finished work!" << endl;
}
int main(){
    thread t1(firstThread), t2(secondThread);
//    t1.detach(); // don't wait for the process to finish. If there's no sleep in the main, the thread will not be given time to finish its work
//    t2.detach();
//    this_thread::sleep_for(chrono::milliseconds(1000));
    cout<< "Main thread finished work!" << endl;
    t1.join();
    t2.join();
    return 0;
}