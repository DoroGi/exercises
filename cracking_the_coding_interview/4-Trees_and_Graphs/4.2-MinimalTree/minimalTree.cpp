#include <vector>
#include <iostream>
#include "..\..\data_structures\2-Trees_Tries_Graphs\BinaryTree\TreeNode.hpp"

TreeNode<int>* minimalTree(std::vector<int> array, TreeNode<int>* parent, int start, int end)
{
    if (end < start) {
        std::cout << "go back" << std::endl;
        return nullptr;
    }
    int mid =  (end + start) / 2;
    std::cout << "current: " << array.at(mid) << " position: " << mid << std::endl;
    std::cout << start << " " << end << " " << std::endl;
    if (parent != nullptr) std::cout << "parent: " << parent->data << std::endl;
    TreeNode<int>* root = new TreeNode<int>(parent, array.at(mid));
    std::cout << "setLeft di : " << array.at(mid) << std::endl;
    root->leftChild = minimalTree(array, root, start, mid-1);
    std::cout << "setRight di : " << array.at(mid) << std::endl;
    root->rightChild = minimalTree(array, root, mid+1, end);
    return root;
}

TreeNode<int>* minimalTree(std::vector<int> array)
{
    return minimalTree(array, nullptr, 0, (array.size())-1);
}

int main ()
{
    std::vector<int> data = {1,2,6,7,8,10,13,23,34,566,678,789,2332,234567};
    TreeNode<int>* root = minimalTree(data);
 
    TreeNode<int>* leftChild = root->leftChild;
    TreeNode<int>* rightChild = root->rightChild;
    std::cout << root->data << std::endl;
    std::cout << leftChild->data << " " << rightChild->data << std::endl;
    std::cout << leftChild->leftChild->data << " " << leftChild->rightChild->data << std::endl;
    std::cout << leftChild->leftChild->rightChild->data << " " << leftChild->rightChild->leftChild->data << " " << leftChild->rightChild->rightChild->data << std::endl;
    return 0;
}