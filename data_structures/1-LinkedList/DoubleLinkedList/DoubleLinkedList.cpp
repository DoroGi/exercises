#include <iostream>

using namespace std;

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
    node<T>* createNode(node<T>* prev, T data, node<T>* next)
    {
        node<T>* tmp = new node<T>;
        tmp->prev = prev;
        tmp->data = data;
        tmp->next = next;
        return tmp;
    }
    void destroyList(node<T>* head)
    {
        if (head != nullptr)
        {
            destroyList(head->next);
            delete head;
        }
    }
public:
    //O(1)
    DoubleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    //O(n)
    ~DoubleLinkedList()
    {
        destroyList(head);
    }

    //O(1)
    size_t getSize()
    {
        return size;
    }

    //O(1)
    bool isEmpty()
    {
        return size == 0;
    }

    //O(n)
    void printContent()
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
    void addFirst(T data)
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

    //O(1)
    void addLast(T data)
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

    //O(1)
    T removeFirst()
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

    //O(1)
    T removeLast()
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
};

int main() {
    DoubleLinkedList<int> a;
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