#pragma once
#include <cstddef>

template <typename T>
struct node
{
    node<T>* prev;
    T data;
    node<T>* next;
};

template <typename T>
class DoubleLinkedList
{
private:
    node<T>* head;
    node<T>* tail;
    size_t size;
    node<T>* createNode(node<T>* prev, T data, node<T>* next);
    void destroyList(node<T>* head);
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    size_t getSize();
    bool isEmpty();
    void printContent();
    node<T>* first();
    node<T>* last();
    void addFirst(T data);
    void addLast(T data);
    T removeFirst();
    T removeLast();
    T remove(node<T>* node);
};
