/* LeetCode Day 22: Product of Array Except Self (238) (Medium) 24/75 
 * by Tyler Edwards | November 15th, 2023 
 * Desc: Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int len = nums.size();
        vector<int> answer(len);
        vector<int> right(len);
        vector<int> left(len);

        left[0] = 1;

        for (int i = 1; i < len; i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }

        right[len - 1] = 1;
        for (int i = len - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < len; i++)
        {
            answer[i] = left[i] * right[i];
        }
            
        return answer;
    }
};