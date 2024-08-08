/* Daily Question: 885. Spiral Matrix III
 * by Tyler Edwards | August 7th, 2024 
 * Code Credit: lee215
 * You start at the cell (rStart, cStart) of an rows x cols grid facing east. 
 * The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.
 * You will walk in a clockwise spiral shape to visit every position in this grid. 
 * Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). 
 * Eventually, we reach all rows * cols spaces of the grid.
 * Return an array of coordinates representing the positions of the grid in the order you visited them. */

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r, int c) {
        vector<vector<int>> res = {{r, c}};
        int dx = 0, dy = 1, tmp;
        for (int n = 0; res.size() < R * C; n++) {
            for (int i = 0; i < n / 2 + 1; i++) {
                r += dx, c += dy;
                if (0 <= r && r < R && 0 <= c && c < C)
                    res.push_back({r, c});
            }
            tmp = dx, dx = dy, dy = -tmp;
        }
        return res;
    }
};