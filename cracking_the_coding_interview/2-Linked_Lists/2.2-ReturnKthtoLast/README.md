# How to run
These exercises require the use of a LinkedList.  

I encountered some problems trying to run both the files together, as the LinkedList is a template.
To solve that I had to instantiate the template with each type I am going to use.

The lines at the end DoubleLinkedList.cpp are doing exactly that:

    template class DoubleLinkedList<int>;
    template class DoubleLinkedList<string>;

More on that: https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl  

To try the exercises, while on "exercises" folder you can run:

    g++ -std=c++2a data_structures\1-LinkedList\DoubleLinkedList\DoubleLinkedList.cpp 2-Linked_Lists\2.1-RemoveDups\removeDups.cpp

