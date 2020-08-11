#include <unordered_set>
#include "../DoubleLinkedList.hpp"

using namespace std;

//Solution to first question:
//Using an hashmap O(n)
template <typename T>
DoubleLinkedList<T>* removeDups(DoubleLinkedList<T>* list)
{
    if (list->isEmpty()) return list;
    unordered_set<T> seen;              // Hashmap (key-only)
    node<T>* current = list->first();
    do
    {
        T data = current->data;
        node<T>* next = current->next;
        
        if  (!seen.contains(data)) {    //O(1)
            seen.insert(data);          //O(1)
        }
        else
        {
            list->remove(current);      //O(1)
        }
        current = next;
    }
    while(current != nullptr);          //O(n)
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