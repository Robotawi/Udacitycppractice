//
// Created by zozo on 1/23/20.
//
#include <iostream>

class BSTNode{
public:
    int key;
    BSTNode* parent = nullptr;
    BSTNode* left = nullptr;
    BSTNode* right = nullptr;
};

class BST{
private:
    BSTNode* root;
protected:
    BSTNode* Insert(BSTNode* node, int key);
    void PrintInOrder(BSTNode* node);
public:
    void Insert(int key);
    void PrintInOrder();
};


int main (){
    BST* tree = new BST;
    tree->Insert(1);
    tree->Insert(2);
    tree->Insert(5);
    tree->Insert(11);
    tree->Insert(7);
    tree->Insert(17);
    tree->Insert(3);

    tree->PrintInOrder();
    return 0;
};

void BST::Insert(int key) {
    root = Insert(root, key);
}

BSTNode* BST::Insert(BSTNode* node, int key){
    //every inserted node must be compared to the root
    if (node == nullptr){ //if no root
        node = new BSTNode;
        node->parent = nullptr;
        node->left = nullptr;
        node->right = nullptr;
        node->key = key;
    }//then, is the key > or < go go till there's no child
    else if (key > node->key){
        //insert to the right
        node->right = Insert(node->right, key);
        node->right->parent = node;
    }
    else{
        node->left = Insert(node->left, key);
        node->left->parent = node;
    }
    return node;
}

void BST::PrintInOrder(BSTNode *node) {
    if (node == nullptr) { return ;}
    PrintInOrder(node->left);
    std::cout << node->key <<std::endl;
    PrintInOrder(node->right);
}

void BST::PrintInOrder() {
    PrintInOrder(root);
}