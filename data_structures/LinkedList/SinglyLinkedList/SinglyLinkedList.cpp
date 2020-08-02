#include <iostream>

using namespace std;

template<typename T>
struct node
{
    T data;
    node *next;
};

template<typename T>
class LinkedList
{
private:
    node<T> *head, *tail;
    size_t size;

    node<T>* createNode(T data, node<T>* next)
    {
        node<T> *tmp = new node<T>;
        tmp->data = data;
        tmp->next = next;
        return tmp;
    }

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    //O(1)
    size_t getSize()
    {
        return size;
    }

    //O(1)
    bool isEmpty()
    {
        return size==0;
    }

    //O(n)
    void printContent()
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
    T first()
    {
        return isEmpty() ? NULL : head->data;
    }

    //O(1)
    T last()
    {
        return isEmpty() ? NULL : tail->data;
    }

    //O(1)
    void addFirst(T newData)
    {
        node<T> *tmp = createNode(newData, head);
        head = tmp;
        if (isEmpty()) tail = head;
        size++;
    }
    
    //O(1)
    void addLast(T newData)
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
    T removeFirst()
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
    T removeLast()
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
};

int main() {
    LinkedList<int> a;
    a.addFirst(1);
    a.printContent();
    a.addFirst(2);
    a.printContent();
    a.addLast(3);   
    a.printContent();
    a.removeFirst();
    a.printContent();
    a.removeLast();
    a.printContent();
    a.removeLast();
    a.printContent();
    return 0;
}