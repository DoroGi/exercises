#include "../../data_structures/1-LinkedList/SingleLinkedList/SingleLinkedList.hpp"

struct partial
{
    SingleLinkedList<int>* partialResult;
    int carry;
};

//O(n)
partial* sumLists(node<int>* n1, node<int>* n2, partial* pt)
{
    if (n1 == nullptr) return pt;
    
    pt = sumLists(n1->next, n2->next, pt);
    
    int sum = n1->data + n2->data + pt->carry;
    int units = sum % 10;
    int carry = sum / 10;
    pt->partialResult->addFirst(units);
    pt->carry = carry;
    return pt;
}

//O(n)
void padList(SingleLinkedList<int>* list, int k)
{
    for (int i=0; i < k; i++) list->addFirst(0);
}

//O(n)
SingleLinkedList<int>* sumLists(SingleLinkedList<int>* l1, SingleLinkedList<int>* l2)
{
    int len1 = l1->getSize();
    int len2 = l2->getSize();
    if (len1 > len2) padList(l2, len1 - len2);
    else padList(l1, len2 - len1);

    partial* partialSum = new partial;
    partialSum->partialResult = new SingleLinkedList<int>;
    partialSum->carry = 0;

    partial* result = sumLists(l1->first(), l2->first(), partialSum);
    if (result->carry > 0) result->partialResult->addFirst(result->carry);
    return result->partialResult;
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