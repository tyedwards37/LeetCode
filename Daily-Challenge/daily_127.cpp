* Daily Question: 2962. Count Subarrays Where Max Element Appears at Least K Times
 * by Tyler Edwards | March 28th, 2024 
 * Code Credit: lee215
 * You are given an integer array nums and a positive integer k.
 * Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
 * A subarray is a contiguous sequence of elements within an array. */

 class Solution {
public:
        long long countSubarrays(vector<int>& A, int k) {
        int a = *max_element(A.begin(), A.end()); // max between the start and end value of the array
        int n = A.size(), cur = 0, i = 0; // intialize variable for the size, the left of the window, and the current value
        long long res = 0; // intialize a long long for the answer
        for (int j = 0; j < n; ++j) { // loop for the size of the array
            cur += A[j] == a; // add to the current value the value at j if it is equal to the variable a
            while (cur >= k) // if the current value is greater than the given max value loop
                cur -= A[i++] == a; // subtract from the current if the value is equal to a and increment it by one
            res += i; // increase the result by whatever the value of i is (left side of window)
        }
        return res; // return the final value 
    }
};