/* Daily Question: 300. Longest Increasing Subsequence
 * by Tyler Edwards | January 4th, 2024 
 * Code Credit: hiepit
 * Given an integer array nums, return the length of the longest strictly increasing subsequence. */

class Solution { 
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
        return *max_element(dp.begin(), dp.end());
    }
};