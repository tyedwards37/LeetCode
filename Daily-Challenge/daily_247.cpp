/* Daily Question: 2045. Second Minimum Time to Reach Destination
 * by Tyler Edwards | July 27th, 2024 
 * Code Credit: RadecX1
 * A city is represented as a bi-directional connected graph with n vertices where each vertex is labeled from 1 to n (inclusive). 
 * The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. 
 * Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. The time taken to traverse any edge is time minutes.
 * Each vertex has a traffic signal which changes its color from green to red and vice versa every change minutes. All signals change at the same time. 
 * You can enter a vertex at any time, but can leave a vertex only when the signal is green. You cannot wait at a vertex if the signal is green.
 * The second minimum value is defined as the smallest value strictly larger than the minimum value.
 * - For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.
 * Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1 to vertex n.
 * Notes:
 * - You can go through any vertex any number of times, including 1 and n.
 * - You can assume that when the journey starts, all signals have just turned green. */

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // if the shortest path from 1 to n is of length L
        // find whether there is a path of length L+1
        // there is always a path of length L+2
        
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int u = e[0]-1, v = e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // bfs from goal
        vector<int> d(n, 1e9);
        d[n-1] = 0;
        queue<int> q;
        q.push(n-1);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto nei : adj[cur]) {
                if (d[nei] == 1e9) {
                    d[nei] = d[cur] + 1;
                    q.push(nei);
                }
            }
        }
        
        // check the existence of a path with length = d[0]+1
        int len = d[0] + 2;
        q.push(0);
        bool done = false;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto nei : adj[cur]) {
                if (d[nei] == d[cur]) {
                    len--;
                    done = true;
                    break;
                } else if (d[nei] == d[cur] - 1) {
                    q.push(nei);
                }
            }
            if (done) break;
        }
        
        // calculate the time needed
        // light : green in [0, c),  [2c, 3c), ... 
        //          red  in [c, 2c), [3c, 4c), ...
        int currTime = 0;
        //cout << len << '\n';
        for (int i = 0; i < len; i++) {
			if ((currTime / change) % 2 == 1)  // have to wait until the signal turns into green
                currTime = ((currTime / change) + 1) * change;    
            currTime += time;
        }
        return currTime;
    }
};