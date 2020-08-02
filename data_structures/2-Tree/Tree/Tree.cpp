#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

template <typename T>
struct node
{
    node<T>* parent;
    T data;
    list<node<T>*>* children;
};

template <typename T>
class Tree
{
private:
    node<T>* root;
    size_t size;

    node<T>* createNode(node<T>* parent, T data)
    {
        node<T>* tmp = new node<T>;
        tmp->parent = parent;
        tmp->data = data;
        tmp->children = new list<node<T>*>;
    }

public:
    //O(1)
    Tree()
    {
        root = nullptr;
        size = 0;
    }

    //O(1)
    T getRoot()
    {
        return root->data;
    }

    //O(1)
    node<T>* parent(node<T>* node)
    {
        return node->parent;
    }

    //O(1)
    list<node<T>*>* children(node<T>* node)
    {
        return node->children;
    }

    //O(1)
    size_t numChildren(node<T>* node)
    {
        return node->children->size();
    }

    //O(1)
    bool isInternal(node<T>* node)
    {
        return numChildren(node) > 0;
    }

    //O(1)
    bool isExternal(node<T>* node)
    {
        return numChildren(node) == 0;
    }

    //O(1)
    bool isRoot(node<T>* node)
    {
        return node == root;
    }

    //O(1)
    int getSize()
    {
        return size;
    }

    //O(1)
    bool isEmpty()
    {
        return size==0;
    }

    //O(depth) -> O(n) in the worst case (only one long branch)
    bool depth(node<T>* node)
    {
        if (node==root) return 1;
        else return 1+depth(node->parent);
    }

    //O(n*depth) -> O(n^2) in the worst case
    int heightBad()
    {
        cout << "not yet implemented" << endl;
        return -1;
    }

    //O(n)
    int height(node<T>* node)
    {
        int h = 0;
        for (node<T>* child : children(node))
        {
            h = max(h, 1 + height(child));
        }
        return h;
    }

    //O(1)
    node<T>* addRoot(T data)
    {
        if (!isEmpty()) return nullptr;
        node<T>* node = createNode(nullptr, data);
        root = node;
        return root;
    }

    //O(1)
    node<T>* addChild(node<T>* parent, T data)
    {
        node<T>* node = createNode(parent, data);
        list<node<T>*>* children = parent->children;
        children->push_back(node);
        return node;
    }

    //O(1)
    T set(node<T>* node, T data)
    {
        T oldData = node->data;
        node->data = data;
        return oldData;
    }

    //O(1)
    void attach(node<T>* parent, Tree subtree)
    {
        list<node<T>*> children = parent->children;
        node<T>* oldRoot = subtree->root;
        children.push_back(oldRoot);
        oldRoot->parent = parent;
    }
};

int main()
{
    Tree<char> t;
    node<char>* root = t.addRoot('a');
    node<char>* b = t.addChild(root, 'b');
    node<char>* c = t.addChild(root, 'c');
    node<char>* d = t.addChild(c, 'd');
    bool rootExt = t.isExternal(root);
    bool bExt = t.isExternal(b);
    bool cExt = t.isExternal(c);
    bool dExt = t.isExternal(d);
    cout << rootExt << " " << bExt << " " << cExt << " " << dExt << " ";
    return 0;
}
