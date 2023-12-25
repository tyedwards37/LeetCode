/* LeetCode Day 55: 162. Find Peak Element(Medium) 59/75 
 * Tyler Edwards | December 24th, 2023 (Santa is coming!)
 * Code Credit: YehudisK
 * A peak element is an element that is strictly greater than its neighbors.
 * Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
 * You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
 * You must write an algorithm that runs in O(log n) time.index. */

class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int lo = 0, hi = nums.size() - 1, mid;
        
        while (lo < hi) 
        {
            mid = lo + (hi - lo) / 2;
            
            if (nums[mid] < nums[mid + 1]) 
                lo = mid + 1;
            else 
                hi = mid;
        }
        
        return lo;
    }
};