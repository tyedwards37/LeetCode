/* Daily Question: 1368. Minimum Cost to Make at Least One Valid Path in a Grid
 * by Tyler Edwards | Janaury 17th, 2025 
 * Code Credit: lee
 * Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:
 * - 1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
 * - 2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
 * - 3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
 * - 4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
 * Notice that there could be some signs on the cells of the grid that point outside the grid.
 * You will initially start at the upper left cell (0, 0). 
 * A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. 
 * The valid path does not have to be the shortest.
 * You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.
 * Return the minimum cost to make the grid have at least one valid path. */

class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), cost = 0;
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        dfs(grid, 0, 0, dp, cost, q);
        while (!q.empty()) {
            cost++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                int r = p.first, c = p.second;
                q.pop();
                for (int j = 0; j < 4; j++)
                    dfs(grid, r + dir[j][0], c + dir[j][1], dp, cost, q);
            }
        }
        return dp[m - 1][n - 1];
    }
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& dp, int cost, queue<pair<int, int>>& q) {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || dp[r][c] != INT_MAX)return;
        dp[r][c] = cost;
        q.push(make_pair(r, c));
        int nextDir = grid[r][c] - 1;
        dfs(grid, r + dir[nextDir][0], c + dir[nextDir][1], dp, cost, q);
    }
};