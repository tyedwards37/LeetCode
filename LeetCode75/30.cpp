/* LeetCode Day 28: Max Consecutive Ones III (1004) (Medium) 30/75 
 * by Tyler Edwards | November 21st, 2023 
 * Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's. */

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int longest = 0, left = 0, right = 0;
        int n = nums.size();

        
        for (right = 0; right < n; right++)
        {
            if (nums[right] == 0) k--;
            
            if (k < 0 && nums[left++] == 0) k++;

            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};
