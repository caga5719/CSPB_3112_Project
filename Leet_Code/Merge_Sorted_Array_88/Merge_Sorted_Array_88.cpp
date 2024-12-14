#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int partition(vector<int>& nums1, int low, int high){
        int i = low - 1;
        int pivot = nums1[high];
        
        for(int j = low; j<high; j++){
            if (nums1[j]<nums1[high]){
                i++;
                swap(nums1[i],nums1[j]);
            }
        }
        swap(nums1[i+1],nums1[high]);
        int partition = i+1;
        return partition;
    }

    void quick_sort(vector<int>& nums1, int low, int high){
        if(low<high){
            int p = partition(nums1, low, high);

            quick_sort(nums1, low, p-1);
            quick_sort(nums1, p+1, high);

        }
    }
    

    // Build a constructor that will combine vector1 and vector3
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int iterator = 0;
        for(int insert = m; insert < m+n; insert++){
            nums1[insert] = nums2[iterator];
            iterator++;
        };
        quick_sort(nums1, 0 , m+n-1);
        
     


    }
};