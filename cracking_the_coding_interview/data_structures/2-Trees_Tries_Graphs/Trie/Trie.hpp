#pragma once
#include <vector>
#include <string>

class TrieNode {
private:
    TrieNode* parent;
    char data;
    std::vector<TrieNode*> children;
public:
    TrieNode(TrieNode* p, char d);
    char getData();
    void setData(char);
    TrieNode* getParent();
    std::vector<TrieNode*> getChildren();
    TrieNode* addChild(char);
    bool contains(std::string str);
};
