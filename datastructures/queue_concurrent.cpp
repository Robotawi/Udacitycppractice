//
// Created by Mohamed Raessa on 2/17/20.
//
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <future>
#include <memory>
#include <algorithm>
#include <condition_variable>

template<typename T>
class Node{
public:
    T value;
    Node<T> * next;
};

template <typename T>
class Queue{
private:
    int m_count;
    Node<T> * m_front;
    Node<T> * m_back;
    std::mutex _mutex;
    std::condition_variable _cond;
public:
    Queue();
    void Pop();
    void Push(T val);
    T Front();
    bool IsEmpty();
};


int main(){
    std::shared_ptr<Queue<int>> QueueInt (new Queue<int>);

    //the popping threads
    std::vector<std::future<void>> poppingthreads;
    for (int i = 0; i<=10; i++){
        //here is single-pusher
        QueueInt->Push(i);
        std::cout << i << " is pushed " <<std::endl;
        //here is multi-popper
        poppingthreads.emplace_back(std::async(std::launch::async, &Queue<int>::Pop, QueueInt));
    }

    std::for_each(poppingthreads.begin(), poppingthreads.end(), [](std::future<void> &fut){ fut.wait();});

    return 0;
}


template <typename T>
Queue<T>::Queue() : m_count{0},m_front{nullptr}, m_back{nullptr} {};

template <typename T>
bool Queue<T>::IsEmpty(){
    return m_count <= 0;
}
template <typename T>
T Queue<T>::Front(){
    return m_front->value;
}

template <typename  T>
void Queue<T>::Push(T val) {
    std::unique_lock<std::mutex> uLock(_mutex);
    if (m_count == 0){
        Node<T> * node = new Node<T>;
        m_front = node;
        m_front->value = val;
        m_back = m_front;
    }
    else{
        Node<T> * node = new Node<T>;
        m_back->next = node;
        m_back->value = val;
        m_back = node;
    }
    m_count++;
    uLock.unlock();
    _cond.notify_all();
}

template <typename  T>
void Queue<T>::Pop() {
    std::unique_lock<std::mutex> uLock(_mutex);
//    std::cout << "Inside the pop" << std::endl;
    _cond.wait(uLock, [this](){return !IsEmpty();});
    if (m_count == 0){
        std::cout << "The queue is empty" << std::endl;
        return;
    }
    else{
        Node<T> * node = m_front;
        m_front = m_front->next; //the front is taking the address of its next
        std::cout << "Pop operation is carried out" << std::endl;
        delete node;
        m_count--;
    }
}