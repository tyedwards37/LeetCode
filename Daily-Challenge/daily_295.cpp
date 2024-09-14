/* Daily Question: 2419. Longest Subarray With Maximum Bitwise AND
 * by Tyler Edwards | September 13th, 2024 
 * Code Credit: HarshitMaurya
 * You are given an integer array nums of size n.
 * Consider a non-empty subarray from nums that has the maximum possible bitwise AND.
 * - In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered. 
 * Return the length of the longest such subarray.
 * The bitwise AND of an array is the bitwise AND of all the numbers in it. 
 * A subarray is a contiguous sequence of elements within an array. */

class Solution {
public:
    int longestSubarray(vector<int> &nums)
        {
            int x = *max_element(nums.begin(), nums.end());
            int ans = 0, len = 0;
            for (int ele: nums)
            {
                if (ele == x) ans = max(ans, ++len);
                else len = 0;
            }
            return ans;
        }
};