/* Daily Question: 1765. Map of Highest Peak
 * by Tyler Edwards | Janaury 20th, 2025 
 * Code Credit: Vlad
 * You are given an integer matrix isWater of size m x n that represents a map of land and water cells.
 * - If isWater[i][j] == 0, cell (i, j) is a land cell.
 * - If isWater[i][j] == 1, cell (i, j) is a water cell.
 * You must assign each cell a height in a way that follows these rules:
 * - The height of each cell must be non-negative.
 * - If the cell is a water cell, its height must be 0.
 * - Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
 * Find an assignment of heights such that the maximum height in the matrix is maximized. 
 * Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them. */

class Solution {
public:
    int dirs[5] = {0, 1, 0, -1, 0};
    vector<vector<int>> highestPeak(vector<vector<int>>& w) {
        vector<pair<int, int>> p;
        int h = 1, si = w.size(), sj = w[0].size();
        for (auto i = 0; i < si; ++i)
            for (auto j = 0; j < sj; ++j) {
                w[i][j] = w[i][j] == 1 ? 0 : -1;
                if (w[i][j] == 0)
                    p.push_back({i, j});
            }
        while (!p.empty()) {
            vector<pair<int, int>> p1;
            for (auto [i, j] : p) {
                for (int d = 0; d < 4; ++d) {
                    int x = i + dirs[d], y = j + dirs[d + 1];
                    if (x >= 0 && y >= 0 && x < si && y < sj && w[x][y] == -1) {
                        w[x][y] = h;
                        p1.push_back({x, y});
                    }
                }
            }
            swap(p, p1);
            ++h;
        }
        return w;
    }
};