#include <iostream>
#include "Trie.hpp"

int main()
{
    TrieNode root = TrieNode(nullptr, 'h');
    TrieNode* heNode = root.addChild('e');
    TrieNode* helNode = heNode->addChild('l');
    TrieNode* hellNode = helNode->addChild('l');
    TrieNode* helpNode = helNode->addChild('p');
    TrieNode* helloNode = hellNode->addChild('o');
    std::cout << (root.contains("hello") ? "yes" : "no") << std::endl;
    std::cout << (root.contains("help") ? "yes" : "no") << std::endl;
    std::cout << (root.contains("he") ? "yes" : "no") << std::endl;
    std::cout << (root.contains("yooo") ? "yes" : "no") << std::endl;
    return 0;
}