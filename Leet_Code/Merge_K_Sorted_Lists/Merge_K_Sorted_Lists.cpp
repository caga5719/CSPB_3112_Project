
#include<iostream>
#include<vector>


using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void printLL(ListNode *head)
    {
        int i = 1;
        while (head->next != nullptr)
        {
            cout << "The ith value is i= " << i << "and the value is " << head->val << endl;
            i++;
            head = head->next;
        }
    }
    ListNode *merge(ListNode *lists1, ListNode *lists2)
    {

        // define a new head of the new list to be created after combining the 2 lists
        ListNode *newHead;
        ListNode *temp;
        bool headFound = false;

        if (lists1 == nullptr)
        {
            return lists2;
        }
        else if (lists2 == nullptr)
        {
            return lists1;
        }

        while (lists1 != nullptr && lists2 != nullptr)
        {
            if (lists1->val <= lists2->val)
            {
                if (headFound == false)
                {
                    newHead = lists1;
                    temp = newHead;
                    headFound = true;
                }
                else
                {
                    temp->next = lists1;
                    temp = temp->next;
                }
                lists1 = lists1->next;
            }
            else
            {
                if (headFound == false)
                {
                    newHead = lists2;
                    temp = newHead;
                    headFound = true;
                }
                else
                {
                    temp->next = lists2;
                    temp = temp->next;
                }
                lists2 = lists2->next;
            }
        }
        if (lists1 != nullptr)
        {
            temp->next = lists1;
        }
        if (lists2 != nullptr)
        {
            temp->next = lists2;
        }

        printLL(temp);
        return newHead;
    }

    ListNode *mergeKListsHelper(vector<ListNode *> &lists, int s, int e)
    {
        // return if there is only one linked list else return a nullptr
        if (e - s + 1 < 1)
        {
            return nullptr;
        }
        else if (e == s)
        {
            return lists[e];
        }

        // set the split index
        int m = (e + s) / 2;

        ListNode *ll1 = mergeKListsHelper(lists, s, m);
        // cout<<"Here is the first value of ll1 "<<ll1->val<<endl;

        ListNode *ll2 = mergeKListsHelper(lists, m + 1, e);
        // cout<<"Here is the first value of ll2 "<<ll2->val<<endl;

        ListNode *mergedLL = merge(ll1, ll2);
        return mergedLL;

        // return lists[0];
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // Need to split the vector of ascending Linkedlists into subproblems/individual lists
        // so they can be eventually merged in pairs of 2 recursively afer
        // This will be handled by our mergeKList helper function

        int s = 0;

        int e = lists.size() - 1;
        // first we need to our start point and endpoint for the vector list
        return mergeKListsHelper(lists, s, e);
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
