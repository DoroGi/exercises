#pragma once

template<typename T>
class Queue
{
private:
    struct node
    {
        T data;
        node* next;
        node(T d, node* n) {
            data = d;
            next = n;
        }
    };
    node* first;
    node* last;
public:
    Queue();
    ~Queue();
    T peek();
    T remove();
    void add(T data);
    bool isEmpty();
    void printContent();
};
