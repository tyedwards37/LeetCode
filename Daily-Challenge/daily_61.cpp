/* Daily Question: 198. House Robber
 * by Tyler Edwards | January 20th, 2024 
 * Code Credit: archit91
 * You are a professional robber planning to rob houses along a street. 
 * Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police. */

class Solution {
public:
    int rob(vector<int>& A) {
        vector<int> dp(size(A),-1);
        return rob(A, dp, 0);
    }
    int rob(vector<int>& A, vector<int>& dp, int i) {
        if(i >= size(A)) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(rob(A, dp, i+1), A[i] + rob(A, dp, i+2));
    }
};