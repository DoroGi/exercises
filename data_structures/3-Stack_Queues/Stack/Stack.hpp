#pragma once

template<typename T>
class Stack
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
    node* top;
public:
    Stack();
    ~Stack();
    T peek();
    T pop();
    void push(T data);
    bool isEmpty();
    void printContent();
};
