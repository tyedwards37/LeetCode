/* Daily Question: 1524. Number of Sub-arrays With Odd Sum
 * by Tyler Edwards | February 24th, 2025 
 * Code Credit: Yanru Cheng
 * Given an array of integers arr, return the number of subarrays with an odd sum.
 * Since the answer can be very large, return it modulo 109 + 7. */

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int res = 0, odd = 0, even = 0;
        for (auto x: arr) {
            even += 1;
            if (x % 2)
                swap(odd, even);
            res = (res + odd) % 1000000007;
        }
        return res;
    }
};