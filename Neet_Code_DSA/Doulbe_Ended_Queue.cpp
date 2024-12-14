struct Node {

    int val;
    Node* next;
    Node* prev;

    Node(int val): val(val), next(nullptr), prev(nullptr){};
};

class Deque {
private:
    Node* head;
    Node* tail;

public:
    Deque() {
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }

    // check if head node is the same as the tail node
    bool isEmpty() {
        if (head->next == tail){
            return true;
        }
        return false;
    }

    // create new node with value and add to the end of the queue
    void append(int value) {
        Node* app_node = new Node(value);
        //check if list is empty
        if (head->next == tail){
            head->next = app_node;
            tail->prev = app_node;

            app_node->next = tail;
            app_node->prev = head;
        //if list not empty add new node before tail (dummy) node and after current end node
        } else {
            //set old end node to be before new node
            tail->prev->next = app_node;
            //set new end node to be after old end node
            app_node->prev = tail->prev;

            //set new end node to be before tail (dummy node)
            app_node->next = tail;
            //set tail to be after new end node
            tail->prev = app_node;
        }
    }

    void appendleft(int value) {
        //check if the queue is empty and insert the node
        Node* app_node = new Node(value);
        if (head->next == tail){
            head->next = app_node;
            tail->prev = app_node;

            app_node->next = tail;
            app_node->prev = head;
        // if the queue is not empty add the node after the head and infront of the current beginning node
        } else {
            //point prev pointer of new node to head (dummy node)
            app_node->prev = head;
            //point next pointer new node to current node after head (dummy node)
            app_node->next = head->next;
            //point current beginning node to point back to new node
            head->next->prev = app_node;
            //point head to new node;
            head->next = app_node;
        }
    }

    int pop() {
        //check if queue is empty
        if(head->next == tail){
            return -1;
        }
        int result = tail->prev->val;

        Node* to_remove = tail->prev;
        //set the tail to point back to node behind current end node
        tail->prev = tail->prev->prev;
        //set current end node to point to tail (dummy node)
        tail->prev->next = tail;
        
        delete to_remove;
        return result;
    }

    int popleft() { 
         //check if queue is empty
        if(head->next == tail){
            return -1;
        }

        //capture current head value
        int result = head->next->val;
        //point head (dummy node) to node after current beginning node
        head->next = head->next->next;

        //point node after current beinning node back to head node
        head->next->prev = head;
        
        return result;
    }
};
