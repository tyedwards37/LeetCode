/* LeetCode Day 7: Maximum Avergae Subarray I (Easy) 8/75 
 * by Tyler Edwards | October 30th, 2023
 * Desc: You are given an integer array nums consisting of n elements, and an integer k. Find a contiguous subarray whose length 
 * is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted. */

class Solution {
public:
    #include <vector>

    double findMaxAverage(vector<int>& nums, int k) 
    {
        double maxAvg = 0.0;
        double currentAvg = 0.0;

        for (int i = 0; i < k; i++)
        {
            int add = nums[i];
            currentAvg += add;
        }

        maxAvg = currentAvg / k;

        for (int j = k; j < nums.size(); j++)
        {
            currentAvg = currentAvg - nums[j - k] + nums[j];
            maxAvg = std::max(maxAvg, currentAvg / k);
        }

        return maxAvg;
    }
};
