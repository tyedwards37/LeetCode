/* Daily Question: 2441. Largest Positive Integer That Exists With Its Negative
 * by Tyler Edwards | April 30th, 2024  
 * Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.
 * Return the positive integer k. If there is no such integer, return -1. */

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> check(nums.begin(), nums.end()); // intialize unordered set of ints with tehe values from nums
        int maxK = -1; // set a defaul value of -1 as the max value, since that is the value if no value is found

        for(int n : nums) { // loop for all teh values in nums
            if (n > 0 && check.count(-n)) { // check if the value is positive and its negative countepart can be found in the check set
                maxK = max(maxK, n);  // sets the max value between the stored max and the value being currently evaluated 
            }
        }

        return maxK; // return the max value
    }
};