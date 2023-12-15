/* LeetCode Day 23: Increasing Triplet Subsequence (334) (Medium) 25/75 
 * by Tyler Edwards | November 16th, 2023 
 * Desc: Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
 * If no such indices exists, return false. */

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        if (nums.size() < 3) return false;

        int low = INT_MAX, mid = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > mid) return true;
            else if (nums[i] < low) low = nums[i];
            else if (nums[i] > low && nums[i] < mid) mid = nums[i];
        }

        return false;
    }
};
