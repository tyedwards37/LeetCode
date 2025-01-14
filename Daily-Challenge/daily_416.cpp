/* Daily Question: 2657. Find the Prefix Common Array of Two Arrays
 * by Tyler Edwards | Janaury 12th, 2025 
 * Code Credit: Amritesh Chandra
 * You are given two 0-indexed integer permutations A and B of length n.
 * A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.
 * Return the prefix common array of A and B.
 * A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once. */

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0);
        vector<int> ans;
        int common = 0;
        
        for (int i = 0; i < n; i++) {
            if (++freq[A[i]] == 2) common++;
            if (++freq[B[i]] == 2) common++;
            ans.push_back(common);
        }
        return ans;
    }
};