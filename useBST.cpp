#include "BST.h"

#include <iostream>
using namespace std;

int main()
{
    BST tree;
    if(tree.root== nullptr)
        cout << "NULL PTR" << endl; 

    tree.insert(20);
    cout << tree.root->data << endl; 

    if(tree.root->left== nullptr)
        cout << "NULL PTR" << endl; 

    tree.insert(30);
    cout << tree.root->right->data << endl; 
    
    cout << tree.search(20) << endl;
    cout << tree.search(0) << endl; 

    tree.insert(10);
    cout << tree.root->left->data << endl; 

    tree.printInOrder();
    cout << endl;
    tree.printPreOrder();
    cout << endl;

    tree.printPostOrder();
    tree.remove(20);
    //cout << tree.root->data << endl;
    //cout << tree.root->left->data << endl; 

    return 0;
}