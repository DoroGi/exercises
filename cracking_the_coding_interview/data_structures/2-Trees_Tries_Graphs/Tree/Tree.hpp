#pragma once
#include <vector>

using namespace std;

template <typename T>
class node
{
    node<T>* parent;
    T data;
    vector<node<T>*>* children;
    node(node<T>* p, T d)
    {
        parent = p;
        data = d;
        children = new vector<node<T>*>;
    }
};

template <typename T>
class Tree
{
private:
    node<T>* root;
    size_t size;
    int heightBad();

public:
    Tree();
    node<T>* getRoot();
    node<T>* parent(node<T>* node);
    vector<node<T>*>* getChildren(node<T>* node);
    size_t numChildren(node<T>* node);
    bool isInternal(node<T>* node);
    bool isExternal(node<T>* node);
    bool isRoot(node<T>* node);
    int getSize();
    bool isEmpty();
    bool depth(node<T>* node);
    int height(node<T>* node);
    node<T>* addRoot(T data);
    node<T>* addChild(node<T>* parent, T data);
    T set(node<T>* node, T data);
    void attach(node<T>* parent, Tree* subtree);
};

