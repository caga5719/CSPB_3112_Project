#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        bool duplicated =false;
        int n = nums.size();
        int i = 0;
        int j = 0;
        vector<int> ans(2*n);
        while (i < n || duplicated == false){
            ans[j] = nums[i];
            i++;
            j++;
            if (i == n && duplicated == false){
                duplicated = true;
                i = 0;
            }
        }
        return ans;
    }
};


int main () {

    vector<int> test = {1,2,3,4,5};

    Solution test_class;
    vector<int> result = test_class.getConcatenation(test);
    
    return 0;
}