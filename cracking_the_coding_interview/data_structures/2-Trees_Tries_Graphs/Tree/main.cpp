#include <iostream>
#include "Tree.hpp"

int main()
{
    Tree<char>* t = new Tree<char>;
    node<char>* root = t->addRoot('a');
    node<char>* b = t->addChild(root, 'b');
    node<char>* c = t->addChild(root, 'c');
    node<char>* d = t->addChild(c, 'd');
    bool rootExt = t->isExternal(root);
    bool bExt = t->isExternal(b);
    bool cExt = t->isExternal(c);
    bool dExt = t->isExternal(d);
    cout << rootExt << " " << bExt << " " << cExt << " " << dExt << " ";
    return 0;
}
