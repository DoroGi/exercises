#include <iostream>
#include "../../data_structures/1-LinkedList/SingleLinkedList/SingleLinkedList.hpp"

using namespace std;

template <typename T>
node<T>* loopDetection(SingleLinkedList<T>* list)
{
    node<T>* fastRunner = list->first();
    node<T>* slowRunner = list->first();

    //I go over the list. If the runners meets again there is a loop
    while(fastRunner != nullptr && fastRunner->next != nullptr)
    {
        slowRunner = slowRunner->next;
        fastRunner = fastRunner->next->next;
        if (slowRunner == fastRunner) break;
    }

    if (fastRunner == nullptr || fastRunner->next == nullptr) return nullptr;

    //K is the length of the non looping part.
    //When slowRunner reaches start of loop, fastRunner is k node into the loop.
    //Now fastRunner will catch up to slowRunner getting a node closer every loop.
    //When they meet they are at loopLength - k from the start of the loop, so...
    slowRunner = list->first();
    
    //Non looping part is long k.
    //fastRunner is k node away from loop start.
    //If now they go at the same speed they will meet at loopStart.
    while(slowRunner != fastRunner)
    {
        slowRunner = slowRunner -> next;
        fastRunner = fastRunner -> next;
    }
    return slowRunner;
}

int main()
{
    SingleLinkedList<int>* listWithCycle = new SingleLinkedList<int>;
    listWithCycle->addFirst(1);
    listWithCycle->addFirst(2);
    listWithCycle->addFirst(3);
    listWithCycle->addFirst(4);
    listWithCycle->addFirst(5);
    listWithCycle->addFirst(6);
    listWithCycle->addFirst(7);
    listWithCycle->addFirst(8);
    listWithCycle->addFirst(9);
    listWithCycle->last()->next = listWithCycle->first()->next;
    node<int>* loopStart = loopDetection(listWithCycle);
    string res = loopStart != nullptr ? "yes" : "no";
    cout << res << endl;
    delete listWithCycle;
    return 0;
}