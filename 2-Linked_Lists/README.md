# How to run
These exercises require the use of a LinkedList, so i copied my implementation here.  

I encoutered some problems trying to run both the files together, as the LinkedList is a template.
To solve that I had to instantiate the template with each type I am going to use.

The lines at the end DoubleLinkedList.cpp are doing exactly that:

    template class DoubleLinkedList<int>;
    template class DoubleLinkedList<string>;

More on that: https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl  

To run the exercises, you can just use

    g++ -std=c++2a DoubleLinkedList.cpp 2.1-RemoveDups\removeDups.cpp

