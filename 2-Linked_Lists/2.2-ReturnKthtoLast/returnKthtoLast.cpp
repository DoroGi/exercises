#include <iostream>
#include "../../data_structures/1-LinkedList/SingleLinkedList/SingleLinkedList.hpp"

using namespace std;

//O(n)
template <typename T>
T returnKthtoLast(SingleLinkedList<T>* list, int k)
{
    node<T>* p1 = list->first();
    node<T>* p2 = list->first();
    for (int i=0; i<k-1; i++)
    {
        p2 = p2->next;
    }
    while (p2->next != nullptr)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1->data;
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
    int result = returnKthtoLast(list, 3);
    cout << result << endl;
    return 0;
}