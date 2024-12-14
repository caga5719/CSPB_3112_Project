#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //set our left and right bounds to the range of the vector
        int l = 0;
        int r = nums.size()-1;

        //iterate through the vector by spliting from the midpoint of it in each iteration.
        //return -1 if no value is found, if a value is found return the index.

        while(l<=r){
            int mid = std::floor((l+r)/2);

            //check if targe is less than value at mid (midpoint)

            if (target < nums[mid]){
                r = mid - 1;
            } else if (target > nums[mid]){
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
