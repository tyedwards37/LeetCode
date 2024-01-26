/* Daily Question: 576. Out of Boundary Paths
 * by Tyler Edwards | January 25th, 2024 
 * Code Credit: applefanboi
 * There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. 
 * You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). 
 * You can apply at most maxMove moves to the ball.
 * Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. 
 * Since the answer can be very large, return it modulo 109 + 7. */

class Solution {
public:
    int mod = pow(10,9) + 7;
    int helperFunction(int row, int col, int maxMoves, int x, int y,  int moves, vector<vector<vector<int>>> & dp){
        if(x < 0 || y < 0 || x >= row || y >= col){
            return 1;
        }
        if(moves == maxMoves){
            return 0;
        }
        if(dp[moves][x][y] != -1){
            return dp[moves][x][y] % mod;
        }
        int tempVal = 0;
        tempVal = (tempVal + helperFunction(row, col, maxMoves, x, y - 1, moves + 1, dp)) % mod;
        tempVal = (tempVal + helperFunction(row, col, maxMoves, x - 1, y, moves + 1, dp)) % mod;
        tempVal = (tempVal + helperFunction(row, col, maxMoves, x + 1, y, moves + 1, dp)) % mod;
        tempVal = (tempVal + helperFunction(row, col, maxMoves, x, y + 1, moves + 1, dp)) % mod;
        dp[moves][x][y] = tempVal;
        return dp[moves][x][y] % mod;
    }
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));
        dp[N][m][n] = helperFunction(m, n, N, i, j, 0, dp);
        return dp[N][m][n];
    }
    
};