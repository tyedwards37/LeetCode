/* Daily Question: 977. Squares of a Sorted Array
 * by Tyler Edwards | March 1st, 2024 (Day 100!)
 * Code Credit: andnik
 * Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order. */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int l = 0, r = A.size() - 1;
        for (int k = A.size() - 1; k >= 0; k--) {
            if (abs(A[r]) > abs(A[l])) res[k] = A[r] * A[r--];
            else res[k] = A[l] * A[l++];
        }
        return res;
    }
};