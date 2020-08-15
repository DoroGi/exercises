#include <vector>
#include <iostream>

using namespace std;

class Multistack
{
private:
    class StackInfo
    {
    public:
        int start;
        int size;
        int capacity;
        StackInfo(int s, int c)
        {
            start = s;
            size = 0;
            capacity = c;
        }

        bool isWithinStackCapacity(int valuesLength, int index)
        {
            if (index < 0 || index >= valuesLength) return false;

            int contiguousIndex = index < start ? index + valuesLength : index;
            int end = start + capacity;
            return start <= contiguousIndex && contiguousIndex < end;
        }

        int lastCapacityIndex(Multistack* ms)
        {
            return ms->adjustIndex(start + capacity - 1);
        }

        int lastElementIndex(Multistack* ms)
        {
            return ms->adjustIndex(start + size - 1);
        }

        bool isFull()
        {
            return size == capacity;
        }

        bool isEmpty()
        {
            return size == 0;
        }
    };
    vector<StackInfo*> info;
    vector<int> values;

public:
    Multistack(int numberOfStacks, int defaultSize)
    {
        for (int i=0; i < numberOfStacks; i++)
        {
            StackInfo* newStack = new StackInfo(defaultSize * i, defaultSize);
            info.push_back(newStack);
        }
        values.reserve(numberOfStacks*defaultSize);
    }

    void push(int stackNum, int value)
    {
        if (AllStacksAreFull()) throw "All stacks are full!";
        StackInfo* stack = info.at(stackNum);
        if (stack->isFull()) expand(stackNum);
        stack->size++;
        values[stack->lastElementIndex(this)] = value;
    }

    int pop(int stackNum)
    {
        StackInfo* stack = info.at(stackNum);
        if (stack->isEmpty()) throw "Stack is empty!";
        
        int value = values[stack->lastElementIndex(this)];
        values[stack->lastElementIndex(this)] = 0;
        stack->size--;
        return value;
    }

    int peek(int stackNum)
    {
        StackInfo* stack = info.at(stackNum);

        return values[stack->lastElementIndex(this)];
    }

    void shift(int stackNum)
    {
        StackInfo* stack = info.at(stackNum);
        if (stack->size >= stack->capacity)
        {
            int nextStack = (stackNum + 1) % info.size();
            shift(nextStack);
            stack->capacity++;
        }

        int index = stack->lastCapacityIndex(this);
        while (stack->isWithinStackCapacity(values.capacity(), index))
        {
            values[index] = values[previousIndex(index)];
            index = previousIndex(index);
        }

        values[stack->start] = 0;
        stack->start = nextIndex(stack->start);
        stack->capacity--;
    }

    void expand(int stackNum)
    {
        shift((stackNum + 1) % info.size());
        info.at(stackNum)->capacity++;
    }

    int numberOfElements()
    {
        int size = 0;
        for (StackInfo* sd : info) size += sd->size;
        return size;
    }

    bool AllStacksAreFull()
    {
        return numberOfElements() == values.capacity();
    }

    int adjustIndex(int index)
    {
        int max = values.capacity();
        return ((index % max) + max) % max;
    }

    int nextIndex(int index)
    {
        return adjustIndex(index+1);
    }

    int previousIndex(int index)
    {
        return adjustIndex(index-1);
    }

    void printAll()
    {
        for (int i=0; i<info.size(); i++) 
        {
            cout << peek(i) << " ";
        }
        cout << endl;
    }
};

int main()
{
    Multistack* ms = new Multistack(3, 6);
    ms->push(0, 0);
    ms->push(0, 1);
    ms->push(0, 2);
    ms->push(0, 3);
    ms->push(0, 4);
    ms->push(1, 10);
    ms->push(1, 11);
    ms->push(1, 12);
    ms->push(1, 13);
    ms->push(1, 14);
    ms->push(2, 20);
    ms->push(2, 21);
    ms->push(2, 22);
    ms->push(2, 23);
    ms->push(2, 24);
    ms->printAll();
    ms->push(0, 5);
    ms->push(0, 6);
    ms->push(0, 7);
    ms->printAll();
    ms->pop(0);
    ms->pop(1);
    ms->pop(2);
    ms->printAll();
    return 0;
}