/* Daily Question: 2501. Longest Square Streak in an Array
 * by Tyler Edwards | October 27th, 2024 
 * Code Credit: xxvvpp
 * You are given an integer array nums. A subsequence of nums is called a square streak if:
 * - The length of the subsequence is at least 2, and
 * - after sorting the subsequence, each element (except the first element) is the square of the previous number.
 * Return the length of the longest square streak in nums, or return -1 if there is no square streak.
 * A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements. */

class Solution {
public:
    int longestSquareStreak(vector<int>& A) {
        unordered_map<int, int> dp;
        int res = 0;
        sort(begin(A), end(A));
        for(auto i : A){
            int root = sqrt(i);
            if(root * root == i)
            dp[i] = 1 + dp[root];
            else 
            dp[i] = 1;
            res = max(res, dp[i]);
        }
        return res < 2 ? -1 : res;
    }
};