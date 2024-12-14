#include "LinkedList.h"

// this is the implementation file

using namespace std;

ListNode::ListNode(int val) : val(val), next(nullptr) {}

// ListNode Constructor with 'next' pointer
ListNode::ListNode(int val, ListNode* next) : val(val), next(next) {}

// LinkedList Constructor
LinkedList::LinkedList() {
    // Initialize the list with a 'dummy' node which makes
    // removing a node from the beginning of the list easier.
    head = new ListNode(-1);
    tail = head;
}

// Implementation for Singly Linked List

int LinkedList::get(int index) const
{
    ListNode *curr = head->next;
    int i = 0;
    while (curr != nullptr)
    {
        if (i == index)
        {
            return curr->val;
        }
        i++;
        curr = curr->next;
    }
    return -1; // Index out of bounds or list is empty
}

// Method to insert at the head
void LinkedList::insertHead(int val)
{
    ListNode *newNode = new ListNode(val);
    newNode->next = head->next;
    head->next = newNode;
    if (newNode->next == nullptr)
    { // If list was empty before insertion
        tail = newNode;
    }
}

// Method to insert at the tail
void LinkedList::insertTail(int val)
{
    tail->next = new ListNode(val);
    tail = tail->next;
}

// Method to remove at given index
bool LinkedList::remove(int index)
{
    int i = 0;
    ListNode *curr = head;
    while (i < index && curr != nullptr)
    {
        i++;
        curr = curr->next;
    }

    // Remove the node ahead of curr
    if (curr != nullptr && curr->next != nullptr)
    {
        if (curr->next == tail)
        {
            tail = curr;
        }
        ListNode *toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;
        return true;
    }
    return false;
}

// Method to get values of the linked list
vector<int> LinkedList::getValues() const
{
    vector<int> res;
    ListNode *curr = head->next;
    while (curr != nullptr)
    {
        res.push_back(curr->val);
        cout<<curr->val<<'\n';
        curr = curr->next;
    }
    return res;
}