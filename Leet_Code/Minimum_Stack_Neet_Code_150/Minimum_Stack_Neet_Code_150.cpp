#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class MinStack {
public:

    vector<int> stack;

    // MinStack constructor that initializes an object
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
    }
    
    void pop() {
        if (stack.empty() == true) {
            cout<<"Unable to pop stack as it is currently empty"<<endl;
        } else { 
            stack.pop_back();
        };
    }
    
    int top() {
        int result = 0;
        if (stack.empty() == true){
            cout<<"Unable to see the top of the stack as it is currently empty"<<endl;
        } else {
            result = stack[stack.size()-1];
        }
        return result;
    }
    
    int getMin() {

        int min;
        if (stack.size() > 0){
            min = *min_element(stack.begin(), stack.end());
            return min;
        } else {
            cout<<"Unable to find the bottom element of the stack as the stack is currently empty"<<endl;
            return 0;
        }
    }
};


int main () {
    
    MinStack test;
    test.push(2);
    test.push(1);
    test.push(0);
    int stack_element;
    for (int i = 0; i < test.stack.size(); i++){
        stack_element = test.stack[i];
        cout<<"Stack Element "<< i << " is "<< stack_element << endl;
    }

    test.pop();
    int top_result = test.top();
    cout<<" Top result is " << top_result << endl;

    int min_result = test.getMin();
    cout<<" Min result is " << min_result << endl; 

    return 0;
}