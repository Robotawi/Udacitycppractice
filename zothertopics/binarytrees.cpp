//
// Created by zozo on 1/21/20.
//

//make a binray tree

class Node{
public:
    int key;
    Node* right = nullptr;
    Node* left  = nullptr;
};

//helper function
Node* NewTreeNode (int data){
    Node* newnodeptr = new Node;
    newnodeptr->key = data;
    newnodeptr->right = nullptr;
    newnodeptr->left = nullptr;

    return newnodeptr;
}

int main(){
    Node * root = NewTreeNode(1);
    root->left = NewTreeNode(2);
    root->right = NewTreeNode(3);
    root->left->left = NewTreeNode(4);
    root->left->right = NewTreeNode(5);
    root->right->left = NewTreeNode(6);
    root->right->right = NewTreeNode(7);
}