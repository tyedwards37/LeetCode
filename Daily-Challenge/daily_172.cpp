/* Daily Question: 861. Score After Flipping Matrix
 * by Tyler Edwards | May 12th, 2024 (final project / studying grind)
 * Code Credit: lee215
 * You are given an m x n binary matrix grid.
 * A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
 * Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
 * Return the highest possible score after making any number of moves (including zero moves). */

class Solution {
public:
    int matrixScore(vector<vector<int>> A) {
        int M = A.size(); // intializes a variable to the num of rows 
        int N = A[0].size(); // initializes a variable to the num of cols
        int res = (1 << (N - 1)) * M; // initializes a variable to the value of  (1 << (N - 1)) * M
        for (int j = 1; j < N; j++) { // loop for the num of cols
            int cur = 0; // intialize a variable to record teh current value
            for (int i = 0; i < M; i++) { // loop for the num of rows
                cur += A[i][j] == A[i][0]; // add to the current value a 1 if the value at i, j is equal to the one at i, 0
            }
            res += max(cur, M - cur) * (1 << (N - j - 1)); // set the result to the max between the current value and the number of rows - the current multiplied by (1 << (N - j - 1))
        }
        return res; // return the result integer
    }
};