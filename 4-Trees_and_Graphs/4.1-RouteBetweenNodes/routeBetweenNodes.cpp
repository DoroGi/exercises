#include <vector>
#include <queue>
#include <iostream>
#include "../../data_structures/2-Trees_Tries_Graphs/Graph/Graph.hpp"

bool routeBetweenNodes(node<char>* start, node<char>* target)
{
    std::queue<node<char>*> q;
    start->marked = true;
    q.push(start);
    while (!q.empty())
    {
        node<char>* current = q.front();
        q.pop();
        current->marked = true;
        for (node<char>* adjacent : current->children)
        {
            if (adjacent == target) return true;
            if (!adjacent->marked)
            {
                adjacent->marked = true;
                q.push(adjacent);
            }
        }
    }
    return false;
}

int main () 
{
    node<char> node1 = node<char>('a');
    node<char> node2 = node<char>('b');
    node<char> node3 = node<char>('c');
    node<char> node4 = node<char>('d');
    node<char> node5 = node<char>('e');
    node<char> node6 = node<char>('f');
    node1.children.push_back(&node2);
    node1.children.push_back(&node3);
    node1.children.push_back(&node4);
    node2.children.push_back(&node1);
    node2.children.push_back(&node3);
    node2.children.push_back(&node4);
    node4.children.push_back(&node5);
    node5.children.push_back(&node4);
    bool firstAndFifthAreConnected = routeBetweenNodes(&node1, &node5);
    bool firstAndSixthAreConnected = routeBetweenNodes(&node1, &node6);
    std::cout << (firstAndFifthAreConnected ? "yes" : "no") << std::endl;
    std::cout << (firstAndSixthAreConnected ? "yes" : "no") << std::endl;
    return 0;
}