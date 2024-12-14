#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class MinStack
{
private:
public:
    MinStack() {}

    std::stack<int> stack;
    std::stack<int> minStack;

    void push(int val)
    {
        stack.push(val);
        val = min(val, minStack.empty() ? val : getMin());
        minStack.push(val);
    }

    void pop()
    {
        stack.pop();
        minStack.pop();
    }

    int top()
    {
        int result = 0;
        if (stack.empty() == true)
        {
            cout << "Unable to see the top of the stack as it is currently empty" << endl;
        }
        else
        {
            result = stack.top();
        }
        return result;
    }

    int getMin()
    {
        int result = 0;
        if (minStack.empty() == true)
        {
            cout << "Unable to see the top of the stack as it is currently empty" << endl;
        }
        else
        {
            result = minStack.top();
        }
        return result;
    }
};

int main()
{

    MinStack test;
    test.push(-1);
    test.push(1);
    test.push(0);
    test.pop();
    int top_result = test.top();
    cout << "Top result is " << top_result << endl;
    int min_result = test.getMin();
    cout << "Min result is " << min_result << endl;

    return 0;
}