#pragma once
#include <vector>

template <typename T>
class node
{
public:
    T data;
    std::vector<node*> children;
    node(T d);
};

template class node<int>;
template class node<char>;