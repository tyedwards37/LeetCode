/* Daily Question: 1248. Count Number of Nice Subarrays
 * by Tyler Edwards | June 21st, 2024
 * Code Credit: 
 * Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
 * Return the number of nice sub-arrays. */

class Solution {
public:
    int numberOfSubarrays(vector<int>& A, int k) {
        return atMost(A, k) - atMost(A, k - 1); 
    }

    int atMost(vector<int>& A, int k) {
        int res = 0, i = 0, n = A.size();
        for (int j = 0; j < n; j++) {
            k -= A[j] % 2;
            while (k < 0)
                k += A[i++] % 2;
            res += j - i + 1;
        }
        return res;
    }
};