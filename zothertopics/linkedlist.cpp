//
// Created by zozo on 1/21/20.
//

#include <iostream>

class Node{
public:
    int data;
    Node* next = nullptr;
};

void PrintList (Node* head);
void GetNode(Node* n, int pos);
void DeleteNode(Node* n, int pos);
void Push(Node** n, int data);
void Append(Node** n, int data);

int main(){
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;
    Node* fifth = new Node;

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = nullptr;

    PrintList(head);

    GetNode(head, 4);

    Push(&head, 7);

    PrintList(head);
    std::cout << "Now appending 11 to the linked list"<<std::endl;
    Append(&head, 11);
    PrintList(head);

//    PrintList(head);
    return 0;
}



void PrintList (Node* n){
    while (n != nullptr){
        std::cout << n->data << std::endl;
        n = n->next;
    }
}

void GetNode(Node* n, int pos){
    int index = 0;
    while (index <= pos){
        n = n->next;
        index++;
        if (index == pos){
            std::cout << "Node " << pos << " data is "<< n->data << std::endl;
        }
    }
}

void DeleteNode(Node* n, int pos){
    int index = 0;
    while(index <= pos){
        n = n->next;
        std::cout << "In delete, reached index = "<< index <<", required to delete index "<<pos<<std::endl;
        if (index == pos-1){
            //delete the node next to the current, and let the current point to the next of the next
            std::cout << "reached inside f to index " << pos-1 <<std::endl;
            n->next = n->next->next;//now 1 is pointing to 3
        }
        index++;
    }
}

void Push(Node** head, int data){
    //pointer to pointer because we will pass the head to it, and the head is to be changed
    //make a new pointer to node LL is a list of pointers to nodes
    Node* newnode = new Node;
    //give the new node its data
    newnode->data = data;
    //let the pointer of the new node point to the node pointed to by the head
    newnode->next = *head;
    //let the head be the newnode
    *head = newnode;
}


void Append(Node** headref, int data){
    //make a newnode, and assign it the data,
    //go through the list, and when you reach the end, let the end point to it
    //and let it point to nulptr

    Node* newnode = new Node;
    newnode->data = data;
    newnode->next = nullptr;

    Node* last = *headref;
    if (last == nullptr){
        *headref = newnode;
    }
    while(last->next != nullptr){
        last = last->next;
    }
    last->next = newnode;
}