#include <iostream>
#include "SingleLinkedList.hpp"

using namespace std;

template <typename T>
node<T>* SingleLinkedList<T>::createNode(T data, node<T>* next)
{
    node<T> *tmp = new node<T>;
    tmp->data = data;
    tmp->next = next;
    return tmp;
}

template <typename T>
void SingleLinkedList<T>::destroyList(node<T>* head)
{
    if (head != nullptr)
    {
        destroyList(head->next);
        delete head;
    }
}

//O(1)
template <typename T>
SingleLinkedList<T>::SingleLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

//O(n)
template <typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
    destroyList(head);
}

//O(1)
template <typename T>
size_t SingleLinkedList<T>::getSize()
{
    return size;
}

//O(1)
template <typename T>
bool SingleLinkedList<T>::isEmpty()
{
    return size==0;
}

//O(n)
template <typename T>
void SingleLinkedList<T>::printContent()
{
    if (isEmpty()) return;

    node<T> *current = head;
    do
    {
        cout << current->data;
        current = current->next;
    }
    while(current != nullptr);
    cout << endl;
}

//O(1)
template <typename T>
node<T>* SingleLinkedList<T>::first()
{
    return isEmpty() ? NULL : head;
}

//O(1)
template <typename T>
node<T>* SingleLinkedList<T>::last()
{
    return isEmpty() ? NULL : tail;
}

//O(1)
template <typename T>
void SingleLinkedList<T>::addFirst(T newData)
{
    node<T> *tmp = createNode(newData, head);
    head = tmp;
    if (isEmpty()) tail = head;
    size++;
}

//O(1)
template <typename T>
void SingleLinkedList<T>::addLast(T newData)
{
    node<T> *tmp = createNode(newData, nullptr);
    if (isEmpty())
    {
        head = tail = tmp;
    }
    else 
    {
        tail->next = tmp;
        tail = tmp;
    }
    size++;
}

//O(1)
template <typename T>
T SingleLinkedList<T>::removeFirst()
{
    if (isEmpty()) return NULL;
    node<T> *removed = head;
    T removedData = removed->data;
    head = removed->next;
    size--;
    if (isEmpty()) tail = nullptr;
    delete removed;
    return removedData;
}

//O(n)
template <typename T>
T SingleLinkedList<T>::removeLast()
{
    if (isEmpty()) return NULL;
    node<T> *removed = tail;
    T removedData = removed->data;
    
    node<T> *current = head;
    while(current->next != nullptr)
    {
        if (current->next->next == nullptr) current->next = nullptr;
        else current = current->next;
    }
    tail = current;
    size--;
    delete removed;
    return removedData;
}

template class SingleLinkedList<int>;
template class SingleLinkedList<string>;