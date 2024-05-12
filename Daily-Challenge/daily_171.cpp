/* Daily Question: 2373. Largest Local Values in a Matrix
 * by Tyler Edwards | May 11th, 2024 (final project / studying grind)
 * Code Credit: votrubac
 * You are given an n x n integer matrix grid.
 * Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:
 * - maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.
 * In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.
 * Return the generated matrix. */

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& g) {
        int n = g.size(); // intialize a variable to teh size of the given array
        vector<vector<int>> res(n - 2, vector<int>(n - 2)); // creates a new answer array that is the correct size
        for (int i = 0; i < n - 2; ++i) // loop over the size of a row/col - 2
            for (int j = 0; j < n - 2; ++j) // loop over the size of a row/col - 2
                for (int ii = i; ii < i + 3; ++ii) // sets the start to whatever the i index is and goes 3 past i's value
                    for (int jj = j; jj < j + 3; ++jj) // sets the start to whatever the j index is and goes 3 past j's value
                        res[i][j] = max(res[i][j], g[ii][jj]); // set the current index of the answer array to the max between the current index's value and the grid's value 
        return res;
    }   
};