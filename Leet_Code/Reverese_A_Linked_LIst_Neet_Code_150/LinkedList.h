#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <vector>
#include <iostream>

// specification file

// Singly Linked List Node
class ListNode
{
public:
    int val;
    ListNode *next;

    // Constructor that sets 'next' to nullptr by default
    ListNode(int val);

    // Constructor that accepts both value and next node
    ListNode(int val, ListNode *next);
};

// Implementation for Singly Linked List
class LinkedList
{
public:
    ListNode* head;
    ListNode* tail;
    // Constructor
    LinkedList();

    int get(int index) const;

    // Method to insert at the head
    void insertHead(int val);

    // Method to insert at the tail
    void insertTail(int val);

    // Method to remove at given index
    bool remove(int index);

    // Method to get values of the linked list
    std::vector<int> getValues() const;
};

#endif 