#include<iostream>

using namespace std;

struct Page_Node {
        //store url and pointer to previous and next url
        string url;
        Page_Node* next;
        Page_Node* prev;

        Page_Node(string url): url(url), prev(nullptr), next(nullptr){};  
    };
class BrowserHistory {
private:
    Page_Node* home_pg;
    Page_Node* last_dummy_pg;
    Page_Node* current_pg;
public:
    //#1

    BrowserHistory(string homepage) {
        home_pg = new Page_Node(homepage);
        current_pg = home_pg;
        last_dummy_pg = new Page_Node("N/A");

        home_pg->next = last_dummy_pg;
        last_dummy_pg->prev = home_pg;
    };
    //#4
    //acts insert a new node after the current last node
    void visit(string url) {
        Page_Node* insert = new Page_Node(url);

        //insert page before dummy end node and after current page
        insert->next = last_dummy_pg;
        insert->prev = current_pg;
        
        //point the last dummy node and the old last page to the newly inserted page
        current_pg->next = insert;
        last_dummy_pg->prev = insert;
        
        //set current_pg node to the newly inserted page
        current_pg = insert;
    };
    //#3
    string back(int steps) {
        // iterate through all pages for the steps requested
        // if steps is greater than pages remaing behind of the current page then return first url/home
        for(int i = 1; i <= steps; i++){
            if (current_pg == home_pg){
                return current_pg->url;
            }
            current_pg = current_pg->prev;
        }
        return current_pg->url;
        
    };
    
    //#2
    string forward(int steps) {
        // iterate through all pages for the steps requested
        // if steps is greater than pages remaing in front of the current page then return last url
        for(int i = 1; i <= steps; i++){
            if (current_pg->next == last_dummy_pg){
                return current_pg->url;
            }
            current_pg = current_pg->next;
        }
        return current_pg->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */