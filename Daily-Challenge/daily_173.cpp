/* Daily Question: 1219. Path with Maximum Gold
 * by Tyler Edwards | May 13th, 2024 (final project / studying grind)
 * Code Credit: votrubac
 * In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.
 * Return the maximum amount of gold you can collect under the conditions:
 * - Every time you are located in a cell you will collect all the gold in that cell.
 * - From your position, you can walk one step to the left, right, up, or down.
 * - You can't visit the same cell more than once.
 * - Never visit a cell with 0 gold.
 * You can start and stop collecting gold from any position in the grid that has some gold. */

class Solution {
public:
    int dfs(vector<vector<int>>& g, int i, int j) {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || g[i][j] <= 0)  return 0;
        g[i][j] = -g[i][j];
        auto res = max({ dfs(g, i + 1, j), dfs(g, i, j + 1), dfs(g, i - 1, j), dfs(g, i, j - 1) });
        g[i][j] = -g[i][j];
        return g[i][j] + res;
    }
    int getMaximumGold(vector<vector<int>>& grid, int res = 0) {
    for (auto i = 0; i < grid.size(); ++i)
        for (auto j = 0; j < grid[i].size(); ++j)
        res = max(res, dfs(grid, i, j));
    return res;
    }
};