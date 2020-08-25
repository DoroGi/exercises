#include <iostream>
#include "TreeNode.hpp"

int main()
{
    TreeNode<int> root = TreeNode<int>(nullptr, 123);
    root.setLeftChild(55);
    root.setRightChild(643);   
    cout << root.getData() << " " << root.getLeftChild()->getData() << " " << root.getRightChild()->getData() << " ";
    return 0;
}
