#include <iostream>
#include "Queue.hpp"

using namespace std;

int main()
{
    Queue<int>* q = new Queue<int>;
    q->add(34);
    q->add(9);
    q->add(8);
    q->add(7);
    q->add(6);
    cout << q->remove() << endl;
    q->add(5);
    cout << q->peek() << endl;
    q->add(4);
    q->add(3);
    q->add(2);
    q->add(1);
    q->printContent();
    return 0;
}