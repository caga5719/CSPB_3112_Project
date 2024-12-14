#include <stack>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
std::unordered_map<char, char> parenthesis_map {
    {')','('},
    {']','['},
    {'}','{'}
};

std::stack<char> storage_stack;

public:
    Solution(){

    };

    bool isValid(std::string s) {

        for (const auto& c : s){
            if (parenthesis_map.find(c) != parenthesis_map.end()){
                if(storage_stack.empty()){
                    return false;
                } else if (parenthesis_map[c] != storage_stack.top()){
                    return false;
                }
                    storage_stack.pop();
            } else {
                    storage_stack.push(c);
            }
        }
        return storage_stack.empty();
    }
};

int main () {

    std::string test = "()[]{}";

    Solution validate;

    std::cout<<"The result is "<< (validate.isValid(test) ? "true" : "false")<<'\n';
    
    return 0;
}
