/* Daily Question: 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
 * by Tyler Edwards | February 2nd, 2025 (Happy Birthday Emily)
 * Code Credit: Hannes Eder
 * You are given an array of integers nums. Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing. */

class Solution {
public:
    int longestMonotonicSubarray(const vector<int>& nums) {
        int ans = 1;
        for (int inc = 1, dec = 1, i = 1; i < ssize(nums); ++i) {
            inc = nums[i - 1] < nums[i] ? inc + 1 : 1;
            dec = nums[i - 1] > nums[i] ? dec + 1 : 1;
            ans = max({ans, inc, dec});
        }
        return ans;
    }
};