//
//  main.cpp
//  RecursiveBT
//
//  Created by Rohan Soni on 25/5/2024.
//

#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* left;
    Node* right;
    
    Node(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree{
public:
    Node* root;
    
    BinarySearchTree(){
        root = nullptr;
    }
    
    Node* rInsert(Node* currentNode, int value){
        if (currentNode == nullptr) {
            return new Node(value);
        }
        if(value < currentNode-> value){
            currentNode->left = rInsert(currentNode->left, value);
        }
        else if(value > currentNode->value){
            currentNode->right = rInsert(currentNode->right, value);
        }
        return currentNode;
    }
    
    void rInsert(int value){
        if(root == nullptr){
            root = new Node(value);
        }
        rInsert(root, value);
    }
    
    bool rContains(Node* currentNode, int value){
        if(currentNode==nullptr){
            return false;
        }
        if(currentNode->value == value){
            return true;
        }
        if(value < currentNode->value){
            return rContains(currentNode->left, value);
        }
        else{
            return rContains(currentNode->right, value);
        }
    }

    bool rContains(int value){
        return rContains(root, value);
    }
    
    int minValue(Node* currentNode){
        while(currentNode->left != nullptr){
            currentNode = currentNode->left;
        }
        return currentNode->value;
    }
    
    Node* rdelete(Node* currentNode, int value){
        if (currentNode == nullptr) {
            return nullptr;
        }
        if (value < currentNode->value) {
            currentNode->left = rdelete(currentNode->left, value);
        }
        else if(value > currentNode->value){
            currentNode->right = rdelete(currentNode->right, value);
        }
        else{
            if (currentNode->left== nullptr && currentNode->right == nullptr) {
                delete currentNode;
                return nullptr;
            }
            else if (currentNode->left == nullptr) {
                Node* temp = currentNode->right;
                delete currentNode;
                return temp;
            }
            else if (currentNode->right == nullptr) {
                Node* temp = currentNode->left;
                delete currentNode;
                return temp;
            }
            else{
                
            }
        }
    }
    
    void rdelete(int value){
        root = rdelete(root, value);
    }
};

int main(int argc, const char * argv[]) {
    BinarySearchTree* myBST = new BinarySearchTree();
    myBST->rInsert(2);
    myBST->rInsert(1);
}
