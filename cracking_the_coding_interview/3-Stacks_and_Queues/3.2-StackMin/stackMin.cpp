#include <iostream>
#include <stack>

using namespace std;

class stackMin
{
private:
    struct node
    {
        int data;
        node* next;
        node(int d, node* n)
        {
            data = d;
            next = n;
        }
    };
    node* top;
    stack<int> mins;

public:
    stackMin()
    {
        top=nullptr;
    }

    ~stackMin()
    {
        node* current = top;
        while(current != nullptr)
        {
            pop();
            current=top;
        }
    }

    int peek()
    {
        return top->data;
    }

    int min()
    {

        return mins.top();
    }

    int pop()
    {
        int oldData = top->data;
        if (!mins.empty() && mins.top() == oldData)
        {
            mins.pop();
        }
        node* oldNext = top->next;
        delete top;
        top=oldNext;
        return oldData;
    }

    void push(int data)
    {
        node* newNode = new node(data, top);
        top = newNode;
        if (mins.empty() || (!mins.empty() && data <= mins.top())) 
        {
            mins.push(data);
        }
    }

    bool isEmpty()
    {
        return top==nullptr;
    }

    void printContent()
    {
        node* current = top;
        while(current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main()
{
    stackMin* st = new stackMin;
    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);
    st->push(6);
    cout << st->peek() << endl;
    cout << st->min() << endl;
    cout << endl;
    st->pop();
    st->push(1);
    cout << st->peek() << endl;
    cout << st->min() << endl;
    cout << endl;
    st->push(2);
    st->push(1);
    cout << st->peek() << endl;
    cout << st->min() << endl;
    cout << endl;
    st->pop();
    st->pop();
    cout << st->peek() << endl;
    cout << st->min() << endl;
    cout << endl;
    st->pop();
    st->pop();
    st->pop();
    cout << st->peek() << endl;
    cout << st->min() << endl;
    cout << endl;
    st->printContent();
    return 0;
    
}