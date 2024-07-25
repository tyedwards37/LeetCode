/* Daily Question: 912. Sort an Array
 * by Tyler Edwards | July 24th, 2024 
 * Given an array of integers nums, sort the array in ascending order and return it.
 * You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible. */

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};