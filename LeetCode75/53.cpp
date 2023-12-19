/* LeetCode Day 49: 994. Rotting Oranges (Medium) 53/75 
 * Tyler Edwards | December 18th, 2023 (Christmas! Just a week away!)
 * Code Credit: dd139
 * You are given an m x n grid where each cell can have one of three values:
 * - 0 representing an empty cell,
 * - 1 representing a fresh orange, or
 * - 2 representing a rotten orange.
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
 * Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1. */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        vector<int> dir = {-1,0,1,0,-1}; 
        
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0; 
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i,j});
                if (grid[i][j] == 1)
                    fresh++;
            }
        int ans = -1; 
        while (!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                pair<int,int> p = q.front();
                q.pop();
                for(int i = 0; i < 4; i++)
                {
                    int r = p.first + dir[i];
                    int c = p.second + dir[i + 1];
                    if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
                    {
                        grid[r][c] = 2;
                        q.push({r,c});
                        fresh--;
                    }
                    
                }
            }
            ans++;
        }
        if (fresh > 0) return -1; 
        if (ans == -1) return 0; 
        return ans;
        
    }
};