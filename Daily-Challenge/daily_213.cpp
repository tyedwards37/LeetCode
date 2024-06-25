/* Daily Question: 995. Minimum Number of K Consecutive Bit Flips
 * by Tyler Edwards | June 23rd, 2024
 * Code Credit: lee215
 * You are given a binary array nums and an integer k.
 * A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.
 * Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.
 * A subarray is a contiguous part of an array. */

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int cur = 0, res = 0, n = A.size(); // intialize integers to track the number of flips (cur), hold the final answer value (res), and for the size of the given array (n)
        for (int i = 0; i < n; ++i) { // loop for the number of values in the given array
            if (i >= K && A[i - K] > 1) { // check if the index i is greater than or equal to K (given value) or if the value at index i minus K is greater than 1
                cur--; // decrements the number of flips
                A[i - K] -= 2; // subrtracts 2 from the value at index i miuns K (given value)
            }
            if (cur % 2 == A[i]) { // check if the number of flips even and A[i] is zero or if the number is odd and A[i] is one
                if (i + K > n) return -1; // if the value of index i plus K is greaater than the size of the array return -1 (impossible to do the flip with the given array and value)
                A[i] += 2; // add 2 to the value at index i 
                cur++; // increment the number of flips
                res++; // increment the final answer value
            }
        }
        return res; // once out oof the loop return the final answer value
    }
};