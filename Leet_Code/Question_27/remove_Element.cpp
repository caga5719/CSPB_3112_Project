#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val){
        int val_occr = 0;
        int last_search_index = nums.size() - 1;

        for(int i = 0; i <= last_search_index; i++){
            while (nums[i] == val && i <= last_search_index){
                val_occr++;
                last_search_index--;
                shift_left(nums, i, val);
            }
        }
        return nums.size()-val_occr;
    }

private:
    void shift_left(vector<int>& nums, int start_index, int val){
        int nums_length = nums.size();
        for(int i = start_index; i < nums_length - 1; i++){
            nums[i] = nums[i+1];
        }
        nums[nums_length-1] = val;

    }

};



int main(){ 

    Solution test;

    vector<int> test_v{0,1,2,2,3,0,4,2};

    int result = test.removeElement(test_v, 2);

    return 0;
}