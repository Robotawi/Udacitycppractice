//
// Created by zozo on 2/3/20.
//
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class Node{
public:
    T value;
    Node<T> * next;
};

template <typename T>
class Stack{
private:
    int m_count;
    Node<T> * m_top;
public:
    Stack();
    bool IsEmpty();
    T Top();
    void Push (T val);
    void Pop();
};

int main(){

    Stack<int> StackInt = Stack<int>();
    StackInt.Push(32);
    StackInt.Push(25);
    StackInt.Push(12);
    StackInt.Push(91);
    StackInt.Push(76);
    StackInt.Push(34);

    while (!StackInt.IsEmpty()){
        cout << StackInt.Top() << " - ";
        StackInt.Pop();
    }
    cout << endl;
    return 0;
}

template <typename T>
Stack<T>::Stack(): m_count{0}, m_top{nullptr}{}

template <typename T>
T Stack<T>::Top() {
    return m_top->value;
}

template <typename T>
bool Stack<T>::IsEmpty(){
    return m_count <= 0;
}

template <typename T>
void Stack<T>::Push(T val) {
    Node<T> * node = new Node<T>;
    node->next = m_top;
    node->value = val;
    m_top = node;
    m_count++;
}

template <typename T>
void Stack<T>::Pop() {
    Node<T> * node = m_top;
    m_top = m_top->next;
    delete node;
    m_count--;
}
