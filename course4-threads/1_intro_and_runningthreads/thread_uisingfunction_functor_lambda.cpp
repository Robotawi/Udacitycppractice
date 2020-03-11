//
// Created by zozo on 2/12/20.
//

#include <iostream>
#include <thread>

void printMessage(std::string message)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // simulate work
    std::cout << "Thread 1: " << message << std::endl;
}

class messagePrinter{
private:
    std::string _message;
public:
    messagePrinter(std::string msg):_message(msg){};
    void operator ()(){
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // simulate work
        std::cout << "Thread 3: " << _message << std::endl;
    }
};

int main()
{
    // define message
    std::string message = "My Message";

    // start thread using variadic templates
    std::thread t1(printMessage, message);

    // start thread using a Lambda
    std::thread t2([message] {
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // simulate work
        std::cout << "Thread 2: " << message << std::endl;
    });


    // start threading using a functor
    std::thread t3  = std::thread(messagePrinter(message));
    // thread barrier
    t1.join();
    t2.join();
    t3.join();

    return 0;
}