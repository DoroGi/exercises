#include <iostream>
#include "DoubleLinkedList.hpp"

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