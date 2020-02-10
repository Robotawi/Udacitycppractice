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
    int Height;
};

class AVL{

public:
    int GetHeight(BSTNode* node){
        if (node == nullptr){ return -1;}
        return node->Height;
    }

    BSTNode* RotateLeft(BSTNode* node);
    BSTNode* RotateRight(BSTNode* node);
    BSTNode* Insert(BSTNode* node, int key);
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



BSTNode* AVL::RotateLeft(BSTNode* node){
    BSTNode* balancednode = node->right;
    //replace, means parents
    balancednode->parent = node->parent;
    node->parent = balancednode;
    //exchange branches
    //for balanced node
    balancednode->left = node;
    //and for the original node
    if (balancednode->left != nullptr){
        node->right = balancednode->left; //TODO: should this be here?
        balancednode->left->parent = node;
    }
    
    balancednode->Height = std::max(GetHeight(balancednode->left), GetHeight(balancednode->right)) + 1;
    node->Height = std::max(GetHeight(node->left), GetHeight(node->right)) + 1;

    return balancednode;
}


BSTNode* AVL::RotateRight(BSTNode *node) {
    BSTNode* balancednode = node-> left;
    //replace
    balancednode->parent = node-> parent;
    node->parent = balancednode;

    //exchange branches
    balancednode->right = node;

    if (balancednode->right != nullptr){
        node->left = balancednode->right;
        //node->left->parent = node; //or balancednode-right
        balancednode->right->parent = node;//or node->left->parent = node; ?
    }

    balancednode->Height = std::max(GetHeight(balancednode->left), GetHeight(balancednode->right)) + 1;
    node->Height = std::max(GetHeight(node->left), GetHeight(node->right)) + 1;

    return balancednode;
}


BSTNode* AVL::Insert(BSTNode *node, int key) {
    if (node == nullptr){
        BSTNode* node = new BSTNode;
        node->key = key;
        node->right = nullptr;
        node->left = nullptr;
        node->parent = nullptr;
        node->Height = 0;
    }
    else if (node->key < key){
        node = Insert(node->right, key);
        node->right->parent = node;
    }
    else{
        node = Insert(node->left, key);
        node->left->parent = node;
    }

    ////////////////////////////////////////////////////////////////////////
    //check for balance
    int balance = std::max(GetHeight(node->left), GetHeight(node->right));
    //if left heavy
    if (balance == 2){
        int balance2 = std::max(GetHeight(node->left->left), GetHeight(node->left->right));

        if (balance2 == 1){
            node = RotateRight(node);
        }
        else{ //-1
            // I don't understand this. OH! Now I got it!
            node->left = RotateLeft(node->left);
            node = RotateRight(node);
        }
    }
    //if right heavy
    if (balance == -2){
        int balance2 = std::max(GetHeight(node->right->left), GetHeight(node->right->right));

        if (balance2 == -1){
            node = RotateLeft(node);
        }
        else{
            //1
            node->right = RotateRight(node->right);
            node = RotateLeft(node);
        }
    }

    //refresh nodes height
    node->Height = std::max(GetHeight(node->left), GetHeight(node->right)) + 1;
    //////////////////////////////////////////////////////////////////////////

    return node;
}