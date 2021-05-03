#pragma once
#include <cstddef>

template<typename T>
struct node
{
    T data;
    node *next;
};

template<typename T>
class SingleLinkedList
{
private:
    node<T> *head, *tail;
    size_t size;
    node<T>* createNode(T data, node<T>* next);
    void destroyList(node<T>* head);
public:
    SingleLinkedList();
    ~SingleLinkedList();
    size_t getSize();
    bool isEmpty();
    void printContent();
    node<T>* first();
    node<T>* last();
    void addFirst(T newData);
    void addLast(T newData);
    T removeFirst();
    T removeLast();
};
