/* Daily Question: 1727. Largest Submatrix With Rearrangements
 * by Tyler Edwards | November 25th, 2023 
 * You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
 * Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally. */

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        int answer = 0;
        vector<int> height(n, 0);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    height[j] = 0;
                }

                else 
                {
                    height[j]++; 
                }
            }

            vector<int> ordered = height;
            sort(ordered.begin(), ordered.end());

            for (int j = 0; j < n; j++)
            {
                answer = max(answer, ordered[j] * (n - j));
            }
        }

        return answer;
    }
};
