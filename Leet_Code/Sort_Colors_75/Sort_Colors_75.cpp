#include<iostream>
#include<vector>

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //create our bucket list to store color counts
        vector<int> count (3);

        //count the occurances of red, white, blue in the nums array

        for (int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }

        //take the counts recorded in our count array and overwrite the values in our
        //actual vector

        int k = 0;

        for(int i = 0; i < count.size(); i++){
            for(int j = 0; j < count[i]; j++){
                nums[k] = i;
                k++;
            }
        }

    }
};