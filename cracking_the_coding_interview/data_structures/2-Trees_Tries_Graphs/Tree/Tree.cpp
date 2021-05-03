#include <iostream>
#include <vector>
#include <algorithm>
#include "Tree.hpp"

using namespace std;

template <typename T>
Tree<T>::Tree()
{
    root = nullptr;
    size = 0;
}

//O(1)
template <typename T>
node<T>* Tree<T>::getRoot()
{
    return root;
}

//O(1)
template <typename T>
node<T>* Tree<T>::parent(node<T>* node)
{
    return node->parent;
}

//O(1)
template <typename T>
vector<node<T>*>* Tree<T>::getChildren(node<T>* node)
{
    return node->children;
}

//O(1)
template <typename T>
size_t Tree<T>::numChildren(node<T>* node)
{
    return node->children->size();
}

//O(1)
template <typename T>
bool Tree<T>::isInternal(node<T>* node)
{
    return numChildren(node) > 0;
}

//O(1)
template <typename T>
bool Tree<T>::isExternal(node<T>* node)
{
    return numChildren(node) == 0;
}

//O(1)
template <typename T>
bool Tree<T>::isRoot(node<T>* node)
{
    return node == root;
}

//O(1)
template <typename T>
int Tree<T>::getSize()
{
    return size;
}

//O(1)
template <typename T>
bool Tree<T>::isEmpty()
{
    return size==0;
}

//O(depth) -> O(n) in the worst case (only one long branch)
template <typename T>
bool Tree<T>::depth(node<T>* node)
{
    if (node==root) return 1;
    else return 1+depth(node->parent);
}

//O(n*depth) -> O(n^2) in the worst case
template <typename T>
int Tree<T>::heightBad()
{
    cout << "not yet implemented" << endl;
    return -1;
}

//O(n)
template <typename T>
int Tree<T>::height(node<T>* topNode)
{
    int h = 0;
    vector<node<T>*>* nodeChildren = getChildren(topNode);
    for (int i=0; i< nodeChildren->size(); i++)
    {
        node<T>* child = nodeChildren->at(i);
        h = max(h, 1 + height(child));
    }
    return h;
}

//O(1)
template <typename T>
node<T>* Tree<T>::addRoot(T data)
{
    if (!isEmpty()) return nullptr;
    node<T>* newRoot = new node<T>(nullptr, data);
    root = newRoot;
    return root;
}

//O(1)
template <typename T>
node<T>* Tree<T>::addChild(node<T>* parent, T data)
{
    vector<node<T>*>* children = parent->children;
    node<T>* newChild = new node<T>(parent, data);
    children->push_back(newChild);
    return newChild;
}

//O(1)
template <typename T>
T Tree<T>::set(node<T>* node, T data)
{
    T oldData = node->data;
    node->data = data;
    return oldData;
}

//O(1)
template <typename T>
void Tree<T>::attach(node<T>* parent, Tree* subtree)
{
    vector<node<T>*>* children = parent->children;
    node<T>* oldRoot = subtree->root;
    children->push_back(oldRoot);
    oldRoot->parent = parent;
}

template class Tree<int>;
template class Tree<char>;
