#include "LinkedList.h"
#include <iostream>
/*struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };*/
 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *prev = NULL;
        ListNode *curr = head->next;

        while (curr != NULL) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};


int main() {
    LinkedList test;

    test.insertHead(5);
    test.insertHead(4);
    test.insertHead(3);


    //test.getValues();

    Solution test_reverse;

    ListNode* test_rev = test_reverse.reverseList(test.head);

    std::cout<<"Here is the reveresed list "<<'\n';
    while (test_rev != nullptr){
        std::cout<< test_rev->val<<std::endl;
        test_rev = test_rev->next;
    }




    return 0;
}