#include "BST.h"
#include<iostream>
using namespace std;

    BST::BST() {
        root = NULL;
    }
    
    BST::node* BST::insert(int data, node* root)
    {
        if(root == NULL)
        {
            root = new node;
            root->data = data;
            root->left =  NULL;
            root->right = NULL;
        }
        else if(data < root->data)
            root->left = insert(data, root->left);
        else if(data > root->data)
            root->right = insert(data, root->right);
        return root;
    }

    void BST::insert(int data) {
        root = insert(data, root);
    }

    bool BST::find(node* root, int data)
    {  
        if(root == NULL)
            return false;
        else if(data < root->data)
            return find(root->left, data);
        else if(data > root->data)
            return find(root->right, data);
        else
            return true;
    }

    bool BST::search(int data) {
        bool isFound = find(root, data);
            return isFound;
    }


void BST::printInOrder(node *root)
{
     if(root == NULL)
            return;
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
}

    void BST::printInOrder()
    {
        printInOrder(root);
    }

    void BST::printPreOrder(node* root)
    {
        if(root==NULL)
            return;
        cout << root->data << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }

    void BST::printPreOrder()
    {
        printPreOrder(root);
    }

    void BST::printPostOrder(node* root)
    {
        if(root==NULL)
            return;
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->data << " "; 
    }

    void BST::printPostOrder()
    {
        printPostOrder(root);
    }