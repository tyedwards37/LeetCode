/* Daily Question: 1335. Minimum Difficulty of a Job Schedule
 * by Tyler Edwards | December 28th, 2023 
 * Code Credit: lee215
 * You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).
 * You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. 
 * The difficulty of a day is the maximum difficulty of a job done on that day.
 * You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].
 * Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1. */

class Solution {
public:
        int minDifficulty(vector<int>& A, int D) 
        {
        int n = A.size(), inf = 1e9, maxd;
        if (n < D) return -1;
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;
        for (int d = 1; d <= D; ++d) 
        {
            for (int i = 0; i <= n - d; ++i) 
            {
                maxd = 0, dp[i] = inf;
                for (int j = i; j <= n - d; ++j) 
                {
                    maxd = max(maxd, A[j]);
                    dp[i] = min(dp[i], maxd + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};