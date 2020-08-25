#pragma once

using namespace std;

template <typename T>
struct TreeNode
{
private:
    TreeNode* parent;
    T data;
    TreeNode* leftChild;
    TreeNode* rightChild;
public:
    TreeNode(TreeNode* p, T d);
    
    T getData() const;
    TreeNode* getParent() const;
    TreeNode* getLeftChild() const;
    TreeNode* getRightChild() const;
    
    void setData(const T data);
    void setLeftChild(const T data);
    void setRightChild(const T data);
    void removeLeftChild();
    void removeRightChild();
};
