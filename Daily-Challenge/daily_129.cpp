/* Daily Question: 2444. Count Subarrays With Fixed Bounds
 * by Tyler Edwards | March 30th, 2024 
 * Code Credit: lee215
 * You are given an integer array nums and two integers minK and maxK.
 * A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
 * - The minimum value in the subarray is equal to minK.
 * - The maximum value in the subarray is equal to maxK.
 * Return the number of fixed-bound subarrays.
 * A subarray is a contiguous part of an array. */

class Solution {
public:
        long long countSubarrays(vector<int>& A, int minK, int maxK) {
        long res = 0; // intialize variable for final answer
        long jbad = -1; // index of the last value where the array was less than minK or greater than maxK
        long jmin = -1;  // index of the last value where the value was equal to minK
        long jmax = -1; // index of the last value where the value was equal to maxK
        long n = A.size(); // intialize variable for the size of the array
        for (int i = 0; i < n; ++i) { // loop for the length of the array 
            if (A[i] < minK || A[i] > maxK) jbad = i; // if the conditions specified are met, change jbad to the current loop value
            if (A[i] == minK) jmin = i; // if the value at index i is equal to the min value change jmin
            if (A[i] == maxK) jmax = i; // if the value at index i is equal to the max value change jmax
            res += max(0L, min(jmin, jmax) - jbad); // increment the final result by the max between 0L and the min between jmin and jmax subtracted by the jbad value
        }
        return res; // return the fianl value
    }
};