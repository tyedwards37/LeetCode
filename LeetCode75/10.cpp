/* LeetCode Day 8: Find Pivot Index (Easy) 10/75 
 * by Tyler Edwards | October 31st, 2023 (Happy Halloween)
 * Desc: Given an array of integers nums, calculate the pivot index of this array. The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
 * If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array. Return the leftmost pivot index. If no such index exists, return -1. */

class Solution {
public:
    #include <vector>
    int pivotIndex(vector<int>& nums) 
    {
        int index = 0;
        while (index < nums.size())
        {
            int left = 0;
            int right = nums.size() - 1;

            int sumLeft = 0;
            int sumRight = 0;

            while (left != index)
            {
                sumLeft += nums[left];
                left++;
            }

            while (right != index)
            {
                sumRight += nums[right];
                right--;
            }

            if (sumLeft == sumRight)
            {
                return index;
            }

            index++;
        }

        return -1;
    }
};
