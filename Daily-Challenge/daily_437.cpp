/* Daily Question: 1800. Maximum Ascending Subarray Sum
 * by Tyler Edwards | February 3rd, 2025 
 * Code Credit: Vlad
 * Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.
 * A subarray is defined as a contiguous sequence of numbers in an array.
 * A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending. */

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0, sum = nums[0];
        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                res = max(res, sum);
                sum = 0;
            }
            sum += nums[i];
        }
        return max(res, sum);
    }
};