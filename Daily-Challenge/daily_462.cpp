/* Daily Question: 2965. Find Missing and Repeated Values
 * by Tyler Edwards | March 5th, 2025 
 * Code Credit: RAHUL VIJAYAN
 * You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. 
 * The task is to find the repeating and missing numbers a and b.
 * Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b. */

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int size = n * n;
        vector<int> freq(size + 1, 0);
        int repeated = -1, missing = -1;

        for (const auto& row : grid) {
            for (int num : row) {
                freq[num]++;
            }
        }

        for (int num = 1; num <= size; num++) {
            if (freq[num] == 2) repeated = num;
            if (freq[num] == 0) missing = num;
        }

        return {repeated, missing};
    }
};