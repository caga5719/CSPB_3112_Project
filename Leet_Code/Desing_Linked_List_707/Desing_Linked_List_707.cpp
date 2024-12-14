#include<iostream>

using namespace std;

struct DoublyListNode {
    int val;
    DoublyListNode* next;
    DoublyListNode* prev;

    DoublyListNode(int val) : val(val) {

    }

    DoublyListNode(int val, DoublyListNode* nPtr, DoublyListNode* pPtr) : val(val), next(nPtr), prev(pPtr) {

    }

};

class MyLinkedList {

public:
    DoublyListNode* head;
    DoublyListNode* tail;

    MyLinkedList() {
        head = new DoublyListNode(-1);
        tail = new DoublyListNode(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        DoublyListNode* curr = head->next;
        int traveresed = 0;
        if (curr == tail || index < 0){
                return -1;
            }
        while (traveresed != index && curr != tail){
            curr = curr->next;
            traveresed++;
        }
        if (traveresed <= index && curr == tail){
            return -1;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        DoublyListNode* new_node = new DoublyListNode(val);
        new_node->next = head->next;
        head->next->prev = new_node;

        new_node->prev = head;
        head->next = new_node;
    }
    
    void addAtTail(int val) {
        DoublyListNode* new_node = new DoublyListNode(val);
        new_node->prev = tail->prev;
        tail->prev->next = new_node;

        new_node->next = tail;
        tail->prev = new_node;
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0){
            addAtHead(val);
            return;
        }
        DoublyListNode* curr = head->next;
        int curr_idx = 0;
        while(curr_idx != index && curr != tail){
            curr = curr->next;
            curr_idx++;
        }
        if (curr_idx == index && curr == tail){
            addAtTail(val);
            return;
        } else if (curr_idx == index) {
            DoublyListNode* new_node = new DoublyListNode(val);
            new_node->next = curr;
            curr->prev->next = new_node;

            new_node->prev = curr->prev;
            curr->prev = new_node;
            return;
        }
    }
    
    void deleteAtIndex(int index) {
        DoublyListNode* curr = head->next;
        int traveresed = 0;
        if (curr == tail || index < 0){
                return;
            }
        while (traveresed != index && curr != tail){
            curr = curr->next;
            traveresed++;
        }
        if (traveresed == index && curr == tail){
            return;
        } else if (traveresed == index) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */