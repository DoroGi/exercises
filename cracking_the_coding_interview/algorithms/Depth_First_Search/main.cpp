#include <iostream>
#include <vector>
#include "DFS.hpp"

int main () 
{
    node node1 = node('a');
    node node2 = node('b');
    node node3 = node('c');
    node node4 = node('d');
    node node5 = node('e');
    node1.children.push_back(&node2);
    node1.children.push_back(&node4);
    node1.children.push_back(&node3);
    node2.children.push_back(&node1);
    node2.children.push_back(&node4);
    node2.children.push_back(&node3);
    node4.children.push_back(&node5);
    node5.children.push_back(&node4);
    DFS(&node1);
    return 0;
}