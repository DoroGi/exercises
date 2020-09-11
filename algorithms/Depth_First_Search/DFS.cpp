#include <iostream>
#include "DFS.hpp"

void DFS(node* current)
{
    std::cout << current->data << " "; 
    current->marked = true;
    for (node* next : current->children)
    {
        if (!next->marked) DFS(next);
    }
}