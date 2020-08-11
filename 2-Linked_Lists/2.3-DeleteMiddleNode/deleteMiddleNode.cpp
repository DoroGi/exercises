#include <iostream>
#include "../../data_structures/1-LinkedList/SingleLinkedList/SingleLinkedList.hpp"

using namespace std;

template <typename T>
void removeMiddleNode(SingleLinkedList<T>* list, node<T>* currentNode)
{
    node<T>* toBeDeleted = currentNode->next;
    currentNode->data = toBeDeleted->data;
    currentNode->next = toBeDeleted->next;
    delete toBeDeleted;
}

int main()
{
    SingleLinkedList<int>* list = new SingleLinkedList<int>;
    list->addFirst(3);
    list->addFirst(2);
    list->addFirst(3);
    list->addFirst(4);
    list->addFirst(2);
    list->addFirst(3);
    list->addFirst(5);
    list->printContent();
    node<int>* aNode = list->first()->next->next->next->next;
    cout << "Removing " << aNode->data << "..." << endl;
    removeMiddleNode(list, aNode);
    list->printContent();
    delete list;
    return 0;
}