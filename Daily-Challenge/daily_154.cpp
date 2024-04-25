/* Daily Question: 2370. Longest Ideal Subsequence
 * by Tyler Edwards | April 24th, 2024  
 * Code Credit: lee215
 * You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:
 * - t is a subsequence of the string s.
 * - The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
 * Return the length of the longest ideal string.
 * A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
 * Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1. */

class Solution {
public:
        int longestIdealString(string s, int k) {
        int dp[150] = {}, res = 0; // intializes an empty array of ints with size 150 and a variable to return as the anaswer
        for (auto& i : s) { // loop through the string for each character
            for (int j = i - k; j <= i + k; ++j) // loop for the size of k * 2, starting from the index of char i minus the given k
                dp[i] = max(dp[i], dp[j]); // set the value of the array at the index of the character i to the max between the value at index i and j
            res = max(res, ++dp[i]); // set the answer to the max between its current value and the value at index i of the array + 1
        }
        return res; // return the answer variable
    }
};