#include <iostream>

using namespace std;

template<typename T>
struct node
{
    T data;
    node<T>* next;
};

template<typename T>
class CircularList
{
private:
    node<T>* tail;
    size_t size;

    node<T>* createNode(T data, node<T>* next)
    {
        node<T>* tmp = new node<T>;
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
    CircularList()
    {
        tail = nullptr;
        size = 0;
    }

    //O(n)
    ~CircularList()
    {
        destroyList(root);
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
        node<T>* current = tail;
        do
        {
            current = current->next;
            cout << current->data << " ";
        }
        while (current != tail);
        cout << endl;
    }

    //O(1)
    T first()
    {
        return isEmpty() ? NULL : tail->next->data;
    }

    //O(1)
    T last()
    {
        return isEmpty() ? NULL : tail->data;
    }

    //O(1)
    void rotate()
    {
        if (!isEmpty()) tail = tail->next;
    }

    //O(1)
    void addFirst(T data)
    {
        if (isEmpty())
        {
            node<T>* tmp = createNode(data, nullptr);
            tmp->next = tmp;
            tail = tmp;
        }
        else
        { 
            node<T>* tmp = createNode(data, tail->next);
            tail->next = tmp;
        }
        size++;
    }

    //O(1)
    void addLast(T data)
    {
        addFirst(data);
        tail = tail->next;
    }

    //O(1)
    T removeFirst()
    {
        if (isEmpty()) return NULL;
        node<T>* removed = tail->next;
        T removedData = removed->data;
        tail->next = tail->next->next;
        delete removed;
        size--;
        return removedData;
    }

    //O(n)
    T removeLast()
    {
        if (isEmpty()) return NULL;
        node<T>* removed = tail;
        T removedData = removed->data;
        node<T>* current = tail->next;
        while (current->next != tail) 
        {
            current = current->next;
        }
        current->next = tail->next;
        tail = current;
        delete removed;
        size--;
        return removedData;
    }
};

int main() {
    CircularList<int> a;
    a.addFirst(1);
    a.printContent();
    a.addFirst(2);
    a.printContent();
    a.addLast(3);   
    a.printContent();
    a.rotate();
    a.printContent();
    a.removeFirst();
    a.printContent();
    a.removeLast();
    a.printContent();
    a.removeLast();
    a.printContent();
    return 0;
}