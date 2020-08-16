#include <iostream>
#include <stack>

using namespace std;

class queueViaStack
{
private:
    bool usingReverse;
    stack<int>* right; 
    stack<int>* reverse;

    //O(n)
    void switchStacks(stack<int>* from, stack<int>* to)
    {
        cout << "switching stacks..." << endl;
        while(!from->empty())
        {
            int elm = from->top();
            from->pop();
            to->push(elm);
        }
        usingReverse = !usingReverse;
    }

public:
    queueViaStack()
    {
        usingReverse = false;
        right = new stack<int>;
        reverse = new stack<int>;
    }

    ~queueViaStack()
    {
        delete right;
        delete reverse;
    }
    
    //O(n) amortized to O(1) for many subsequent calls
    void push(int data)
    {
        if(usingReverse) switchStacks(reverse, right);
        right->push(data);
    }

    //O(n) amortized to O(1) for many subsequent calls
    int peek()
    {
        if(!usingReverse) switchStacks(right, reverse);
        return reverse->top();
    }

    //O(n) amortized to O(1) for many subsequent calls
    int pop()
    {
        if(!usingReverse) switchStacks(right, reverse);
        int value = reverse->top();
        reverse->pop();
        return value;
    }
};

int main()
{
    queueViaStack* q = new queueViaStack();
    q->push(1);
    q->push(2);
    q->push(3);
    q->push(4);
    q->push(5);
    q->push(6);
    cout << q->peek() << endl;
    q->pop();
    cout << q->peek() << endl;
    q->push(6);
    q->pop();
    cout << q->peek() << endl;
    q->pop();
    cout << q->peek() << endl;
    return 0;
}
