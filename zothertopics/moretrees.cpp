//
// Created by zozo on 1/25/20.
//

//make a class for the node of the tree,

//and a class of the tree
#include <iostream>
#include "eigen-3.3.7/Eigen/Eigen"


class BSTNode{
public:
    int data;
    BSTNode* parent = nullptr;
    BSTNode* right = nullptr;
    BSTNode* left = nullptr;
};


class BST{
public:
    BSTNode * root;
    BSTNode * Insert(BSTNode* node, int data);
    void PrintInOrder(BSTNode* node);
    bool Search(BSTNode* node, int targetdata);
    int FindMax(BSTNode* node);
    int FindMin(BSTNode* node);
    int Successor(BSTNode* node, int targetdata);
};


int main(){
    BST * tree = new BST;
    //it returns the root, but builds something inside it.
    //Is not this amazing?
    tree->root = tree->Insert(tree->root, 1);
    std::cout << "tree->root is "<< &tree->root <<std::endl;
//    tree->root = tree->Insert(tree->root, 2);
//    std::cout << "tree->root is "<< &tree->root <<std::endl;
//    tree->root = tree->Insert(tree->root, 5);
//    std::cout << "tree->root is "<< &tree->root <<std::endl;
//    tree->root = tree->Insert(tree->root, 4);
//    std::cout << "tree->root is "<< &tree->root <<std::endl;

    int keys[] = {6, 11, 24, 15, 26, 31, 7, 50, 70, 122};

    for (const int k : keys){
        for (int i = 2; i <10; i++){
            tree->Insert(tree->root, k*i);
        }
    }
    tree->PrintInOrder(tree->root);

    auto hmmm = tree->Search(tree->root, 2);
    std::cout << "Search result is " << hmmm << std::endl;
    hmmm = tree->Search(tree->root, 17);
    std::cout << "Search result is " << hmmm << std::endl;

    auto min = tree->FindMin(tree->root);
    std::cout << "The minimum is " << min << std::endl;

    auto max = tree->FindMax(tree->root);
    std::cout << "The maximum is " << max << std::endl;

//    auto findy = tree->Successor(tree->root, 2);
//    std::cout << "The successor of 2 is " << findy << std::endl;

    return 0;

}


BSTNode* BST::Insert(BSTNode* node, int data){
    //if the tree doesn't exist, intialize the root
    if (node == nullptr){
        //this is not the root, this is just connected to the root
        node  = new BSTNode;
        node->data = data;
        node->right = nullptr;
        node->left = nullptr;
    }
    else if (data > node->data){
        node->right = Insert(node->right, data);
        node->right->parent = node;
    }
    else{
        node->left = Insert(node->left, data);
        node->left->data = data;
        node->left->parent = node;
    }
    return node;

}


void BST::PrintInOrder(BSTNode *node) {
    if (node == nullptr){return;}
    else{
        PrintInOrder(node->left);
        std::cout << node->data << std::endl;
        PrintInOrder(node->right);
    }
}


bool BST::Search(BSTNode *node, int targetdata) {
   if (node == nullptr){
       return false;
   } else if (node->data == targetdata){return true;}
   else if (node->data < targetdata){Search(node->right, targetdata);}
   else{Search(node->left, targetdata);}
}


int BST::FindMax(BSTNode* node){
    if (node == nullptr){
        return -1;
    }
    else if (node->right == nullptr){return node->data;}
    else{FindMax(node->right);}
}
int BST::FindMin(BSTNode* node){
    if (node == nullptr){
        return 9999;
    }
    else if (node->left == nullptr){return node->data;}
    else{FindMax(node->left);}
}


//int BST::Successor(BSTNode* node, int targetdata){
//    if(node == nullptr){
//        return 9999;
//    }
//    if (Search(node, targetdata)){
//        if (node->right == nullptr){
//            std::cout<<"targetdata has no successor" << std::endl;
//            return 9999;
//        }
//        else {Successor()}
//    }
//    else{
//        std::cout << "The targetdata doesn't exist in the tree" << std::endl;
//        return 9999;
//    }
//}