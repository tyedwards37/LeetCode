/* Daily Question: 2044. Count Number of Maximum Bitwise-OR Subsets
 * by Tyler Edwards | October 17th, 2024 
 * Code Credit: lee215
 * Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.
 * An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. 
 * Two subsets are considered different if the indices of the elements chosen are different. 
 * The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed). */

class Solution {
public:
    int countMaxOrSubsets(vector<int>& A) {
        int max = 0, dp[1 << 17] = {1};
        for (int a: A) {
            for (int i = max; i >= 0; --i)
                dp[i | a] += dp[i];
            max |= a;
        }
        return dp[max];
    }
};