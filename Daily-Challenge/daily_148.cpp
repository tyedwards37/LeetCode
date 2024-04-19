/* Daily Question: 200. Number of Islands
 * by Tyler Edwards | April 18th, 2024 
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
 * You may assume all four edges of the grid are all surrounded by water. */

 class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); // intialize a variable to the size of the rows of the grid
        int n = m ? grid[0].size() : 0; // intialize a vraiable that is either the number of cols or 0
        int islands = 0; // intialize a variable torecord the number of islands
        for (int i = 0; i < m; i++) { // loop for the number of rows
            for (int j = 0; j < n; j++) { // loop for the number of cols
                if (grid[i][j] == '1') { // check if that spot on the grid is a 1
                    islands++; // increment the number of islands
                    eraseIslands(grid, i, j); // run the function to erase that island given the grid, the current row, and current col index
                }
            }
        }
        return islands; // return the final number of islands
    }
private:
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size(); // intializes a variable m for the number of rows and n for the number of cols
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') { // check if the current row index is less than 0, equal to the number of rows or if the current col index is less than 0, equal to the number of cols or if the value at teh current index is equal to 0
            return; // returns to stop the recusrive loop
        }
        grid[i][j] = '0'; // sets grid value at current index equal to 0
        eraseIslands(grid, i - 1, j); // recurisvely checks to the left of the current grid index to check for a 1
        eraseIslands(grid, i + 1, j); // recurisvely checks to the right of the current grid index to check for a 1
        eraseIslands(grid, i, j - 1); // recurisvely checks below the current grid index to check for a 1
        eraseIslands(grid, i, j + 1); // recurisvely checks above the current grid index to check for a 1
    }
};