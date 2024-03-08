/* Daily Question: 3005. Count Elements With Maximum Frequency
 * by Tyler Edwards | March 7th, 2024 
 * You are given an array nums consisting of positive integers.
 * Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
 * The frequency of an element is the number of occurrences of that element in the array. */

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int maxFreq = 0;
        for (auto& check: freq) {
            maxFreq = max(maxFreq, check.second);
        }

        int numOfMaxFreq = 0;
        for (auto& check: freq) {
            if (check.second == maxFreq) {
                numOfMaxFreq++;
            }
        }

        return maxFreq * numOfMaxFreq;
    }
};