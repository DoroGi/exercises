#include <iostream>
#include <unordered_set>
#include "../../data_structures/1-LinkedList/DoubleLinkedList/DoubleLinkedList.hpp"

using namespace std;

//Solution to follow up question:
//Without additional data structures O(n^2)
template <typename T>
DoubleLinkedList<T>* removeDups(DoubleLinkedList<T>* list)
{
    if (list->isEmpty()) return list;
    node<T>* p1 = list->first();
    node<T>* p2 = list->first();
    while (p1 != nullptr)
    {
        p2 = p1->next;
        while(p2 != nullptr)
        {
            if (p1->data == p2->data) list->remove(p2);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return list;
}

int main()
{
    DoubleLinkedList<int>* list = new DoubleLinkedList<int>;
    list->addFirst(3);
    list->addFirst(2);
    list->addFirst(3);
    list->addFirst(4);
    list->addFirst(2);
    list->addFirst(3);
    list->addFirst(5);
    list->printContent();
    DoubleLinkedList<int>* dedupled = removeDups(list);
    list->printContent();

    delete list;
    return 0;
}
