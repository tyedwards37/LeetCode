/* Daily Question: 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 * by Tyler Edwards | June 22nd, 2024
 * Code Credit: lee215
 * Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit. */

class Solution {
public:
        int longestSubarray(vector<int>& A, int limit) {
            int i = 0, j; // intialize two integers i and j
            multiset<int> m; // intialize a multiset m 
            for (j = 0; j < A.size(); ++j) { // loop for the values in the given array
                m.insert(A[j]); // insert the value at the current index j to the multiset
                if (*m.rbegin() - *m.begin() > limit) // check for the condition .rbegin() - .begin() is greater than the given limit
                    m.erase(m.find(A[i++])); // erase the index i value from the multilist
            }
            return j - i; // return the final value of j - i
    }
};