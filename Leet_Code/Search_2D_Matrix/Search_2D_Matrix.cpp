#include<tuple>
#include<cmath>
#include<vector>

using namespace std;

class Solution {
public:

    std::tuple<bool, int> searchMatrixRowHelper(vector<int>& row, int target){
    //need to capture first index (column) and last index (column) of a specfic row
        int l = 0;
        int r = row.size()-1;

        int mid;

        while(l <= r){
            mid = std::floor((l+r)/2);

            if (target < row[mid]){
                r = mid - 1;
            } else if (target > row[mid]){
                l = mid + 1;
            } else {
                return {true, row[mid]};
            }
        }
        return {false, row[mid]};
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

    // need to split 2-d array in half based of rows
    // once in a specific row, binary search until targe is found or need to split the remaing rows below or above (based on target)
    // and repeat searching a specific row


    //need to capture 1st row and last row
    int leftRow = 0;
    int rightRow = matrix.size() - 1;

    //capture result of row binary search
    bool result = false;
    int lastVal;

    while (leftRow <= rightRow){

        int mid = std::floor((leftRow+rightRow)/2);
        
        std::tuple<bool, int> temp = searchMatrixRowHelper(matrix[mid], target);
        lastVal = get<int>(temp);
        result = get<bool>(temp);

        if (result == true){
            return result;
        }
    

        if (target < lastVal){
                rightRow = mid - 1;
            } else if (target > lastVal){
                leftRow = mid + 1;
            }
        
        }
    return result;
    }   
};
