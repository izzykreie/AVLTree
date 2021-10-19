#include "AVLTree.h"
#include<iostream>
using namespace std;

    node* AVLTree::insert(int data, node* root)
    {
        if(root == NULL)
        {
            root = new node;
            root->data = data;
            root->left =  NULL;
            root->right = NULL;
            root->height = 1; 

            return root;
        }
        else if(data < root->data)
            root->left = insert(data, root->left);
        else if(data > root->data)
            root->right = insert(data, root->right);
        else 
            return root;

        updateHeight(root);
        root = balance(data, root);

        return root;
    }

    node* AVLTree::balance(int data, node* root)
    {
        int heightDifference = getHeight(root->left) - getHeight(root->right);

        if(heightDifference>1)
        {
            if(data<root->left->data)
                return rotateRight(root);

            else if(data>root->left->data)
            {
                root->left = rotateLeft(root->left);
                return rotateRight(root);
            }
        }

        else if(heightDifference<-1)
        {
            if(data>root->right->data)
                return rotateLeft(root);

            else if(data<root->right->data)
            {
                root->right = rotateRight(root->right);
                return rotateLeft(root);
            }
        }

        return root; 
    }

    void AVLTree::updateHeight(node* root)
    {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if(leftHeight>rightHeight)
            root->height = 1 + leftHeight;
        else 
            root->height = 1 + rightHeight;
    }

    int AVLTree::getHeight(node* root)
    {
        int height;
        if(root==NULL)
            height = 0;
        else 
            height = root->height;
        return height;  
    }

    node* AVLTree::rotateRight(node* oldRoot)
    {
        node* newRoot = oldRoot->left;
        node* subtree = newRoot->right;

        newRoot->right = oldRoot;
        oldRoot->left = subtree;

        updateHeight(oldRoot);
        updateHeight(newRoot);

        return newRoot;
    }

    node* AVLTree::rotateLeft(node* oldRoot)
    {
        node* newRoot = oldRoot->right;
        node* subtree = newRoot->left;

        newRoot->left = oldRoot;
        oldRoot->right = subtree;

        updateHeight(oldRoot);
        updateHeight(newRoot);

        return newRoot;
    }

    bool AVLTree::find(node* root, int data)
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

    void AVLTree::printInOrder(node *root)
    {
        if(root == NULL)
            return;
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }

    void AVLTree::printPreOrder(node* root)
    {
        if(root==NULL)
            return;
        cout << root->data << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }

    void AVLTree::printPostOrder(node* root)
    {
        if(root==NULL)
            return;
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->data << " "; 
    }