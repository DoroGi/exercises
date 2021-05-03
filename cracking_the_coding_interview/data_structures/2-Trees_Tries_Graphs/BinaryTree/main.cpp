#include <iostream>
#include "TreeNode.hpp"

int main()
{
    TreeNode<int> root = TreeNode<int>(nullptr, 123);
    root.leftChild = &TreeNode<int>(&root, 55);
    root.rightChild = &TreeNode<int>(&root, 643);   
    cout << root.data << " " << root.leftChild->data << " " << root.rightChild->data << " ";
    return 0;
}
