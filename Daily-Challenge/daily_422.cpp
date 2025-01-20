/* Daily Question: 2661. First Completely Painted Row or Column
 * by Tyler Edwards | Janaury 19th, 2025 
 * Code Credit: Sumeet Sharma
 * You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].
 * Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
 * Return the smallest index i at which either a row or a column will be completely painted in mat. */

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        unordered_map<int, pair<int, int>> positionMap;
        vector<int> rowCount(rows, cols), colCount(cols, rows);

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                positionMap[mat[r][c]] = {r, c};
            }
        }

        for (int idx = 0; idx < arr.size(); ++idx) {
            int val = arr[idx];
            auto [row, col] = positionMap[val];

            if (--rowCount[row] == 0 || --colCount[col] == 0) {
                return idx;
            }
        }

        return -1;
    }
};