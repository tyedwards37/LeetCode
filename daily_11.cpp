/* Daily Question: 1685. Sum of Absolute Differences in a Sorted Array
 * by Tyler Edwards | November 24th, 2023 
 * You are given an integer array nums sorted in non-decreasing order.
 * Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.
 * In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed). */

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
        int size = nums.size(), left = 0, right = 0, total = 0;
        vector<int> sums(size, 0);

        for (int n : nums)
        {
            total += n;
        }

        right = total;

        for (int i = 0; i < size; i++)
        {
            int n = nums[i];
            right -= n;

            sums[i] = n * i - left + right - n * (size - i - 1);

            left += n;
        }

        return sums;
    }
};