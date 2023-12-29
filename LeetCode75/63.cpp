/* LeetCode Day 57: 198. House Robber (Medium) 63/75 
 * Tyler Edwards | December 28th, 2023 
 * Code Credit: heroes3001
 * You are a professional robber planning to rob houses along a street. 
 * Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police. */

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if (nums.size() == 0) return 0;

        int prev1 = 0;
        int prev2 = 0;

        for (int num : nums) 
        {
            int tmp = prev1;
            prev1 = max(prev2 + num, prev1);
            prev2 = tmp;
        }

        return prev1;    
    }
};
