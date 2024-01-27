/* Daily Question: 629. K Inverse Pairs Array
 * by Tyler Edwards | January 26th, 2024 
 * Code Credit: votrubac
 * For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].
 * Given two integers n and k, return the number of different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs. 
 * Since the answer can be huge, return it modulo 109 + 7. */

class Solution {
public:
    int MOD = 1000000007;

    int kInversePairs(int n, int k) {
    int dp[2][1001] = { 1 };
    for (int N = 1; N <= n; ++N)
        for (int K = 0; K <= k; ++K) {
            dp[N % 2][K] = (dp[(N - 1) % 2][K] + (K > 0 ? dp[N % 2][K - 1] : 0)) % MOD;
            if (K >= N)
                dp[N % 2][K] = (MOD + dp[N % 2][K] - dp[(N - 1) % 2][K - N]) % MOD;
        }
    return dp[n % 2][k];
}
};