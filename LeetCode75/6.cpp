/* LeetCode Day 5: Move Zeroes (Easy) 6/75 
 * by Tyler Edwards | October 28th, 2023
 * Desc: Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * Note that you must do this in-place without making a copy of the array. */

class Solution {
public:
    #include <vector>
    
    void moveZeroes(vector<int>& nums) 
    {
        int i = 0; 
        int j = 0;

        while(i < nums.size() && j < nums.size())
        {
            if(nums[j] != 0)
            {
                swap(nums[i++], nums[j++]);
            }

            else
            {
                j++;
            }
        }
    }
};
