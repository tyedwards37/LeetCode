/* Daily Question: 41. First Missing Positive
 * by Tyler Edwards | March 25th, 2024 
 * Code Credit: kanavk
 * Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
 * You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space. */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(); // gets the size of the array 
        for (int i = 0; i < n; i++) if (nums[i] <= 0) nums[i] = n + 1; // replaces any negative numbers with size + 1
        for (int i = 0; i < n; i++) if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1; // for every positive turn the corresponding index negative
        for (int i = 0; i < n; i++) if (nums[i] > 0) return i + 1; // check for a positive number and if that is found, that + 1is the answer
        return n + 1; // if none is found return the size + 1 
    }
};