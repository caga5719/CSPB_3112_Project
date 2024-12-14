#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Pair {
public:
     int key;
     string value;

   Pair(int key, string value) : key(key), value(value) {}
};
class Solution {
public:
    vector<Pair> merge(vector<Pair>& pairs, int s, int m, int e) {
        vector<Pair> leftV= {pairs.begin() + s, pairs.begin() + m};
        vector<Pair> rightV = {pairs.begin() + m+1, pairs.begin() + e};

        //initialize iterators for both vectors
        int i = 0;
        int j = 0;

        //loop through and compare each subvector until the end of a subvector has been reached
        while(i < leftV.size() && j < rightV.size()){
            // compare the current key of the left vector and the current key of the right vector
            if (leftV[i].key <= rightV[j].key){
                pairs[s++] = leftV[i++];
            } else {
                pairs[s++] = rightV[j++];
            }
        }
        
        // check if there are any remaining elements in the left subarray
        while(i < leftV.size()){
            pairs[s++] = leftV[i++];
        }
        // check if there are any remaining elements in the right subarray
        while(j < rightV.size()){
            pairs[s++] = rightV[j++];
        }
        return pairs;
    }
    vector<Pair> mergeSort(vector<Pair>& pairs, int s=0, int e=0) {

        //Check if the vector is not a single "Pair"/base case
        if (pairs.size()-s == 0){
            return pairs;
        }

        // divid the vector into 2 parts
        int m = (pairs.size())/2;

        //keep splitting the vector into subproblems until the base case of 1 vector value is reached
        //in this case we're creating 2 sub vectors right and left

        //left vector
        mergeSort(pairs, s, m);
        //right vector
        mergeSort(pairs, m+1, pairs.size());

        //merge the 2 subarrays
        merge(pairs,s,m,pairs.size());

        return pairs;
    }
};


int main() {



    return 0;
}