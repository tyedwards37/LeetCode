/* Daily Question: 1590. Make Sum Divisible by P
 * by Tyler Edwards | October 2nd, 2024 
 * Code Credit: lee215
 * Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. 
 * It is not allowed to remove the whole array.
 * Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
 * A subarray is defined as a contiguous block of elements in the array. */

class Solution {
public:
    int minSubarray(vector<int>& A, int p) {
        int n = A.size(), res = n, need = 0, cur = 0;
        for (auto a : A)
            need = (need + a) % p;
        unordered_map<int, int> last = {{0, -1}};
        for (int i = 0; i < n; ++i) {
            cur = (cur + A[i]) % p;
            last[cur] = i;
            int want = (cur - need + p) % p;
            if (last.count(want))
                res = min(res, i - last[want]);
        }
        return res < n ? res : -1;
    }
};