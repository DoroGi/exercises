#include "TreeNode.hpp"

using namespace std;

template<typename T>
TreeNode<T>::TreeNode(TreeNode* p, T d) : parent(p), data(d), leftChild(nullptr), rightChild(nullptr) {};

template<typename T>
T TreeNode<T>::getData() const
{
    return data;
}

template<typename T>
TreeNode<T>* TreeNode<T>::getParent() const
{
    return parent;
}

template<typename T>
TreeNode<T>* TreeNode<T>::getLeftChild() const 
{
    return leftChild;
}

template<typename T>
TreeNode<T>* TreeNode<T>::getRightChild() const 
{
    return rightChild;
}

template<typename T>
void TreeNode<T>::setData(const T newData)
{
    data = newData;
}

template<typename T>
void TreeNode<T>::setLeftChild(const T data)
{
    leftChild = new TreeNode<T>(this, data);
}

template<typename T>
void TreeNode<T>::setRightChild(const T data)
{
    rightChild = new TreeNode<T>(this, data);
}

template<class T>
void TreeNode<T>::removeLeftChild()
{
    delete leftChild;
    leftChild = nullptr;
}

template<class T>
void TreeNode<T>::removeRightChild()
{
    delete rightChild;
    rightChild = nullptr;
}

template class TreeNode<int>;
