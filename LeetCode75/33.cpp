/* LeetCode Day 31: Equal Row and Column Pairs(2352) (Medium) 33/75 
 * by Tyler Edwards | November 24th, 2023 
 * Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.
 * A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array). */

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        int n = grid.size(), answer = 0;
        map<vector<int>, int> map;

        for (int i = 0; i < n; i++)
        {
            map[grid[i]]++;
        }

        for (int i = 0; i < grid[0].size(); i++)
        {
            vector<int> vector;

            for (int j = 0; j < n; j++)
            {
                vector.push_back(grid[j][i]);
            }

            answer += map[vector];
        }

        return answer;
    }
};
