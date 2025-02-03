/* Daily Question: 1752. Check if Array Is Sorted and Rotated
 * by Tyler Edwards | February 1st, 2025 (Happy Birthday Emily)
 * Code Credit: False Genius
 * Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
 * There may be duplicates in the original array. */

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 1; i < n; i++)
            if (nums[i - 1] > nums[i])
                count++;
        
        if (nums[n - 1] > nums[0])
            count++;
        
        return count <= 1;
    }
};