/* LeetCode Day 60: 1143. Longest Common Subsequence (Medium) 66/75 
 * Tyler Edwards | January 2nd, 2024 
 * Code Credit: turbotorquetiger
 * There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
 * The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
 * Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner. */

class Solution {
public:    
    int dp[1000 + 1][1000 + 1];
    
    int maxLen(string& s1, string& s2, int n, int m)
    {
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
               if (i == 0 || j == 0) {
                   dp[i][j] = 0;
               } 
            }
        }
        
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(0 + dp[i][j - 1], 0 + dp[i - 1][j]);
            }
        }

        return dp[n][m];
    }
        
    int longestCommonSubsequence(string s1, string s2) 
    {
        memset(dp, -1, sizeof(dp));        
        return maxLen(s1, s2, s1.length(), s2.length());
    }
};