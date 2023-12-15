/* LeetCode Day 29: Longest Subarray of 1's After Deleting One Element (1493) (Medium) 31/75 
 * by Tyler Edwards | November 22nd, 2023 
 * Given a binary array nums, you should delete one element from it.
 * Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray. */

class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int i = 0, k = 1, j, n = nums.size();

        for (j = 0; j < n; j++)
        {
            if (nums[j] == 0) k--;
            if (k < 0 && nums[i++] == 0) k++;
        }

        return j - i - 1;
    }
};
