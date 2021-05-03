#pragma once

using namespace std;

template <typename T>
class TreeNode
{
public:
    TreeNode* parent;
    T data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(TreeNode* p, T d) : parent(p), data(d), leftChild(nullptr), rightChild(nullptr) {};
};

template class TreeNode<int>;
