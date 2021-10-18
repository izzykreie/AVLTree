#ifndef H_AVLTree
#define H_AVLTree

#include <iostream>
using namespace std;

class node  
{
    public: 
    node* left;
    node* right;
    int data;
    int height;
};

class AVLTree
{
    public:
    AVLTree();

    node* insert(int data, node* root);
    bool find(node* root, int data);
    void printInOrder(node* root);
    void printPreOrder(node* root);
    void printPostOrder(node* root);

    private: 
    void updateHeight(node* root);
    int getHeight(node* root);
    node* rotateRight(node* oldRoot);
    node* rotateLeft(node* oldRoot);
};

#endif