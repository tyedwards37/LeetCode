/* Daily Question: 1574. Shortest Subarray to be Removed to Make Array Sorted
 * by Tyler Edwards | November 13th, 2024  
 * Code Credit: Vlad
 * Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
 * Return the length of the shortest subarray to remove.
 * A subarray is a contiguous subsequence of the array. */

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& n) 
    {
        int sz = n.size(), r = sz - 1;
        for (; r > 0 && n[r - 1] <= n[r]; --r) ;
        auto res = r;
        for (int l = 0; l < r && (l == 0 || n[l - 1] <= n[l]); ++l) {
            while (r < sz && n[r] < n[l])
                ++r;
            res = min(res, r - l - 1);
        }
        return res;
    }  
};