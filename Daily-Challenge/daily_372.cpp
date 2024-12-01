/* Daily Question: 1346. Check If N and Its Double Exist
 * by Tyler Edwards | November 30th, 2024  
 * Code Credit: Ryan
 * Given an array arr of integers, check if there exist two indices i and j such that :
 * - i != j
 * - 0 <= i, j < arr.length
 * - arr[i] == 2 * arr[j] */

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> set;
        for(int i=0;i<arr.size();i++){
            if(set.count(2*arr[i])>0 || ((arr[i]%2==0) && set.count(arr[i]/2)>0))
                return true;
            set.insert(arr[i]);
        }
        return false;
    }
};