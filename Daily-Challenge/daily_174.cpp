/* Daily Question: 2812. Find the Safest Path in a Grid
 * by Tyler Edwards | May 14th, 2024 (final project / studying grind) (hardest, but final final tomorrow)
 * Code Credit: Codensity_30
 * You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:
 * - A cell containing a thief if grid[r][c] = 1
 * - An empty cell if grid[r][c] = 0
 * You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.
 * The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.
 * Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).
 * An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.
 * The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val. */

class Solution {
public:

    void buildDis(queue<pair<int,int>>& q, int n, vector<vector<int>>& dis, vector<vector<bool>>& vis){
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int lvl = 0;

        while (!q.empty()) {
            int siz = q.size();
            while(siz--){
                auto [x,y] = q.front();
                q.pop();
                dis[x][y] = lvl;
                for (int i=0; i<4; i++) {
                    int nx = x+dir[i].first, ny = y+dir[i].second;
                    if (nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny]) {
                        q.push({nx,ny});
                        vis[nx][ny] = true;
                    }
                }
            }
            lvl++;
        }
    }

    int findSf(vector<vector<int>>& dis, int n){
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<bool>> vis (n,vector<bool>(n));
        pq.push({dis[0][0],{0,0}});
        vis[0][0] = true;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 1e9;
        while(!pq.empty()){
            auto [d,cord] = pq.top();
            pq.pop();
            int x = cord.first, y = cord.second;
            ans = min(ans,dis[x][y]);
            if(x==n-1 && y==n-1) return ans;
            for(int i=0; i<4; i++){
                int nx = x+dir[i].first, ny = y+dir[i].second;
                if(nx>=0 && nx<n && ny>=0 && ny<n &&!vis[nx][ny]){
                    vis[nx][ny] = true;
                    pq.push({dis[nx][ny],{nx,ny}});
                }
            }
        }
        return ans;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pair<int, int>> q;
        vector<vector<bool>> vis (n,vector<bool>(n));

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    vis[r][c] = true;
                    q.push({r, c});
                }
            }
        }
        
        vector<vector<int>> dis (n,vector<int>(n));

        buildDis(q,n,dis,vis);
        int ans = findSf(dis,n);

        return ans;
    }
};