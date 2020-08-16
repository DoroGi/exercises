#include <iostream>
#include <stack>

using namespace std;

stack<int>* sortStack(stack<int>* s1)
{
    stack<int>* s2 = new stack<int>;
    while(!s1->empty())
    {
        int tmp = s1->top();
        s1->pop();
        while(!s2->empty() && tmp < s2->top())
        {
            s1->push(s2->top());
            s2->pop();
        }
        s2->push(tmp);
    }
    while(!s2->empty())
    {
        s1->push(s2->top());
        s2->pop();
    }
    delete s2;
    return s1;
}

int main()
{
    stack<int>* s = new stack<int>;
    s->push(10);
    s->push(1);
    s->push(34);
    s->push(345);
    s->push(22);
    s->push(3);
    s = sortStack(s);
    while(!s->empty())
    {
        cout << s->top() << endl;
        s->pop();
    }
    return 0;
}