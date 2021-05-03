#include <iostream>
#include "../../data_structures/1-LinkedList/DoubleLinkedList/DoubleLinkedList.hpp"

using namespace std;

//O(n)
template <typename T>
DoubleLinkedList<T>* partition(DoubleLinkedList<T>* list, T pivot)
{
    DoubleLinkedList<T>* partitioned = new DoubleLinkedList<int>;
    node<T>* current = list->first();
    while(current != nullptr)
    {
        if(current->data >= pivot) partitioned->addLast(current->data);
        else partitioned->addFirst(current->data);
        current = current->next;
    }
    return partitioned;
}

int main()
{
    DoubleLinkedList<int>* list = new DoubleLinkedList<int>;
    list->addFirst(12);
    list->addFirst(3);
    list->addFirst(2);
    list->addFirst(8);
    list->addFirst(9);
    list->addFirst(5);
    list->addFirst(11);
    list->addFirst(6);
    list->addFirst(12);
    list->addFirst(44);
    list->addFirst(23);
    list->printContent();
    DoubleLinkedList<int>* partitioned = partition(list, 11);
    partitioned->printContent();
    delete list;
    delete partitioned;
    return 0;
}