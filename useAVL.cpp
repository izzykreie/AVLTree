#include "AVLTree.h"
#include <iostream>
using namespace std;

int main()
{
    AVLTree tree;
    node* root = NULL;

    root = tree.insert(20, root);
    cout << root->data << endl; 
    cout << "Root height:" << root->height << endl; 
 
    root = tree.insert(10, root);
    root = tree.insert(5, root);
    root = tree.insert(20, root);
    root = tree.insert(15, root);
    root = tree.insert(30, root);
    root = tree.insert(40, root);


    cout << root->data << endl;
    tree.printInOrder(root);

    return 0;
}