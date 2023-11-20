/* LeetCode Day 26: Max Number of K-Sum Pairs (1679) (Medium) 28/75 
 * by Tyler Edwards | November 19th, 2023 
 * Desc: You are given an integer array nums and an integer k.
 * In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.
 * Return the maximum number of operations you can perform on the array. */

class Solution {
public:
    int count = 0;

    int maxOperations(vector<int>& nums, int k) 
    {
        unordered_map<int, int> map;
        int operations = 0, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (map[k - nums[i]] > 0)
            {
                operations++;
                map[k - nums[i]]--;
            }

            else map[nums[i]]++;
        }

        return operations;
    }
};