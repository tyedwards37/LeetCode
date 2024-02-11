/* Daily Question: 1463. Cherry Pickup II
 * by Tyler Edwards | February 10th, 2024 
 * Code Credit: coding_fred
 * You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.
 * You have two robots that can collect cherries for you:
 * - Robot #1 is located at the top-left corner (0, 0), and
 * - Robot #2 is located at the top-right corner (0, cols - 1).
 * Return the maximum number of cherries collection using both robots by following the rules below:
 * - From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
 * - When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
 * - When both robots stay in the same cell, only one takes the cherries.
 * - Both robots cannot move outside of the grid at any moment.
 * - Both robots should reach the bottom row in grid. */

class Solution {
public:
    int dp[70][70][70] = {};
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        return dfs(grid, m, n, 0, 0, n - 1);
    }
    int dfs(vector<vector<int>>& grid, int m, int n, int r, int c1, int c2) {
        if (r == m) return 0; // Reach to bottom row
        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];
        int ans = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nc1 = c1 + i, nc2 = c2 + j;
                if (nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n) {
                    ans = max(ans, dfs(grid, m, n, r + 1, nc1, nc2));
                }
            }
        }
        int cherries = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        return dp[r][c1][c2] = ans + cherries;
    }
};