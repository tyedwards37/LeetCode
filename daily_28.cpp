/* Daily Question: 1464. Maximum Product of Two Elements in an Array
 * by Tyler Edwards | December 11th, 2023 
 * Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1). */

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int max1 = 0, max2 = 0;

        for (int n: nums)
        {
           int tempMax = max(n, max2);

           if (tempMax > max1)
           {
               max2 = max1;
               max1 = tempMax;
           }

           else
           {
               max2 = tempMax;
           }
        }

        return (max1 - 1) * (max2 - 1);
    }
};