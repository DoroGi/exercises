#include <iostream>
#include "DoubleLinkedList.hpp"

using namespace std;

template <typename T>
node<T>* DoubleLinkedList<T>::createNode(node<T>* prev, T data, node<T>* next)
{
    node<T>* tmp = new node<T>;
    tmp->prev = prev;
    tmp->data = data;
    tmp->next = next;
    return tmp;
}

template <typename T>
void DoubleLinkedList<T>::destroyList(node<T>* head)
{
    if (head != nullptr)
    {
        destroyList(head->next);
        delete head;
    }
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    destroyList(head);
}

template <typename T>
size_t DoubleLinkedList<T>::getSize()
{
    return size;
}

template <typename T>
bool DoubleLinkedList<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
void DoubleLinkedList<T>::printContent()
{
    node<T>* current = head;
    do
    {
        cout << current->data << " ";
        current = current->next;
    }
    while (current != nullptr);
    cout << endl;
}

template <typename T>
node<T>* DoubleLinkedList<T>::first()
{
    return isEmpty() ? NULL : head;
}

template <typename T>
node<T>* DoubleLinkedList<T>::last()
{
    return isEmpty() ? NULL : tail;
}
    
template <typename T>
void DoubleLinkedList<T>::addFirst(T data)
{
    if (isEmpty())
    {
        head = tail = createNode(nullptr, data, nullptr);
    }
    else
    {
        node<T>* tmp = createNode(nullptr, data, head);
        head->prev = tmp;
        head = tmp;
    }
    size++;
}

template <typename T>
void DoubleLinkedList<T>::addLast(T data)
{
    if (isEmpty())
    {
        head = tail = createNode(nullptr, data, nullptr);
    }
    else
    {
        node<T>* tmp = createNode(tail, data, nullptr);
        tail->next = tmp;
        tail = tmp;
    }
    size++;
}

template <typename T>
T DoubleLinkedList<T>::removeFirst()
{
    if (isEmpty()) return NULL;
    node<T>* removed = head;
    T removedData = removed->data;
    head = head->next;
    head->prev = nullptr;
    delete removed;
    size--;
    return removedData;
}

template <typename T>
T DoubleLinkedList<T>::removeLast()
{
    if (isEmpty()) return NULL;
    node<T>* removed = tail;
    T removedData = removed->data;
    tail = tail->prev;
    tail->next = nullptr;
    delete removed;
    size--;
    return removedData;
}

template <typename T>
T DoubleLinkedList<T>::remove(node<T>* node)
{
    if (node == head) head = node->next;
    else node->prev->next = node->next;
    
    if (node == tail) tail = node->prev;
    else node->next->prev = node->prev;
    
    size--;
    T removedData = node->data;
    delete node;
    return removedData;
}

template class DoubleLinkedList<int>;
template class DoubleLinkedList<string>;