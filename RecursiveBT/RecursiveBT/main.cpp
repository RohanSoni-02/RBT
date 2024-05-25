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
    
    bool insert(int value){
        Node* newNode = new Node(value);
        if(root == nullptr){
            root = newNode;
            return true;
        }
        Node* temp = root;
        while (true) {
            if (newNode->value == temp->value) {
                return false;
            }
            
            if (newNode->value < temp->value) {
                if (temp->left == nullptr) {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
            else{
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
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
};

int main(int argc, const char * argv[]) {
    
}
