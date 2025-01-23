/* Daily Question: 1267. Count Servers that Communicate
 * by Tyler Edwards | Janaury 22nd, 2025 
 * Code Credit: Dhairya Dhondiyal
 * You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. 
 * Two servers are said to communicate if they are on the same row or on the same column.
 * Return the number of servers that communicate with any other server. */

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rows(grid.size(),0),columns(grid[0].size(),0);	
        for(int i=0;i<grid.size();i++)						
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j])
                    rows[i]++,columns[j]++;
        int result=0;
        for(int i=0;i<grid.size();i++)			
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]&&(columns[j]>1||rows[i]>1))	
                    result++;
        return result;
    }
};