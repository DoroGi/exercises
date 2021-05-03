#include <vector>
#include <string>
#include <iostream>
#include "Trie.hpp"

TrieNode::TrieNode(TrieNode* p, char d) : parent(p), data(d) {}

char TrieNode::getData()
{
    return data;
}

void TrieNode::setData(char d)
{
    data = d;
}

TrieNode* TrieNode::getParent()
{
    return parent;
}

std::vector<TrieNode*> TrieNode::getChildren()
{
    return children;
}

TrieNode* TrieNode::addChild(char d)
{
    TrieNode* result = new TrieNode(this, d);
    children.push_back(result);
    return result;
}

bool TrieNode::contains(std::string str)
{
    if (str.size() <= 1) return true;

    for (TrieNode* child : children)
    {
        if (data == str[0]) 
        {
            str.erase(str.begin());
            return child->contains(str);
        }
    }
    return false;
}