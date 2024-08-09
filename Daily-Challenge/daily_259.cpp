/* Daily Question: 840. Magic Squares In Grid
 * by Tyler Edwards | August 8th, 2024 
 * Code Credit: anwendeng
 * A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
 * Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?
 * Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15. */

class Solution {
public:
    static bool isMagic(int i, int j, vector<vector<int>>& grid){
    //    if (grid[i][j] != 5) return 0;

        bitset<10> once; // bitset of size 10 to track digits 1-9
        int rowSum[3] = {0}, colSum[3] = {0};

        for(int a=i-1; a <= i+1; a++) {
            for(int b=j-1; b <=j+1; b++) {
                int x= grid[a][b];
                if (x<1 || x>9) return 0; // invalid number for a magic square
                rowSum[a-i+1] += x;
                colSum[b-j+1] += x;
                once.flip(x);
            }
        }
        // numbers 1-9 are present exactly once
        if (once.count() != 9) return 0;

        // all rows and columns sum to 15
        if (!all_of(rowSum, rowSum+3, [](int sum){ return sum == 15; })) return 0;
        if (!all_of(colSum, colSum+3, [](int sum){ return sum == 15; })) return 0;

        // Check if diagonals sum to 15
        return (grid[i-1][j-1]+grid[i+1][j+1]==10 && grid[i+1][j-1]+grid[i-1][j+1]== 10);
    }

    static int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int r = grid.size(), c = grid[0].size();
        if (r < 3 || c < 3) return 0;

        int cnt = 0;
        for(int i = 1; i < r-1; i++) {
            for(int j = 1; j < c-1; j++) {
                if (grid[i][j]==5) 
                    cnt+=isMagic(i, j, grid);
            }
        }
        return cnt;
    }
};





auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();