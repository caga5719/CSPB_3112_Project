#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        int org_last_idx = 0;
        for (int i = 1; i < nums.size(); i++){
            if(nums[org_last_idx] != nums[i]){
                swap(nums[++org_last_idx], nums[i]);
            }
        }
        return org_last_idx + 1;
    }
};


int main(){

    Solution test;
    
    vector<int> test_vec = {0,0,1,1,1,2,2,3,3,4};

    int result = test.removeDuplicates(test_vec);

    cout<< "The number of originals is  = " << result << endl;

    for (int num: test_vec){
        cout<<num<<" ";
    }

    return 0;

}