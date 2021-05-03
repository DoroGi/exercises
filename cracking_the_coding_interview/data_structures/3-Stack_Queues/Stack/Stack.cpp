#include <iostream>
#include <string>
#include "Stack.hpp"

using namespace std;

template<typename T>
Stack<T>::Stack()
{
    top = nullptr;
}

template<typename T>
Stack<T>::~Stack()
{
    node* current = top;
    while(current != nullptr)
    {
        node* next = current->next;
        delete current;
        current=next;
    }
}

template<typename T>
T Stack<T>::peek()
{
    return top->data;
}

template<typename T>
T Stack<T>::pop()
{
    T oldData = top->data;
    node* oldNext = top->next;
    delete top;
    top=oldNext;
    return oldData;
};

template<typename T>
void Stack<T>::push(T data)
{
    node* newNode = new node(data, top);
    top = newNode;
};

template<typename T>
bool Stack<T>::isEmpty()
{
    return top==nullptr;
};

template<typename T>
void Stack<T>::printContent()
{
    node* current = top;
    while(current != nullptr)
    {
        cout << current->data << ' ';
        current = current->next;
    }
};

template class Stack<int>;
template class Stack<string>;
