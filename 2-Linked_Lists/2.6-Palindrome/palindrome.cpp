#include <iostream>
#include <string>
#include "../../data_structures/1-LinkedList/SingleLinkedList/SingleLinkedList.hpp"

using namespace std;

template <typename T>
struct Result
{
    node<T>* head;
    bool result;
    Result(node<T>* h, bool r)
    {
        head = h;
        result = r;
    }
};

template <typename T>
Result<T>* recursivePalindrome(node<T>* head, size_t length)
{
    //Base case
    if (length==0) return new Result<T>(head, true);
    if (length==1) return new Result<T>(head->next, true);

    //"go down" the first half of the list
    Result<T>* res = recursivePalindrome(head->next, length-2);

    //"coming back" on the second half of the list, to finally make the comparisons
    if (res->result == false) return res;

    res->result = res->head->data == head->data;
    res->head = res->head->next;
    return res;    
}

template <typename T>
bool palindrome(SingleLinkedList<T>* list)
{
    size_t length = list->getSize();
    Result<T>* res = recursivePalindrome(list->first(), length);
    return res->result;
}

int main()
{
    SingleLinkedList<int>* list = new SingleLinkedList<int>;
    list->addFirst(9);
    list->addFirst(1);
    list->addFirst(3);
    list->addFirst(4);
    list->addFirst(3);
    list->addFirst(1);
    list->addFirst(9);
    list->printContent();
    string result = palindrome(list) ? "It's a palindrome!" : "Not a palindrome";
    cout << result << endl;
 
    SingleLinkedList<int>* list2 = new SingleLinkedList<int>;
    list2->addFirst(5);
    list2->addFirst(5);
    list2->addFirst(5);
    list2->addFirst(5);
    list2->addFirst(5);
    list2->addFirst(4);
    list2->printContent();
    string result2 = palindrome(list2) ? "It's a palindrome!" : "Not a palindrome";
    cout << result2 << endl;
    delete list;
    delete list2;
    return 0;
}