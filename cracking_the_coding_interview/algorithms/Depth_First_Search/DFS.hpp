#pragma once
#include <vector>

class node
{
public:
    char data;
    std::vector<node*> children;
    bool marked;
    node(char d) : data(d), marked(false) {};
};

void DFS(node* current);
