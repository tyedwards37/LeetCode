/* LeetCode Day 56: 162. Find Peak Element(Medium) 60/75 
 * Tyler Edwards | December 25th, 2023 (Merry Christmas!)
 * Code Credit: lee215
 * A peak element is an element that is strictly greater than its neighbors.
 * Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
 * You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
 * You must write an algorithm that runs in O(log n) time.index. */

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) 
    {
        int l = 1, r = 1000000000;
        while (l < r) 
        {
            int m = (l + r) / 2, total = 0;

            for (int p : piles)
            {
                total += (p + m - 1) / m;
            }

            if (total > H)
            {
                l = m + 1;
            }

            else
            {
                r = m;
            }
        }

        return l;
    }
};