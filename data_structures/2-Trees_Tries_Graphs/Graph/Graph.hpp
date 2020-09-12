#pragma once
#include <vector>

template <typename T>
class node
{
public:
    T data;
    bool marked;
    std::vector<node*> children;
    node(T d) : data(d), marked(false) {};
};

template class node<int>;
template class node<char>;