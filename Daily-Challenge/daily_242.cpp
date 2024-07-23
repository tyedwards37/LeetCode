/* Daily Question: 1636. Sort Array by Increasing Frequency
 * by Tyler Edwards | July 22nd, 2024 
 * Code Credit: kiranpalsingh1806
 * Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
 * Return the sorted array. */
 
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> count;

        for(auto n : nums) count[n]++;

        sort(begin(nums), end(nums), [&](int a, int b) {
            return count[a] == count[b] ? a > b : count[a] < count[b];
        });
        return nums;
    }
};