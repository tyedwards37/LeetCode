/* Daily Question: 2684. Maximum Number of Moves in a Grid
 * by Tyler Edwards | October 28th, 2024 
 * Code Credit: tojuna
 * You are given a 0-indexed m x n matrix grid consisting of positive integers.
 * You can start at any cell in the first column of the matrix, and traverse the grid in the following way:
 * - From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
 * Return the maximum number of moves that you can perform. */

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {1, 1}, {-1, 1}};
        vector<vector<int>> cache(m, vector<int>(n, -1));

        function<int(int, int)> dp = [&](int i, int j) {
            if (cache[i][j] != -1) return cache[i][j];
            int ans = 0;
            for (auto [x, y] : dirs) {
                int ni = i + x, nj = j + y;
                if (ni >= 0 && ni < m && nj < n && grid[i][j] < grid[ni][nj])
                    ans = max(ans, 1 + dp(ni, nj));
            }
            return cache[i][j] = ans;
        };
        int res = 0;
        for (int i = 0; i < m; i++)
            res = max(res, dp(i, 0));
        return res;
    }
};