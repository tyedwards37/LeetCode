/* Daily Question: 931. Minimum Falling Path Sum
 * by Tyler Edwards | January 18th, 2024 
 * Code Credit: votrubac
 * Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
 * A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. 
 * Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1). */

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        for (auto i = 1; i < A.size(); ++i)
            for (auto j = 0; j < A.size(); ++j)
                A[i][j] += min({ A[i-1][j], A[i-1][max(0,j-1)], A[i-1][min((int)A.size()-1,j+1)] });
        return *min_element(begin(A[A.size() - 1]), end(A[A.size() - 1]));
    }
};