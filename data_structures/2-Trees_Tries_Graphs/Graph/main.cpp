#include <iostream>
#include <vector>
#include "Graph.hpp"

int main () 
{
    node<int> node1 = node<int>(1);
    node<int> node2 = node<int>(2);
    node<int> node3 = node<int>(3);
    node<int> node4 = node<int>(4);
    node<int> node5 = node<int>(5);
    node1.children.push_back(&node2);
    node1.children.push_back(&node3);
    node1.children.push_back(&node4);
    node2.children.push_back(&node1);
    node2.children.push_back(&node3);
    node2.children.push_back(&node4);
    node4.children.push_back(&node5);
    node5.children.push_back(&node4);
    bool firstAndFifthAreConnected = node1.children[0]->children[2]->children[0]->data == node5.data;
    std::cout << (firstAndFifthAreConnected ? "yes" : "no") << std::endl;
    return 0;
}