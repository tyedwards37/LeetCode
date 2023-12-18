/* LeetCode Day 48: 399. Evaluate Division (Medium) 52/75 
 * Tyler Edwards | December 17th, 2023 
 * Code Credit: saiteja_balla0413
 * You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). 
 * You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.
 * In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. 
 * Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.
 * Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists. */

 class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        queue<pair<int,int>> q;
        q.push({e[0],e[1]});
		
        int moves = 1;
        int rows = maze.size();
        int cols = maze[0].size();
        
        vector<vector<int>> offsets = {{0,1},{1,0},{0,-1},{-1,0}};
		
        maze[e[0]][e[1]] = '+';
        while (!q.empty())
        {
            int l = q.size();
			
            for(int k = 0; k < l; k++)
            {
                auto [i,j] = q.front();
                q.pop();
                

                for (int l = 0; l < 4; l++)
                {
                    int x = i + offsets[l][0];
                    int y = j + offsets[l][1];

                    if(x < 0 || y < 0 || x >= rows || y >= cols || maze[x][y] == '+')
                    {
                        continue;
                    }

                    if(x == 0 || y == 0 || x == rows - 1 || y == cols - 1)
                    {
                        return moves;
                    }

                    maze[x][y] = '+';
                    q.push({x,y});
                }
            }
            moves++;
            
        }
        return -1;
    }
};
