/* Daily Question: 1277. Count Square Submatrices with All Ones
 * by Tyler Edwards | October 26th, 2024 
 * Code Credit: lee215
 * Given a m * n matrix of ones and zeros, return how many square submatrices have all ones. */

class Solution {
public:
    int countSquares(vector<vector<int>>& A) {
        int res = 0;
        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < A[0].size(); res += A[i][j++])
                if (A[i][j] && i && j)
                    A[i][j] += min({A[i - 1][j - 1], A[i - 1][j], A[i][j - 1]});
        return res;
    }
};