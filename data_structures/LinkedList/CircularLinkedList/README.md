# Circular Linked List
Same as the Singly Linked List, but now the tail node always points to the head node.  
This means that spare some space having an implicit head, which we can get with tail->next.  
Note that this has an additional method "rotate".