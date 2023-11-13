/* LeetCode Day 20: Single Number (Easy) 22/75 
 * by Tyler Edwards | November 13th, 2023 
 * Desc: Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
 * You must implement a solution with a linear runtime complexity and use only constant extra space. */

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        int count = 2;
        int index = 0;
        int check = nums[index];
        while (1)
        {
            count = 2;
            check = nums[index];
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == check)
                {
                    count--;
                }
            }

            if (count == 1)
            {
                return check;
            }

            index++;
        }
    }
};