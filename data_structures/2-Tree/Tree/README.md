# Tree
A tree is not so different from a double linked list.  
The node has a
- parent (null for the root)
- data
- a certain number of children

## Height
There are two implementations.
Please not the using `depth()` is not the best way to find the heigth.

## Iterating over a tree
Please note that the function `positions()` return an iterable on the whole tree.
This is kinda tricky as there are various way to iterate a tree.
It is left as not implemented here, you can find different possibilies in the algorithm section.