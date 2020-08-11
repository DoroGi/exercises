# Singly Linked List
A linked list is a collection of nodes that collectively form a linear sequence.
In a singly linked list, **each node stores** a reference to an object that is an **element** of the sequence, as well as a reference to the **next** node of the list.  
The **head** node is the starting node of the list.  
We also store a reference to the **Tail** and size, as they allow for improved runtime complexity for some methods.  
Note that everything is O(1) but removeLast, which is O(n).
If you frequently need to removeLast, this is probably not the correct Data Structure.