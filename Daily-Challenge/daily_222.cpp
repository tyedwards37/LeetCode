/* Daily Question: 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
 * by Tyler Edwards | July 2nd, 2024
 * Code Credit: a3426189
 * You are given an integer array nums. 
 * In one move, you can choose one element of nums and change it to any value. 
 * Return the minimum difference between the largest and smallest value of nums after performing at most three moves. */

class Solution {
public:
    int minDifference(vector<int>& A) {
        int n = A.size();
        if (n < 5) return 0;
        sort(A.begin(), A.end());
        return min({A[n - 1] - A[3], A[n - 2] - A[2], A[n - 3] - A[1], A[n - 4] - A[0]});
    }
};