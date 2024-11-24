/* Daily Question: 1975. Maximum Matrix Sum
 * by Tyler Edwards | November 23rd, 2024  
 * Code Credit: Dung Dao
 * You are given an n x n integer matrix. You can do the following operation any number of times:
 * - Choose any two adjacent elements of matrix and multiply each of them by -1.
 * Two elements are considered adjacent if and only if they share a border.
 * Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above. */

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        long long neg_cnt = 0, ans = 0, size = a.size(), minn = 1000000;
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j) {
                ans += abs(a[i][j]);
                if (a[i][j] < 0)
                    neg_cnt++;
                minn = minn < abs(a[i][j])? minn: abs(a[i][j]);
            }
        if (neg_cnt % 2 == 0)
            return ans;
        else 
            return ans - 2*minn;
    }
};