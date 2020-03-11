//
// Created by zozo on 2/12/20.
//

#include <thread>
#include <future>
#include <string>
#include <iostream>
using std::cout;
using std::endl;

void modifyMessage(std::promise<std::string> && prms, std::string msg){
    std::string modifiedmsg = msg + ", I am the from thread!";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    prms.set_value(modifiedmsg);
    cout << "I am the thread, and I finsihed my job" << endl;
}

int main(){
    std::promise<std::string> prms;
    std::future<std::string> fut = prms.get_future();
    std::string message = "Message from main";
    std::thread t = std::thread(modifyMessage, std::move(prms), message);

    auto status = fut.wait_for(std::chrono::milliseconds(500));
    if (status == std::future_status::ready){
        cout << "The returned message from the thread is: " << endl;
        cout << fut.get() << endl;
    }
    else{
        cout << "No returned message from the thread yet" << endl;
    }

    t.join();
    return 0;
}