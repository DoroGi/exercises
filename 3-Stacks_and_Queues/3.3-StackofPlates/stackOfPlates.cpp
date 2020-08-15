#include <vector>
#include <iostream>

using namespace std;

class Node
{
public:
    Node* above;
    Node* below;
    int value;
    Node(int v)
    {
        above = nullptr;
        value = v;
        below = nullptr;
    };
};

class Stack
{
private:
    int capacity;
public:
    Node* top;
    Node* bottom;
    int size;
    Stack(int c)
    {
        capacity = c;
        size=0;
    }

    ~Stack()
    {
        while(!isEmpty()) pop();
    }

    bool isFull()
    {
        return capacity == size;
    }

    bool isEmpty()
    {
        return size==0;
    }

    void join(Node* above, Node* below) {
        if (below != nullptr) below->above = above;
        if (above != nullptr) above->below = below;
    }

    bool push(int v)
    {
        if(size>=capacity) return false;
        size++;
        Node* n = new Node(v);
        if (size == 1) bottom = n;
        join(n,top);
        top = n;
        return true;
    }

    int pop()
    {
        Node* t = top;
        top = top->below;
        size--;
        int deletedValue = t->value;
        delete t;
        return deletedValue;
    }

    int removeBottom()
    {
        Node* b = bottom;
        bottom = bottom->above;
        if (bottom != nullptr) bottom->below = nullptr;
        size--;
        int deletedValue = b->value;
        delete b;
        return deletedValue;
    }
};

class SetOfStacks
{
public:
    vector<Stack*>* stacks = new vector<Stack*>;
    int capacity;
    SetOfStacks(int c)
    {
        capacity = c;
    }

    ~SetOfStacks()
    {
        for(int i=0; i<stacks->size(); i++) delete stacks->at(i);
    }

    Stack* getLastStack()
    {
        if (stacks->size() == 0) return nullptr;
        return stacks->at(stacks->size()-1);
    }

    void push(int v)
    {
        Stack* last = getLastStack();
        if(last != nullptr && !last->isFull())
        {
            last->push(v);
        }
        else {
            Stack* stack = new Stack(capacity);
            stack->push(v);
            stacks->push_back(stack);
        }
    }

    int pop()
    {
        Stack* last = getLastStack();
        if (last == nullptr) throw "Stack are empty!";
        int v = last->pop();
        if (last->size==0) stacks->pop_back();
        return v;
    }

    bool isEmpty()
    {
        Stack* last = getLastStack();
        return last == nullptr || last->isEmpty();
    }

    int popAt(int index)
    {
        return leftShift(index, true);
    }

    int leftShift(int index, bool removeTop)
    {
        Stack* stack = stacks->at(index);
        int removed;
        removed = removeTop ? stack->pop() : stack->removeBottom();
        if (stack->isEmpty())
        {
            stacks->erase(stacks->begin() + index);
        }
        else if (stacks->size() > index+1)
        {
            int v = leftShift(index+1, false);
            stack->push(v);
        }
        return removed;
    }
};

int main()
{
    SetOfStacks* ss = new SetOfStacks(3);
    ss->push(1);
    ss->push(2);
    ss->push(3);
    ss->push(4);
    ss->push(4);
    ss->push(5);
    ss->push(6);
    ss->push(7);
    cout << ss->pop() << endl;
    cout << ss->popAt(0) << endl;
    cout << ss->pop() << endl;
    return 0;
}