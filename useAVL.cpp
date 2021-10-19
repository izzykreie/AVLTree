#include "AVLTree.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    AVLTree tree;
    node* root = NULL;

    int num;
    string line;
    ifstream AVL_tests("AVL_tests.txt");
    if (AVL_tests.is_open())
    {
        while(getline (AVL_tests,line))
        {
            num = std::stoi(line);
            root = tree.insert(num,root);
        }
        AVL_tests.close();
    } 
    
    tree.printPreOrder(root);

    return 0;
}