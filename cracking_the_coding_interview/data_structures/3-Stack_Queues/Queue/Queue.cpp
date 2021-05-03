#include <iostream>
#include <string>
#include "Queue.hpp"

using namespace std;

template<typename T>
Queue<T>::Queue()
{
    first = nullptr;
    last = nullptr;
}

template<typename T>
Queue<T>::~Queue()
{
    node* current = first;
    while(current != nullptr)
    {
        node* next = current->next;
        delete current;
        current=next;
    }
}

template<typename T>
T Queue<T>::peek()
{
    if(isEmpty()) throw "Queue is empty!";
    return first->data;
}

template<typename T>
T Queue<T>::remove()
{
    if(isEmpty()) throw "Queue is Empty!";
    T oldData = first->data;
    node* oldNext = first->next;
    delete first;
    first=oldNext;
    if (first == nullptr) last=nullptr;
    return oldData;
}

template<typename T>
void Queue<T>::add(T data)
{
    node* newNode = new node(data, nullptr);
    if(last!=nullptr) last->next = newNode;
    last = newNode;
    if(first==nullptr) first = last;
}

template<typename T>
bool Queue<T>::isEmpty()
{
    return first==nullptr;
}

template<typename T>
void Queue<T>::printContent()
{
    node* current = first;
    while(current != nullptr)
    {
        cout << current->data << ' ';
        current = current->next;
    }
    cout << endl;
}

template class Queue<int>;
template class Queue<string>;
