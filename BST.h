#ifndef H_BST
#define H_BST

#include <iostream>
using namespace std;

class BST
{
    protected:
        struct node 
        {
            int data;
            node* left;
            node* right;
        };
        node* insert(int data, node* root);
        bool find(node* root, int data);
        void printInOrder(node* root);
        void printPreOrder(node* root);
        void printPostOrder(node* root);

    public:
        node* root;
        BST();
        void insert(int data);
        bool search(int data);
        void printInOrder();
        void printPreOrder();
        void printPostOrder();
};

#endif