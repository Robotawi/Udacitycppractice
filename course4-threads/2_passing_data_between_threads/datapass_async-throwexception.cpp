//
// Created by zozo on 2/12/20.
//

#include <thread>
#include <future>
#include <string>
#include <iostream>
using std::cout;
using std::endl;

std::string modifyMessage(std::string msg){
    cout << "The thread id is " << std::this_thread::get_id() << endl;
        if (msg.empty()){
            throw std::runtime_error("The message from main is empty!");
        }
        else{
            std::string modifiedmsg = msg + ", + I am the from thread!";
            cout << "I am the thread, and I finsihed my job" << endl;
            return modifiedmsg;
        }
    }

int main(){
    cout << "Main thread id is " << std::this_thread::get_id() << endl;
    std::string message = "Message from main";
    std::future<std::string> fut = std::async(std::launch::deferred, modifyMessage, message);

//    auto status = fut.wait_for(std::chrono::milliseconds(1000));
//    if (status == std::future_status::ready){
        try{
            cout << "The returned message from the thread is: " << endl;
            cout << fut.get() << endl;
        }
        catch(std::runtime_error e){
            cout << e.what()<<endl;
        }

//    }
//    else{
//        cout << "No returned message from the thread yet" << endl;
//    }

    return 0;
}