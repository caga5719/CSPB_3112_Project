#include<vector>
#include<Pair>


using namespace std;

// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        //create a loop to iterate through each pair in 'Pairs'
        //initialize a vector to contain each state of the pairs vector after the insertion of each element
        vector<vector<Pair>> stateVector;
        for (int i = 0; i < pairs.size(); i++){
            //initialize our sorted vector pointer (j) to be one less than our un-sorted vector pointer
            int j = i - 1;
            //create inner loop to iterate through the sorted portion of the vector until the inserting element (initally i) 
            //can find its correct position
            //make sure jth index is not less than 0
            //make sure that each j+1th element that is 
            while(j >= 0 && pairs[j].key >pairs[j+1].key){
                Pair temp = pairs[j+1];
                pairs[j+1] = pairs[j];
                pairs[j] = temp;
                j--;
            }
        // insert each state of vectors in stateVector
        stateVector.push_back(pairs);
        }
        return stateVector;
    }
};
