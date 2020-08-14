#include <iostream>
#include "Stack.hpp"

using namespace std;

int main()
{
    Stack<int>* st = new Stack<int>;
    st->push(9);
    st->push(8);
    st->push(7);
    st->push(6);
    st->push(34);
    cout << st->pop() << endl;
    st->push(5);
    cout << st->peek() << endl;
    st->push(4);
    st->push(3);
    st->push(2);
    st->push(1);
    st->printContent();
    return 0;
}