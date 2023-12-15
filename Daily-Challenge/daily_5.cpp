/* Daily Question: 1838. Frequency of the Most Frequent Element
 * by Tyler Edwards | November 18th, 2023 
 * Desc: The frequency of an element is the number of times it occurs in an array.
 * You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.
 * Return the maximum possible frequency of an element after performing at most k operations. */

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        int maxFrequency = 0;
        long currentSum = 0;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        for (int left = 0, right = 0; right < n; ++right)
        {
            currentSum += nums[right];

            while (currentSum + k <  (long) nums[right] * (right - left + 1))
            {
                currentSum -= nums[left];
                left++;
            }

            maxFrequency = max(maxFrequency, right - left + 1);
        }

        return maxFrequency;
    }
};
