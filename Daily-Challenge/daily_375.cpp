/* Daily Question: 2825. Make String a Subsequence Using Cyclic Increments
 * by Tyler Edwards | December 3rd, 2024  
 * Code Credit: lee
 * You are given two 0-indexed strings str1 and str2.
 * In an operation, you select a set of indices in str1, and for each index i in the set, increment str1[i] to the next character cyclically. 
 * That is 'a' becomes 'b', 'b' becomes 'c', and so on, and 'z' becomes 'a'.
 * Return true if it is possible to make str2 a subsequence of str1 by performing the operation at most once, and false otherwise. */

class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int j = 0, n = s1.size(), m = s2.size();
        for (int i = 0; i < n && j < m; ++i)
            if (s1[i] == s2[j] || s1[i] + 1 == s2[j] || s1[i] - 25 == s2[j])
                ++j;
        return j == m;
    }
};