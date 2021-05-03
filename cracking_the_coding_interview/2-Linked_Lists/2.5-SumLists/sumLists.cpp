#include <iostream>
#include "../../data_structures/1-LinkedList/SingleLinkedList/SingleLinkedList.hpp"

//O(n)
SingleLinkedList<int>* sumLists(node<int>* n1, node<int>* n2, int remainder)
{
    int firstNum = n1 == nullptr ? 0 : n1->data;
    int secondNum = n2 == nullptr ? 0 : n2->data;
    int sum = firstNum + secondNum + remainder;
    if (sum == 0) return new SingleLinkedList<int>;

    int partial = sum % 10;
    int carry = sum / 10;
    node<int>* n1Next = n1 == nullptr ? nullptr : n1->next;
    node<int>* n2Next = n2 == nullptr ? nullptr : n2->next;
    SingleLinkedList<int>* rest = sumLists(n1Next, n2Next, carry);
    rest->addFirst(partial);
    return rest;
}

//O(n)
SingleLinkedList<int>* sumLists(SingleLinkedList<int>* l1, SingleLinkedList<int>* l2)
{
    return sumLists(l1->first(), l2->first(), 0);
}

int main()
{
    SingleLinkedList<int>* l1 = new SingleLinkedList<int>;
    l1->addFirst(1);
    l1->addFirst(0);
    l1->addFirst(1);
    l1->printContent();
    SingleLinkedList<int>* l2 = new SingleLinkedList<int>;
    l2->addFirst(9);
    l2->addFirst(9);
    l2->addFirst(9);
    l2->addFirst(9);
    l2->addFirst(9);
    l2->addFirst(9);
    l2->printContent();
    SingleLinkedList<int>* l3 = sumLists(l1, l2);
    l3->printContent();
    delete l1;
    delete l2;
    delete l3;
    return 0;
}