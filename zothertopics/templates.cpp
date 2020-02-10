//
// Created by zozo on 2/3/20.
//
#include <iostream>
using namespace std;

class Nani{
public:
    int value;
    int * next;
};


template <typename T>
T myMax(T a, T b){
    return (a > b)? a : b;
}

template <typename T>
class Node{
public:
    T value;
    Node<T> * next;
    Node(T v): value(v),next(nullptr){};
};


template <typename T>
void PrintList(Node<T>* n){
    while(n != nullptr){
        cout << n->value << " -> " ;
        n = n->next;
    }
    cout << "nullptr" <<endl;
}
int main()
{
    cout << myMax<int>(3, 7) << endl;  // Call myMax for int
    cout << myMax<float>(3.0, 1.0) << endl; // call myMax for double
    cout << myMax<char>('g', 'e') << endl;   // call myMax for char

    Node<float> * n1 = new Node<float>(3.69);
    Node<float> * n2 = new Node<float>(2.74);
    Node<float> * n3 = new Node<float>(1.97);
    Node<float> * n4 = new Node<float>(0.07);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    PrintList(n1);
    return 0;
}