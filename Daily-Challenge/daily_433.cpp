/* Daily Question: 827. Making A Large Island
 * by Tyler Edwards | Janaury 30th, 2025 
 * Code Credit: Mai Thanh Hiep
 * You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
 * Return the size of the largest island in grid after applying this operation.
 * An island is a 4-directionally connected group of 1s. */

class Solution {
public:
    const int DIR[5] = {0, 1, 0, -1, 0};
    int m, n;
    unordered_map<int, int> componentSize;
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int ans = 0, nextColor = 2;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] != 1) continue; // Only paint when it's an island cell
                paint(grid, r, c, nextColor++);
                ans = max(ans, componentSize[nextColor - 1]);
            }
        }
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] != 0) continue; // Skip non-empty cell
                unordered_set<int> neighborColors;
                for (int i = 0; i < 4; ++i) {
                    int nr = r + DIR[i], nc = c + DIR[i+1];
                    if (nr < 0 || nr == m || nc < 0 || nc == n || grid[nr][nc] == 0) continue;
                    neighborColors.insert(grid[nr][nc]);
                }
                int sizeFormed = 1;
                for (int color : neighborColors) sizeFormed += componentSize[color];
                ans = max(ans, sizeFormed);
            }
        }
        return ans;
    }
    void paint(vector<vector<int>>& grid, int r, int c, int color) {
        if (r < 0 || r == m || c < 0 || c == n || grid[r][c] != 1) return;
        grid[r][c] = color;
        componentSize[color] += 1;
        for (int i = 0; i < 4; ++i) paint(grid, r + DIR[i], c + DIR[i+1], color);
    }
};