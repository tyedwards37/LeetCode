/* Daily Question: 2257. Count Unguarded Cells in the Grid
 * by Tyler Edwards | November 20th, 2024  
 * Code Credit: Venkata Sai Tanish Jonnadula
 * You are given two integers m and n representing a 0-indexed m x n grid. 
 * You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.
 * A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. 
 * A cell is guarded if there is at least one guard that can see it.
 * Return the number of unoccupied cells that are not guarded. */

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        // m is no. of rows, n is no. of columns, g is guards vector and w is walls vector
        vector<vector<int>> v(m, vector<int> (n,0));
        int k = w.size();
        for(int i=0;i<k;i++){
            int x = w[i][0], y = w[i][1];
            v[x][y] = -2;
        }
        k = g.size();
        for(int i=0;i<k;i++){
            int x = g[i][0], y = g[i][1];
            v[x][y] = 2;
        }
        for(int j=0;j<k;j++){
            int x = g[j][0], y = g[j][1];
            for(int i=x-1;i>=0;i--){ // up
                if(v[i][y]==-2 || v[i][y]==2) break;
                v[i][y] = 1;
            }
            for(int i=x+1;i<m;i++){ // down
                if(v[i][y]==-2 || v[i][y]==2) break;
                v[i][y] = 1;
            }
            for(int i=y-1;i>=0;i--){ // left
                if(v[x][i]==-2 || v[x][i]==2) break;
                v[x][i] = 1;
            }
            for(int i=y+1;i<n;i++){ // right
                if(v[x][i]==-2 || v[x][i]==2) break;
                v[x][i] = 1;
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!v[i][j]) ans++;
            }
        }
        return ans;
    }
};