//
// Created by zozo on 2/4/20.
//
#include <iostream>
#include <thread>
#include <mutex>

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
public:
    Queue();
    void Dequeue();
    void Enqueue(T val);
    T Front();
    bool IsEmpty();
};


int main(){
    Queue<int> QueueInt = Queue<int>();
    QueueInt.Enqueue(25);
    QueueInt.Enqueue(95);
    QueueInt.Enqueue(22);
    QueueInt.Enqueue(11);
    QueueInt.Enqueue(20);

    while(!QueueInt.IsEmpty()){
        std::cout << QueueInt.Front() << " - " ;
        QueueInt.Dequeue();
    }
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
void Queue<T>::Enqueue(T val) {
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
}

template <typename  T>
void Queue<T>::Dequeue() {
    if (m_count == 0){
        return;
    }
    else{
        Node<T> * node = m_front;
        m_front = m_front->next; //the front is taking the address of its next
        delete node;
        m_count--;
    }
}