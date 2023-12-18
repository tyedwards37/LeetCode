/* Daily Question: 1913. Maximum Product Difference Between Two Pairs
 * by Tyler Edwards | December 17th, 2023 
 * Code Credit: saiteja_balla0413
 * The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).
 * - For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.
 * Given an integer array nums, choose four distinct indices w, x, y, and z such that the product difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.
 * Return the maximum such product difference. */

class Solution {
public:
    int maxProductDifference(vector<int>& nums) 
    {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max1)
            {
                max2 = max1;
                max1 = nums[i];
            }

            else if (nums[i] > max2)
            {
                max2 = nums[i];
            }

            if (nums[i] < min1)
            {
                min2 = min1;
                min1 = nums[i];
            }

            else if (nums[i] < min2)
            {
                min2 = nums[i];
            }
        }

        return (max1 * max2) - (min1 * min2);
    }
};