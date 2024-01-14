/* LeetCode Beginner's Guide: 1480. Running Sum of 1d Array (1/6)
 * by Tyler Edwards | January 14th, 2024 
 * Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
 * Return the running sum of nums. */

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }   
};