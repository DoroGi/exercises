#include <iostream>
#include <string>
#include "../../data_structures/1-LinkedList/SingleLinkedList/SingleLinkedList.hpp"

using namespace std;

template <typename T>
size_t findSize(SingleLinkedList<T>* list)
{
    size_t size = 0;
    node<T>* current = list->first();
    while (current != nullptr)
    {
        size++;
        current = current->next;
    }
    return size;
}

template <typename T>
node<T>* findLast(SingleLinkedList<T>* list)
{
    node<T>* current = list->last();
    while (current->next != nullptr)
    {
        current = current->next;
    }
    return current;

}

//O(n)
template <typename T>
node<T>* intersection(SingleLinkedList<T>* l1, SingleLinkedList<T>* l2)
{
    //First trivial check
    if (findLast(l1) != findLast(l2)) return nullptr;
    
    //Discard node that are surely not shared
    node<T>* p1 = l1->first();
    node<T>* p2 = l2->first();
    size_t len1 = findSize(l1);
    size_t len2 = findSize(l2);
    if (len1 > len2)
    {
        int sizeDiff = len1 - len2;
        for (int i=0; i < sizeDiff; i++)
        {
            p1 = p1->next;
        }
    }
    else
    {
        int sizeDiff = len2 - len1;
        for (int i=0; i < sizeDiff; i++)
        {
            p2 = p2->next;
        }
    }

    //Check all remaining nodes
    while(p1 != nullptr && p2 != nullptr)
    {
        if (p1==p2) return p1;
        p1 = p1->next;
        p2 = p2->next;
    }

    return nullptr;
}

int main()
{
    SingleLinkedList<int>* l1 = new SingleLinkedList<int>;
    l1->addFirst(6);
    l1->addFirst(5);
    l1->addFirst(4);
    l1->addFirst(3);
    l1->addFirst(2);
    l1->addFirst(1);
    node<int>* shared = l1->first()->next->next->next;

    SingleLinkedList<int>* l2 = new SingleLinkedList<int>;
    l2->addFirst(6);
    l2->addFirst(5);
    l2->addFirst(3);
    l2->addFirst(2);
    l2->addFirst(1);

    SingleLinkedList<int>* l3 = new SingleLinkedList<int>;
    l3->addFirst(12);
    l3->addFirst(11);
    l3->last()->next = shared;
    
    string res1 = intersection(l1, l2)==nullptr ? "no" : "yes";
    string res2 = intersection(l1, l3)==nullptr ? "no" : "yes";
    cout << res1 << endl;
    cout << res2 << endl;
    delete l1;
    delete l2;
    delete l3;
    return 0;
}