#include <vector>
#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node() : val(0), next(nullptr) {}; 
    Node(int val) : val(val), next(nullptr) {}; 
    Node(int val, Node* node_ptr) : val(val), next(node_ptr) {}; 
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = new Node(-1);
        tail = head;
    }

    int get(int index) {
        Node* curr = head;
        int size = -1;
        while(curr->next != nullptr){
            curr = curr->next;
            size++;
            if (size == index){
                return curr->val;
            };
        };
        return -1;
    }

    void insertHead(int val) {
        Node* new_head = new Node(val);
        new_head->next = head->next;
        head->next = new_head;
        if (tail == head){
            tail = new_head;
        }
    }
    
    void insertTail(int val) {
        Node* new_tail = new Node(val);
        tail->next = new_tail;
        tail = new_tail;
    }

    bool remove(int index) {
        if (head->next == nullptr){
            //list is empty
            return false;
        }
        Node* prev_node = head;
        int i = -1;
        while(prev_node->next != nullptr){
            if (i == index - 1){
                if(tail == prev_node->next){
                    Node* to_del = tail;
                    tail = prev_node;
                    prev_node->next = nullptr;
                    delete to_del;
                    return true;
                }
                Node* to_del = prev_node->next;
                prev_node->next = prev_node->next->next;
                delete to_del;
                return true;
            }
            prev_node = prev_node->next;
            i++;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* curr = head->next;
        while (curr != nullptr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
        
    }
};


int main() {
    LinkedList test;

    test.insertHead(1);
    test.insertHead(2);
    test.remove(0);
    test.remove(0);
    test.getValues();

    
    return 0;
}