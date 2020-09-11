#include <iostream>
#include <queue>
#include "BFS.hpp"

void BFS(node* root)
{
    std::queue<node*> q;
    std::cout << root->data << " ";
    root->marked = true;
    q.push(root);

    while (!q.empty())
    {
        node* current = q.front();
        q.pop();
        current->marked = true;
        for (node* adjacent : current->children)
        {
            if (adjacent->marked != true)
            {
                std::cout << adjacent->data << " ";
                adjacent->marked = true;
                q.push(adjacent);
            }
        }
    }
}