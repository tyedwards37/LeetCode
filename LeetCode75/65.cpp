/* LeetCode Day 59: 62. Unique Paths (Medium) 65/75 
 * Tyler Edwards | January 1st, 2024 (Happy New Year!)
 * Code Credit: jianchao-li
 * There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
 * The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
 * Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner. */

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<int> cur(n, 1);

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                cur[j] += cur[j - 1];
            }
        }

        return cur[n - 1];
    }
};