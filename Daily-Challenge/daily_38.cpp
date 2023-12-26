/* Daily Question: 1155. Number of Dice Rolls With Target Sum
 * by Tyler Edwards | December 25th, 2023 (Merry Christmas!)
 * Code Credit: votrubac
 * You have n dice, and each die has k faces numbered from 1 to k.
 * Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. 
 * Since the answer may be too large, return it modulo 109 + 7. */

class Solution {
public:
    int numRollsToTarget(int n, int o, int target) 
    {
        vector<int> dp(target + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            vector<int> dp1(target + 1);

            for (int j = 1; j <= o; j++)
            {
                for (auto k = j; k <= target; k++)
                {
                    dp1[k] = (dp1[k] + dp[k - j]) % 1000000007;
                }
            }

            swap(dp, dp1);
        }

        return dp[target];
    }
};